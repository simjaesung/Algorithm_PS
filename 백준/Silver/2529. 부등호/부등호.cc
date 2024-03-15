#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool check[10];
char s[10];
int n;
vector<string>v;

void go(int select, string ans)
{
	if (select == n + 1) {
		v.push_back(ans);
		//cout << ans << '\n';
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (check[i]) continue;
		string tmp = ans;
		int len = ans.length();

		if (len > 0) {
			if (s[len] == '>') {
				if (ans[len - 1] - '0' < i) continue;
			}
			else {
				if (ans[len - 1] - '0' > i) continue;
			}
		}

		check[i] = true; ans += to_string(i);
		go(select + 1, ans);
		ans = tmp;
		check[i] = false;
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	go(0, "");
	cout << v.back() << '\n';
	cout << v.front() << '\n';
	
	return 0;
}