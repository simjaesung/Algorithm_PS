#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int x; cin >> x;
	int s = 64;

	vector<int>ans;

	while ( x > 0) {
		if (s <= x) {
			ans.push_back(s);
			x -= s;
		}
		s /= 2;
	}

	cout << ans.size();

	
	return 0;
}