#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0);

	int p = 0, ans = 0;
	for (int i = 0; i < 10; i++) {
		int in, out;
		cin >> out >> in;
		p += in; p -= out;
		ans = max(ans, p);
	}
	cout << ans;
	
	return 0;
}