#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class TrafficLight;

class State
{
protected:
	TrafficLight *trLight;

public:
	virtual ~State() {};
	void setTrLight(TrafficLight *trLight) {
		this->trLight = trLight;
	}

	virtual void GreenHandle() = 0;
	virtual void YellowHandle() = 0;
	virtual void RedHandle() = 0;

};


class TrafficLight
{
	State *state;
public:
	TrafficLight(State *state) : state(nullptr){
		this->TransitionTo(state);
	};

	void TransitionTo(State *state) {
		if (this->state !=nullptr)
			delete this->state;
		this->state = state;
		this->state->setTrLight(this);
	}

	void GreenClourRequest() {
		state->GreenHandle();
	}
	void YellowClourRequest() {
		state->YellowHandle();
	}
	void RedClourRequest() {
		state->RedHandle();
	}

	~TrafficLight() {
		delete state;
	};
	
};

class YellowState;
class RedState;


class GreenState : public State
{
public:
	
	void GreenHandle() override {
		cout << "Traffic light's state - GREEN\n";
	}
	void YellowHandle() override;

	void RedHandle() override;
	
};

class YellowState : public State
{
public:
	void GreenHandle() override {
		cout << "YELLOW state of traffic light want to change GREEN state!\n";
		this->trLight->TransitionTo(new GreenState);
	}
	void YellowHandle() override {
		cout << "Traffic light's state - YELLOW\n";
	}
	void RedHandle() override;
};

class RedState : public State
{
public:
	void GreenHandle() override {
		cout << "RED state of traffic light want to change GREEN state!\n";
		trLight->TransitionTo(new GreenState);
	}
	void YellowHandle() override {
		cout << "RED state of traffic light want to change YELLOW state!\n";
		this->trLight->TransitionTo(new YellowState);
	}
	void RedHandle() override {
		cout << "Traffic light's state - RED\n";
	};
};


void GreenState::YellowHandle() {
	cout << "GREEN state of traffic light want to change YELLOW state!\n";
	this->trLight->TransitionTo(new YellowState);
}

void GreenState::RedHandle(){
	cout << "GREEN state of traffic light want to change RED state!\n";
	this->trLight->TransitionTo(new RedState);
}


void YellowState::RedHandle() {
	cout << "YELLOW state of traffic light want to change RED state!\n";
	this->trLight->TransitionTo(new RedState);
}



int main() {

	TrafficLight *trLight = new TrafficLight(new RedState);
	trLight->YellowClourRequest();
	trLight->YellowClourRequest();
	trLight->GreenClourRequest();
	trLight->GreenClourRequest();

	delete trLight;

	system("pause");
	return 0;
}