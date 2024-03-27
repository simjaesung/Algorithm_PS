#include <iostream>
#include <string>

using namespace std;

typedef struct Stack {
	int data[10000];
	int size = 0;

	void push(int val)
	{
		data[size++] = val;
	}

	int pop()
	{
		if (size > 0) {
			return data[--size];
		}
		else {
			return -1;
		}	
	}

	int empty()
	{
		if (size == 0) return 1;
		else return 0;
	}

	int top()
	{
		if (empty()) return -1;
		else return data[size - 1];
	}

}Stack;



int main()
{
	Stack s;
	
	int n;
	cin >> n;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "top") {
			cout << s.top() << '\n';
		}
		else if (cmd == "size") {
			cout << s.size << '\n';
		}
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}
		else if (cmd == "pop") {
			cout << s.pop() << '\n';
		}
	}
	
	return 0;
}