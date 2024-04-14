#include <iostream>
#include <algorithm> 
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;

	vector<string>list(s.length());

	for (int i = 0; i < s.length(); i++) {
		list[i] = s.substr(i);
	}

	sort(list.begin(), list.end());

	for (auto x : list)	cout << x << '\n';
	
	return 0;
}