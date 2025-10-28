#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> res;
int n;

void dfs(long val, int last){
	res.push_back(val);
	for(int i = 0; i < last; i++){
		dfs(val * 10 + i, i);
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < 10; i++) dfs(i,i);
	sort(res.begin(), res.end());
	if(res.size() <= n) cout << -1;
	else cout << res[n];
	return 0;
}