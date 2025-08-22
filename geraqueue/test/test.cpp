#include <iostream>
#include <geraqueue.hpp>
#include <gerastr.h>

int main() 
{
	queue<str> que;
	for (int i = 1; i < 6; i++)
		que.enqueue(i);
	queue<str> cque = que;
	for (int i = 0; i < 5; i++)
		cout << que.dequeue() << ' ';
	cout << endl;
	for (int i = 0; i < 5; i++)
		cout << cque.dequeue() << ' ';
	cout << endl;

	return 0;
}
