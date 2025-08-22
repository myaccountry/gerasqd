#include <iostream>
#include <gerastack.hpp>
#include <gerastr.h>

int main() 
{
	stack<str> stk;
	for (int i = 1; i < 6; i++)
		stk.push(i);
	for (int i = 0; i < 5; i++)
		cout << stk.pop() << ' ';
	cout << endl;

	return 0;
}
