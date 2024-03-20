#include<iostream>
#include<deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	while (n--) {
		deque<string>dq;
		string f, s;
		cin >> f; 
		int k; cin >> k;
		cin >> s;

		string val="";
		for (int i = 1; i < s.length(); i++) {
			if (s[i] != ',' && s[i] != ']') val += s[i];
			else {
				if(val != "") dq.push_back(val);
				val = "";
			}
		}	

		int reverse = 0, error = 0;
		for (int j = 0; j < f.length(); j++) {
			if (f[j] == 'R') {
				if (reverse == 1) reverse = 0;
				else reverse = 1;
			}
			else {
				if (dq.empty()) {
					cout << "error" << '\n';
					error = 1;
					break;
				}
				else {
					if (reverse) dq.pop_back();
					else dq.pop_front();
				}		
			}
		}

		if (error) continue;
		else {
			cout << '[';
			if (reverse) {
				while (!dq.empty()) {
					if (dq.size() == 1)cout << dq.back();
					else cout << dq.back() << ',';
					
					dq.pop_back();
				}
			}
			else {
				while (!dq.empty()) {
					if (dq.size() == 1)cout << dq.front();
					else cout << dq.front() << ',';
					dq.pop_front();
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}