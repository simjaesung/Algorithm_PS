#include<iostream>
#include<string>

using namespace std;

int main()
{
	int alp[26] = { 0 };
	fill(alp, alp + 26, -1);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (alp[int(s[i]) - 97] == -1) {
			alp[int(s[i]) - 97] = i;
		}	
	}

	for (auto x : alp) 
		cout << x << ' ';
	
	return 0;
}