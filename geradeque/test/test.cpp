#include <iostream>
#include <geradeque.hpp>
#include <gerastr.h>

int main() 
{
	deque<int> deq;
	for (int i = 1; i <= 10; i++) {
		if (i % 2 == 0)
			deq.push_back(i);
		else
			deq.push_front(i);
	}

	for (int i = 0; i < 10; i++) {
		cout << deq.pop_front() << ' ';
	}
	cout << endl;

	return 0;
}
