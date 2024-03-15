#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, val;
long ans;
int a[1005], b[1005], T;
vector<int>A; vector<int>B;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];

	//부분합 전부 구하기
	for (int i = 0; i < n; i++) {
		val = 0;
		for (int j = i; j < n; j++) {
			val += a[j];
			A.push_back(val);
		}
	}

	for (int i = 0; i < m; i++) {
		val = 0;
		for (int j = i; j < m; j++) {
			val += b[j];
			B.push_back(val);
		}
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//합쳐서 T가 되는 B의 부분합 구하기 
	for (auto x : A) {
		int idx1 = lower_bound(B.begin(), B.end(), T - x) - B.begin();
		int idx2 = upper_bound(B.begin(), B.end(), T - x) - B.begin();
		ans += idx2 - idx1;
	}
	cout << ans;
	return 0;
}