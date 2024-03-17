#include<iostream>
#include<vector>
using namespace std;

int arr[105][105];
int c[105][105];
int n, k, l;

//동남서북
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool inrange(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int ax, ay;
		cin >> ax >> ay;
		arr[ax][ay] = 2;
	}

	vector<pair<int, char>>d;

	cin >> l;
	for (int i = 0; i < l; i++) {
		int s; char m;
		cin >> s;
		cin >> m;
		d.push_back(make_pair(s, m));
	}
	
	int cnt = 0; int len = 1;
	int x = 1;	int y = 1; int dir = 0; int didx = 0;

	vector<pair<int, int>>root;

	while (1) {
		c[x][y]++;
		root.push_back(make_pair(x, y));

		x += dx[dir]; y += dy[dir];

		if (!inrange(x, y)) {
			cout << cnt + 1;
			return 0;
		}

		if (arr[x][y] == 2) {
			arr[x][y] = 0;
			len++;
		}

		if (c[x][y] !=0) {
			for (int i = root.size() - 1; i >= root.size() - len; i--) {
				int px = root[i].first; int py = root[i].second;
				if (px == x && py == y) {
					cout << cnt + 1;
					return 0;
				}
			}
		}

		cnt++;

		//방향을 바꿀 경우
		if (didx < l && cnt == d[didx].first) {
			if (d[didx].second == 'L') dir = (dir - 1 + 4) % 4;
			else dir = (dir + 1) % 4;
			didx++;
		}
	}
	
	return 0;
}