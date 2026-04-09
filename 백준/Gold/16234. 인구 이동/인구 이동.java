import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	static int[] dx = {-1,1,0,0}, dy = {0,0,-1,1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());

		int[][] arr = new int[N][N];
		for(int i = 0; i < N; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}

		int ans = 0;
		
		while(true){
			int[][] area = new int[N][N];
			
			int num = 1; //구역 번호
			for(int i = 0; i < N; i++){
				for(int j = 0; j < N; j++){
					if(area[i][j] != 0) continue;
					Deque<Pair> dq = new ArrayDeque<>();
					area[i][j] = num++;
					dq.addLast(new Pair(i,j));

					while(!dq.isEmpty()){
						Pair cur = dq.removeFirst();
						for(int k = 0; k < 4; k++){
							int nx = cur.x + dx[k];
							int ny = cur.y + dy[k];
							if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
							if(area[nx][ny] != 0) continue;
							
							int diff = Math.abs(arr[cur.x][cur.y] - arr[nx][ny]);
							if(diff >= L && diff <= R){
								area[nx][ny] = area[cur.x][cur.y];
								dq.addLast(new Pair(nx,ny));
							}
						}
					}
				}
			}

			//모든 지역이 다른 번호
			if(num == N * N + 1) break;

			//인구 이동
			int[] tmpSum = new int[num+1];
			int[] tmpCnt = new int[num+1];
			for(int i = 0; i < N; i++){
					for(int j = 0; j < N; j++){
						tmpSum[area[i][j]] += arr[i][j];
						tmpCnt[area[i][j]]++;
					}
			}
			
			for(int i = 0; i < N; i++){
					for(int j = 0; j < N; j++){
						arr[i][j] = tmpSum[area[i][j]] / tmpCnt[area[i][j]];
					}
			}
			ans++;
		}
		System.out.println(ans);
	}
}