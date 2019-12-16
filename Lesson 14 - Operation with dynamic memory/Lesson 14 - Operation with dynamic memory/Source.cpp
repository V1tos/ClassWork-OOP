#include <iostream>
#include <string>


using namespace std;
//
//template <typename T>
//
//class NodeList
//{
//	private:
//		
//	template <typename T>
//	class Container {
//		
//
//	public:
//		Container *nextContainer;
//		T data;
//		Container(T data = T(), Container *nextContainer = nullptr)
//		{
//			this->data = data;
//			this->nextContainer = nextContainer;
//		};
//
//	};
//
//	Container <T> *head;
//	int size;
//
//
//
//	
//
//public:
//	NodeList()
//	{
//		this->head = nullptr;
//		this->size = 0;
//	};
//	int GetSize() {
//		return this->size;
//	}
//	void push(T data) {
//		if (head == nullptr) {
//			head = new Container<T>(data);
//			
//		}
//		else
//		{
//			Container<T> *current = this->head;
//			while (current->nextContainer != nullptr)
//			{
//				current = current->nextContainer;
//			}
//			current->nextContainer = new Container<T>(data);
//
//		}
//		this->size++;
//		
//	}
//	/*~NodeList();*/
//};




template <typename T>
class NodeList1
{

private:

	template <typename T>
	class Container1 {


	public:
		Container1 *NextNode;
		T data;

		Container1(T(data) = T(), Container1 *NextNode = nullptr) {
			this->data = data;
			this->NextNode = NextNode;
		};

		

	};

	
	Container1<T> *head1;

	int size1;
public:
	NodeList1() {
		this->head1 = head1;
		this->size1 = 0;
	};
	void PushData(T data) {

		if (this->head1 == nullptr) {
			this->head1 = new Container1<T>(data);
		}
		else
		{
			Container1<T> *current = this->head1;
			while (current->NextNode!=nullptr)
			{
				current = current->NextNode;

			};
			current->NextNode = new Container1<T>(data);
			
		};
		this->size1++;

	};

	int GetSize() {
		return this->size1;
	};

	void DeleteFirst() {

		Container1<T> *tmp = this->head1;
		this->head1 = this->head1->NextNode;
		delete tmp;
		this->size1--;
	};
	void ShowData() {
		
		Container1<T> *current = this->head1;
		int counter = 0;
		while (current !=nullptr)
		{
			
			cout <<"Data " << counter << " - " << current->data  << endl;
			counter++;
			current = current->NextNode;
		};

	};



};



int main() {
	/*NodeList <int> testList;
	cout <<testList.GetSize();
	testList.push(4);
	cout << testList.GetSize();*/

	NodeList1 <int> test;
	cout << test.GetSize() << endl;
	test.PushData(3);
	cout << test.GetSize() << endl;
	test.DeleteFirst();
	cout << test.GetSize() << endl;
	test.PushData(3);
	test.PushData(6);
	test.PushData(2);
	test.PushData(7);
	test.PushData(8);
	test.PushData(3);
	cout << test.GetSize() << endl;
	test.ShowData();

	system("pause");
	return 0;
}