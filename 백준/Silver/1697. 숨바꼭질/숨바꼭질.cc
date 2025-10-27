#include <iostream>
#include <queue>
using namespace std;

int visited[100005];
int n,k;
int main() {
	cin >> n >> k;
	queue<int> q;
	q.push(n); 
	visited[n] = 1;
	while(!q.empty()){
		int cx = q.front(); q.pop();
		if(cx == k){
			cout << visited[cx] - 1;
			break;
		}
		if(cx - 1 >= 0 && !visited[cx-1]){
			visited[cx-1] = visited[cx] + 1;
			q.push(cx-1);
		}

		if(cx + 1 <= 100000 && !visited[cx+1]){
			visited[cx+1] = visited[cx] + 1;
			q.push(cx+1);
		}

		if(cx * 2 <= 100000 && !visited[cx * 2]){
			visited[cx * 2] = visited[cx] + 1;
			q.push(cx * 2);
		}
		
	}
	return 0;
}