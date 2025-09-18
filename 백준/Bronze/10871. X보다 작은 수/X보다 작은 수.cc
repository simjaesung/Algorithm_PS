#include <iostream>
using namespace std;
int main() {
	int N, X, val;
	cin >> N >> X;

	for(int i = 0; i < N; i++){
		cin >> val;
		if(val < X) cout << val << " ";
	}
	return 0;
}