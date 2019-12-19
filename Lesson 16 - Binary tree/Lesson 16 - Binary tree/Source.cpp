#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

Node *CreateNewNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *Insert(Node *root, int data) {
	if (root == NULL) {
		root = CreateNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}

	return root;
}



bool Search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}

void Delete(Node *root, int data) {
	/*if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return 0;
	}
	else if (data <= root->data) {
		return Delete(root->left, data);
	}
	else {
		return Delete(root->right, data);
	}*/

	Node *tmp = root;
	Node *Left = tmp->left;
	Node *Right = tmp->right;

	
	while (tmp->data!=0)
	{
		
			cout << tmp->data;
			if (tmp->data > data) {
				tmp = Left;
			}
			else if(tmp->data < data)
			{
				tmp=Right;
			}
		
			
			Left = tmp->left;
			Right = tmp->right;
	}

}

int main() {
	int number;

	Node *root = NULL;
	root = Insert(root, 50);
	root = Insert(root, 20);
	root = Insert(root, 23);
	root = Insert(root, 60);

	Delete(root, 25);

	//cout << "Enter number for search: " << endl;
	//cin >> number;
	//if (Search(root, number) == true) {
	//	cout << "Number: " << number << " Found" << endl;
	//}
	//else {
	//	cout << number << " Not found" << endl;
	//}



	system("pause");
	return 0;
}