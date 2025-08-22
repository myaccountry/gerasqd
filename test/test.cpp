#include <iostream>
#include <gerasqd.hpp>
#include <gerastr.hpp>
using namespace std;

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
	cout << endl << endl;

	queue<str> que;
	for (int i = 1; i < 6; i++)
		que.enqueue(i);
	queue<str> cque = que;
	for (int i = 0; i < 5; i++)
		cout << que.dequeue() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << cque.dequeue() << ' ';
	cout << endl << endl;

	stack<str> stk;
	for (int i = 1; i < 6; i++)
		stk.push(i);
	for (int i = 0; i < 5; i++)
		cout << stk.pop() << ' ';
	cout << endl;

	return 0;
}
