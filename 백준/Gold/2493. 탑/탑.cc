#include<iostream>
#include<stack>

using namespace std;
int t[500001];
int arr[500001] = { 0 };

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(nullptr); cout.tie(nullptr);

	int n,tall,cnt; cin >> n;

	stack<int>s;
	stack<int>ans;

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		s.push(i);
	} //입력 순대로 push

	tall = t[s.top()]; //현재 가장 큰 레이저 탑의 키
	ans.push(s.top());
	s.pop(); cnt = 1;

	while (!s.empty()) {
		if (t[s.top()] > tall) {
			while (!ans.empty() && t[s.top()] > t[ans.top()]) {
				arr[ans.top()] = s.top();
				ans.pop();
			}
		}
		tall = t[s.top()];
		ans.push(s.top());
		s.pop();
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';

	return 0;
}