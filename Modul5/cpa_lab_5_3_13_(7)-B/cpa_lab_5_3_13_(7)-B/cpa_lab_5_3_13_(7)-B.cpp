// cpa_lab_5_3_13_(1)-B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Node
{
public:
	Node(int val);
	int value;
	//~Node();
	Node* next;
};
Node::Node(int val) : value(val), next(nullptr)
{
	//	cout << "+Node" << endl;
}
//Node::~Node()
//{
//	cout << "-Node" << endl;
//}

class List
{
public:
	List();
	List(List const &source);
	void push_back(int value);
	//~List();
	void push_front(int value);
	bool pop_front(int value);
	bool pop_back(int value);
	int size();
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
private:
	Node* head;
	Node* tail;
};
List::List(List const &source):head(nullptr),tail(nullptr){
	Node *tc=source.head;
	while (tc!=nullptr)
	{
		this->push_back(tc->value);
		tc = tc->next;
	}
	
}
int List::size() {
	Node *t = head;
	int i = 0;
	while (t != nullptr) {
		t = t->next;
		++i;
	}
	return i;
}
List::List() : head(nullptr)
{

}
//List::~List() {
//	Node *t = head, *next;
//	while (t != nullptr)
//	{
//		next = t->next;
//		delete t;
//		t = next;
//	}
//}
int List::at(int index)
{
	Node *t = head;
	int i = 0;
	while (i < index && t != nullptr) {
		t = t->next;
		++i;
	}
	return t->value;
}
void List::insert_at(int index, int value) {
	Node *t = head, *pre = nullptr;
	int i = 0;
	while (i < index && t != nullptr) {
		pre = t;
		t = t->next;
		++i;
	}
	Node *n = new Node(value);
	if (pre == nullptr) {
		n->next = head;
		head = n;
	}
	else {
		n->next = pre->next;
		pre->next = n;
	}

}
void List::remove_at(int index) {
	Node *t = head, *pre = nullptr;
	int i = 0;
	while (i < index && t != nullptr) {
		pre = t;
		t = t->next;
		++i;
	}
	if (pre == nullptr) {
		head = head->next;
	}
	else {
		pre->next = t->next;
	}
	delete t;
}
void List::push_front(int value)
{
	Node* new_head = new Node(value);
	new_head->next = head;
	head = new_head;
	if (tail == nullptr)
		tail = new_head;
}
void List::push_back(int value)
{
	// implement me!
	Node *new_tail = new Node(value);
	new_tail->next = nullptr;
	if (tail != nullptr)
		tail->next = new_tail;
	tail = new_tail;
	if (head == nullptr)
		head = new_tail;
}

bool List::pop_front(int value)
{
	Node *t = head, *prev = nullptr;

	while (t != nullptr) {
		if (t->value == value) {

			if (prev == nullptr) {
				prev = head;
				head = head->next;
				if (head->next == nullptr)
					tail = head;
				delete prev;
			}
			else
			{
				if (t->next == nullptr)
					tail = prev;
				prev->next = t->next;
				delete t;
			}

			return true;
		}
		else
		{
			prev = t;
			t = t->next;
		}
	}
	return false;
}
bool List::pop_back(int value) {
	Node *t = head, *pre = nullptr, *temp = nullptr;
	while (t->next != nullptr)
	{
		if (t->value == value)
		{
			temp = pre;
		}
		pre = t;
		t = t->next;
	}
	if (tail->value == value) {
		temp = pre;
		tail = pre;
	}

	if (temp != nullptr) {
		t = temp->next;
		temp->next = t->next;

		delete t;
		return true;
	}
	return false;

}
void printList(List list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == " << list.at(i) << endl;
	}
}
int main()
{
	List list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	cout << "list1" << endl;
	printList(list1);
	cout << endl;

	List list2(list1);
	cout << "list2" << endl;
	printList(list2);
	cout << endl;

	list1.insert_at(1, 6);
	list2.remove_at(2);

	cout << "list1" << endl;
	printList(list1);

	cout << "list2" << endl;
	printList(list2);
	cout << endl;
	return 0;

}


