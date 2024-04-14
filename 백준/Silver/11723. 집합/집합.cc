#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int s = 0;
	int m; cin >> m;

	while (m--) {
		string cmd;	cin >> cmd;
		int val;

		if (cmd == "add") {
			cin >> val; val--;
			s = (s | (1 << val));
		}
		else if (cmd == "remove") {
			cin >> val; val--;
			s = (s & ~(1 << val));
		}
		else if (cmd == "check") {
			cin >> val; val--;
			if (s & (1 << val))cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (cmd == "toggle") {
			cin >> val; val--;
			s = s ^ (1 << val);
		}
		else if (cmd == "all") {
			s = (1 << 20) - 1;
		}
		else if (cmd == "empty") {
			s = 0;
		}
	}
	
	
	
	return 0;
}