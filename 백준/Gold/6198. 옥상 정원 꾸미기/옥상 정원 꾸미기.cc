#include<iostream>
#include<stack>
#include<vector>
using namespace std;
long long build[80001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	stack<pair<long long, long long>> s;

	long long n, cnt; cin >> n;
	long long ans = 0;

	for (long long i = 0; i < n; i++) cin >> build[i]; //역순으로 stack push
	for (long long i = n - 1; i >= 0; i--) {
		cnt = 0; //보이는 빌딩 개수
		//빌딩이 보이지 않을 경우 및 앞에 빌딩이 없을 경우
		if (s.empty() || s.top().first >= build[i]) s.push(make_pair(build[i], cnt));
		//보이는 빌딩의 개수를 세아린 후 pop, 이떄 pop되는 빌딩에서 빌딩이 보였을 경우는 그 개수를 총 보이는 개수에 반영
		else if (build[i] > s.top().first) {
			while (!s.empty() && build[i] > s.top().first) {
				cnt++; cnt += s.top().second;
				ans += s.top().second;
				s.pop();
			}
			s.push(make_pair(build[i], cnt));
		}
	}
	while (!s.empty()) {
		ans += s.top().second;
		s.pop();
	}

	cout << ans;
	return 0;
}