#include <iostream>
#include <string>


using namespace std;

template <typename T>

class NodeList
{
	private:
	template <typename T>
	class Container {
		

	public:
		Container *nextContainer;
		T data;
		Container(T data = T(), Container *nextContainer = nullptr)
		{
			this->data = data;
			this->nextContainer = nextContainer;
		};

	};

	Container <T> *head;
	int size;



	

public:
	NodeList()
	{
		this->head = nullptr;
		this->size = 0;
	};
	int GetSize() {
		return this->size;
	}
	void push(T data) {
		if (head == nullptr) {
			head = new Container<T>(data);
			
		}
		else
		{
			Container<T> *current = this->head;
			while (current->nextContainer != nullptr)
			{
				current = current->nextContainer;
			}
			current->nextContainer = new Container<T>(data);

		}
		this->size++;
		
	}
	/*~NodeList();*/
};





int main() {
	NodeList <int> testList;
	cout <<testList.GetSize();
	testList.push(4);
	cout << testList.GetSize();


	system("pause");
	return 0;
}