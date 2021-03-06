// cpa_lab_7_2_6_(1)-B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

class Caretaker
{
private:
	int value, minvalue, maxvalue;
public:
	Caretaker(int val, int minval, int maxval)
	{
		value = val;
		minvalue = minval;
		maxvalue = maxval;
	}
	void Add(int a)
	{
		int temp = value + a;
		if (temp > maxvalue || temp < minvalue)
			throw string("Value could exceed limit");
		else value = temp;
	}
	void Substruct(int a)
	{
		Add(-a);
	}
	int GetValue()
	{
		return value;
	}
};

int main()
{
	int a, mina, maxa;
	int add, sub;
	cout << "enter first object" << endl;
	cin >> a >> mina >> maxa;

	Caretaker obj1 = Caretaker(a, mina, maxa);

	cout << "enter second object" << endl;
	cin >> a >> mina >> maxa;

	Caretaker obj2 = Caretaker(a, mina, maxa);




	try
	{
		cout << "enter value to add" << endl;
		cin >> add;
		obj1.Add(add);
		cout << "enter value to substruct" << endl;
		cin >> sub;
		obj1.Substruct(sub);
	}
	catch (string e)
	{
		cout << e << endl;
	}

	try
	{
		cout << "enter value to add" << endl;
		cin >> add;
		obj2.Add(add);
		cout << "enter value to substruct" << endl;
		cin >> sub;
		obj2.Substruct(sub);
	}
	catch (string e)
	{
		cout << e << endl;
	}

	cout << obj1.GetValue() << endl;
	cout << obj2.GetValue() << endl;

	return 0;
}
