#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string s;
vector<string>v;
int check[55], arr[3];

void go(int select,int start) 
{
	if (select == 3) {
		string tmp;
		
		for (int i = arr[0]; i >= 0; i--) tmp += s[i];
		for (int i = arr[1]; i > arr[0]; i--) tmp += s[i];
		for (int i = s.length()-1; i > arr[1]; i--) tmp += s[i];

		v.push_back(tmp);
		return;
	}

	for (int i = start; i < s.length(); i++) {
		if (check[i]) continue;
		check[i] = 1; arr[select] = i;
		go(select + 1,i + 1);;
		check[i] = 0;
	}

}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;

	go(0,0);
	sort(v.begin(), v.end());
	cout << v[0];
	return 0;
}