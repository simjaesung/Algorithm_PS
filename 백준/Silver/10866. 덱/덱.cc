#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	int n, val;
	cin >> n;

	deque<int>D;
	string cmd;
	while (n--)
	{
		ios::sync_with_stdio(0);
		cin.tie(0);

		cin >> cmd;

		if (cmd == "push_front") {
			cin >> val;
			D.push_front(val);
		}
		else if (cmd == "push_back") {
			cin >> val;
			D.push_back(val);
		}
		else if (cmd == "pop_front") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << D.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << D.empty() << '\n';
		}
		else if (cmd == "front") {
			if (D.empty()) cout << -1 << '\n';
			else cout << D.front() << '\n';
		}
		else if (cmd == "back") {
			if (D.empty()) cout << -1 << '\n';
			else cout << D.back() << '\n';
		}
	}

}