#include<iostream>
#include<vector>
using namespace std;


int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int arr[105][105];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	while (n--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<int>v;
		v.push_back(d);

		//드래곤 커브 경로 
		for (int i = 0; i < g; i++) {
			int tmp = v.size() - 1;
			for (int k = tmp; k >= 0; k--) {
				v.push_back((v[k] + 1) % 4);
			}
		}

		//위 경로대로 그림 그리기
		arr[y][x] = 1;

		//문제에 주어진 x,y는 반대임을 주의
		for (int i = 0; i < v.size(); i++) {
			x += dx[v[i]]; y += dy[v[i]];
			arr[y][x] = 1;
		}
		
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) ans++;
		}
	}

	cout << ans;

	return 0;
}