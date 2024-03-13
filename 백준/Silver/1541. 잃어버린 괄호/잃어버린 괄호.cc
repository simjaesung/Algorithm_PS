#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;

	int ans = 0;
	bool minus = false; //minus 토글
	string tmp; //숫자 문자열 저장
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '-' && s[i] != '+') tmp += s[i];
		else {
			int val = stoi(tmp);
			tmp.clear();

			//앞에 -가 등장했으면,
			if (minus) ans -= val;
			else ans += val;

			if (s[i] == '-') minus = true;
		}
	}

	if (minus) ans -= stoi(tmp);
	else ans += stoi(tmp);

	cout << ans;

	return 0;
}