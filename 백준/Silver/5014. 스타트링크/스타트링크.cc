#include<iostream>
#include<queue>
using namespace std;
int arr[1000005], c[1000005];

int main()
{
	//f : 건물 높이 s: 강호위치 g: 스타트링크 위치
	// u만큼 위로 d만큼 아래
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	queue<int>q;
	q.push(s); c[s] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int next;
			if (i == 0) next = now + u;
			else next = now - d;

			if (next < 1 || next > f) continue;
			if (c[next] == 0) {
				c[next] = c[now] + 1;
				q.push(next);
			}
		}
	}
	if (c[g] == 0) cout << "use the stairs";
	else cout << c[g] - 1;
	

	return 0;
}