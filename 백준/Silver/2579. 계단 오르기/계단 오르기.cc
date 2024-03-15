#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int S[301], D[301];
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> S[i];

	D[0] = 0;
	D[1] = S[1]; 
	D[2] = S[1] + S[2];

	for (int j = 3; j <= n; j++) D[j] = max(D[j - 2] + S[j], D[j - 3] + S[j - 1] + S[j]);

	cout << D[n];
	
	return 0;
}