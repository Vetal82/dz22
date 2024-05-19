// ConsoleApplication11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Time.h"
using namespace std;
int main()
{
	Time_ a;
	Time_ b(12,00,00);
	a.showTime();
	b.showTime();
	cout << "Equal?" << (a == b ? "yes" : "no") << endl;
	cout << "Not Equal?" << (a != b ? "yes" : "no") << endl;
	cout << "More?" << (a > b ? "yes" : "no") << endl;
	cout << "More or Equal?" << (a >= b ? "yes" : "no") << endl;
	cout << "Less?" << (a < b ? "yes" : "no") << endl;
	cout << "Less or Equal?" << (a >= b ? "yes" : "no") << endl;
	cout << "----------------------------------------" << endl;
	a.showTime();
	//cout << "+365 days = ";
	/*a += 365;
	a.showDate();
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	b.showDate();
	cout << "-15 days =";
	b -= 15;
	b.showDate();*/
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	a.showTime();
	cout << "+8 minutes = ";
	a += 8.0f;
	a.showTime();
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	b.showTime();
	cout << "-6 minutes =";
	b -= 6.0f;
	b.showTime();
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	a.showTime();
	cout << "+8 hour = ";
	a += 8L;
	a.showTime();
	cout << "++++++++++++++++++++++++++++++++++++" << endl;
	b.showTime();
	cout << "-6 hour =";
	b -= 6L;
	b.showTime();
	/*cout << "++++++++++++++++++++++++++++++++++++" << endl;
	Date d = a + 7;
	a.showDate();
	d.showDate();*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
