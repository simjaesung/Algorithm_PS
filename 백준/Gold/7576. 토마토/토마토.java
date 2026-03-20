import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());

		Deque<Pair> dq = new ArrayDeque<>();

		int[][] arr = new int[N][M];
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 1) dq.addLast(new Pair(i,j));
			}
		}

		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();
			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if(arr[nx][ny] != 0) continue;
				arr[nx][ny] = arr[cur.x][cur.y] + 1;
				dq.addLast(new Pair(nx,ny));
			}
		}

		int ans = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++) {
				if(arr[i][j] == 0){
					System.out.println(-1);
					return;
				}
				ans = Math.max(ans, arr[i][j]);
			}
		}

		System.out.println(ans-1);
	}
}