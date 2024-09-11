#include <iostream>
#include<queue>
#include<tuple>
#include<algorithm>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

char board[1000][1000];
int dist[1000][1000][2];
int n, m;

bool inrange(int x, int y) {
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

int bfs() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 2; k++)
                dist[i][j][k] = 0;
        }
    }
    queue<tuple<int, int, int>>q;
    q.push({ 0,0,0 });
    dist[0][0][0] = 1; dist[0][0][1] = 1;

    while (!q.empty()) {
        int cx, cy, broke;
        tie(cx, cy, broke) = q.front();
        q.pop();
        if (cx == n - 1 && cy == m - 1) return dist[cx][cy][broke];

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (inrange(nx, ny)) {
                if (board[nx][ny] == '0' && dist[nx][ny][broke] == 0) {
                    dist[nx][ny][broke] = dist[cx][cy][broke] + 1;
                    q.push({ nx,ny,broke });
                }

                if (!broke && board[nx][ny] == '1' && dist[nx][ny][1] == 0) {
                    dist[nx][ny][1] = dist[cx][cy][broke] + 1;
                    q.push({ nx,ny,1 });
                }
            }
        }
    }
    return -1;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];
    cout << bfs();
    return 0;
}