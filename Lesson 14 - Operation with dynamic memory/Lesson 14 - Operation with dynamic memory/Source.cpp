#include <iostream>
#include <string>




//Побудувати клас для роботи з однозв’язним списком.Елемент списку містить наступну інформацію про автобус :
//
//номер автобуса;
//прізвище та ініціали водія;
//номер маршруту.
//Програма повинна забезпечувати :
//початкове формування двох списків :
//з даними про автобуси, які знаходяться в автопарку;
//з даними про автобуси, які знаходяться на маршрутах.
//При виїзді кождого автобуса з парку вводиться номер автобуса, і програма видаляє дані про цей автобус з списку автобусів, які знаходяться в автопарку, та записує ці дані в список автобусів, які знаходяться на маршруті.
//аналогічна операція виконується для списків, якщо якийсь автобус повертається в автопарк;
//по запиту видіються відомості про автобуси, які знаходяться в автопарку або на маршруті.


using namespace std;

class Bus
{
	short number;

public:
	Bus() {};
	Bus(short number) {
		this->number = number;
	};

	short GetNumber() {
		return this->number;
	}
	void ShowNumber() {
		cout << this->number << endl;
	}
	/*~Bus();*/
};



template <typename T>
class BusStation
{
	private:
		
	template <typename T>
	class Container {
		

	public:
		Container *nextBus;
		T data;
	
	
		Container(T(data) =T(), Container *nextBus = nullptr)
		{
			this->data = data;
			this->nextBus = nextBus;
		};

		
		

	};

	

	Container <T> *head;
	int size;



	

public:
	BusStation()
	{
		this->head = nullptr;
		this->size = 0;
	};
	int GetSize() {
		return this->size;
	}

	void Push(T data) {
		if (head == nullptr) {
			head = new Container<T>(data);
			
		}
		else
		{
			Container<T> *current = this->head;
			
			while (current->nextBus != nullptr)
			{
				current = current->nextBus;
			}
			current->nextBus = new Container<T>(data);

		}
		this->size++;
		
	}
	void ShowData() {
		Container <T> *current = head;

		while (current != nullptr) {

			cout << current->data.GetNumber();
			current = current->nextBus;
		}


	}
	void DeleteFirst() {

		Container <T> *temp = this->head;
		this->head = this->head->nextBus;
		delete temp;
		size--;

	}

	~BusStation() {

		DeleteFirst();
	};
};






int main() {
	BusStation <Bus> testList;
	Bus tmp(4);

	testList.Push(tmp);
	/*cout << testList.GetSize();*/
	testList.ShowData();


	system("pause");
	return 0;
}