#include <iostream>
#include <sstream>
#include "stackl.h"

int main()
{
	using namespace std;

	StackL a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	StackL b(a);
	cout << "a = " << a << endl;
	cout << "b(a) = " << b << endl;
	a.push(6);
	cout << "a.push(6) = " << a << endl;
	a.pop();
	cout << "a.pop() = " << a << endl;
	cout << "a.top() = " << a.top() << endl;
	if (a.isEmpty())
	{
		cout << "a isEmpty" << endl;
	}
	else
	{
		cout << "a !isEmpty" << endl;
	}

	return 0;
}