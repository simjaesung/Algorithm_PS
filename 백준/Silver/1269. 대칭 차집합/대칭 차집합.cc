#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, int>A; map<int, int>B;
vector<int>AA; vector<int>BB;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int val; cin >> val;
		AA.push_back(val);
		A[val] = 1;
	}

	for (int i = 0; i < b; i++) {
		int val; cin >> val;
		BB.push_back(val);
		B[val] = 1;
	}

	int ans = 0;

	for (int i = 0; i < AA.size(); i++) if (!B[AA[i]])ans++;
	for (int i = 0; i < BB.size(); i++) if (!A[BB[i]])ans++;
	
	cout << ans;
	return 0;
}