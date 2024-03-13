#include<iostream>
#include<algorithm>
using namespace std;
string arr[55];

bool isnum(char c) {
	char num[10] = { '0', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9'};

	for (int i = 0; i < 10; i++) {
		if (num[i] == c) return true;
	}

	return false;
}

bool compare(const string& a, const string& b) {
	if (a.length() != b.length()) return a.length() < b.length();

	int suma = 0; int sumb = 0;

	for (int i = 0; i < a.length(); i++) {
		if (isnum(a[i])) suma += a[i] - '0';
	}

	for (int i = 0; i < b.length(); i++) {
		if (isnum(b[i])) sumb += b[i] - '0';
	}

	if (suma != sumb) return suma < sumb;
	
	return a < b;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		arr[i] = s;
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++) cout << arr[i] << '\n';
	return 0;
}