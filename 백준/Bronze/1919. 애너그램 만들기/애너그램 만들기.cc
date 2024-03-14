#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	int A[26] = { 0 }, B[26] = { 0 };

	for (auto& x : a) A[x - 'a']++;
	for (auto& s : b) B[s - 'a']++;

	int ans = 0;
	for (int i = 0; i < 26; i++) ans += abs(A[i] - B[i]);

	cout << ans;
	

	return 0;
}