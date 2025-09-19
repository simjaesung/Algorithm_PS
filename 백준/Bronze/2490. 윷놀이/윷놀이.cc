#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d;

	for(int i = 0; i < 3; i++){
		int cnt = 0;
		cin >> a >> b >> c >> d;
		if(a) cnt++;
		if(b) cnt++;
		if(c) cnt++;
		if(d) cnt++;

		if(cnt == 4) cout << "E" << "\n";
		else if(cnt == 3) cout << "A" << "\n";
		else if(cnt == 2) cout << "B" << "\n";
		else if(cnt == 1) cout << "C" << "\n";
		else cout << "D" << "\n";
	}
}