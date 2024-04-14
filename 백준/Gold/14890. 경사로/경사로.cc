#include<iostream>
#include<algorithm>
using namespace std;

int n, l;
int arr[105][105], c[105][105];

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}


	int ans = 0;
	//행확인
	for (int i = 0; i < n; i++) {
		int cango = 1;
		for (int j = 1; j < n; j++) {
			//높이 차이가 2 이상인 경우
			if (abs(arr[i][j] - arr[i][j - 1]) > 1) {
				cango = 0;
				break;
			}

			//높이 차이가 같을 경우
			if (arr[i][j] == arr[i][j - 1]) continue;

			//오른쪽이 더 클 경우
			if (arr[i][j] > arr[i][j - 1]) {
				int val = l; int check = 0;
				while (val > 0) {
					//범위를 벗어난 경우
					//이미 경사로를 설치한 경우
					//높이 차이가 1이 아닌 경우
					if (!inrange(i, j - val) || c[i][j - val] == 1
						|| arr[i][j] - arr[i][j - val] != 1) {
						check = 1; break;
					}
					val--;
				}

				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i][j - val] = 1;
						val--;
					}
				}

			}
			//왼쪽이 더 클 경우
			//-1칸과 비교해야함
			else {
				int val = l; int check = 0;
				while (val > 0) {
					if (!inrange(i, j - 1 + val) || c[i][j - 1 + val] == 1 
						|| arr[i][j - 1] - arr[i][j  - 1 + val] != 1) {
						check = 1; break;
					}
					val--;

				}
				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i][j - 1 + val] = 1;
						val--;
					}
				}

			}
		}
		if (cango) ans++;
	}



	for (int i = 0; i < n; i++) fill(c[i], c[i] + n, 0);



	//열 확인
	for (int j = 0; j < n; j++) {
		int cango = 1;
		for (int i = 1; i < n; i++) {
			//높이 차이가 2 이상인 경우
			if (abs(arr[i][j] - arr[i-1][j]) > 1) {
				cango = 0;
				break;
			}

			//높이 차이가 같을 경우
			if (arr[i][j] == arr[i-1][j]) continue;

			//아래가 더 클 경우
			if (arr[i][j] > arr[i-1][j]) {
				int val = l; int check = 0;
				while (val > 0) {
					//범위를 벗어난 경우
					//이미 경사로를 설치한 경우
					//높이 차이가 1이 아닌 경우
					if (!inrange(i-val, j) || c[i - val][j] == 1 
						|| arr[i][j] - arr[i - val][j] != 1) {
						check = 1; break;
					}
					val--;
				}
				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i - val][j] = 1;
						val--;
					}
				}

			}
			//위가 더 클 경우
			//-1칸과 비교해야함
			else {
				int val = l; int check = 0;
				while (val > 0) {
					if (!inrange(i+val - 1, j) || c[i + val - 1][j] == 1
						|| arr[i - 1][j] - arr[i + val - 1][j] != 1) {
						check = 1; break;
					}
					val--;
				}
				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i + val - 1][j] = 1;
						val--;
					}
				}
			}
		}
		if (cango) ans++;
	}


	cout << ans;
	
	
	return 0;
}