#include<iostream>
using namespace std;
int cnt0, cnt1;
int main()
{
	int n; cin >> n;
	
	while (n--) {
		int vote; cin >> vote;
		if (vote == 1) cnt1++;
		else cnt0++;
	}
	if (cnt1 > cnt0) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";

	return 0;
}