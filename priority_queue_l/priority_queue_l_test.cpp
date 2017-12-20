#include <iostream>
#include <sstream>
#include "priority_queue_l.h"

int main()
{
	using namespace std;
	PriorityQueueL a;
	if (a.isEmpty())
	{
		cout << "Empty queue a" << endl;
	}
	a.push(9);
	a.push(7);
	a.push(4);
	cout << "a.push(9), a.push(7), a.push(4) = " << a << endl;
	a.push(3);
	cout << "a.push(3) = " << a << endl;
	a.push(8);
	cout << "a.push(8) = " << a << endl;
	a.push(10);
	cout << "a.push(10) = " << a << endl;
	a.pop();
	cout << "a.pop() = " << a << endl;
	return 0;
}