#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, time;
	int y = 0, m = 0;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> time;
		if(time < 30) y += 10;
		else y += (time / 30 + 1) * 10;

		if(time < 60) m += 15;
		else m += (time / 60 + 1) * 15;
	}

	if(y == m) cout << "Y M " << y;
	else if(y < m) cout << "Y " << y;
	else cout << "M " << m;

	return 0;
}