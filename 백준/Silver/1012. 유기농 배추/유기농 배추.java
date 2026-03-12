import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int[][] arr = new int[55][55];
		boolean[][] visited = new boolean[55][55];
		int[] dx = {-1,1,0,0};
		int[] dy = {0,0,1,-1};
		StringTokenizer st;
		
		while(t-- > 0){
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 55; i++){
				Arrays.fill(arr[i],0);
				Arrays.fill(visited[i],false);
			}
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			
			while(k-- > 0){
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				arr[x][y] = 1;
			}

			int ans = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(arr[i][j] == 1 && !visited[i][j]){
						ans++;
						Deque<Pair> dq = new ArrayDeque<>();
						dq.addLast(new Pair(i,j));
						visited[i][j] = true;
						while(!dq.isEmpty()){
							Pair cur = dq.removeFirst();
							for(int l = 0; l < 4; l++){
								int nx = cur.x + dx[l];
								int ny = cur.y + dy[l];
								if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
								if(arr[nx][ny] != 1 || visited[nx][ny]) continue;
								visited[nx][ny] = true;
								dq.addLast(new Pair(nx,ny));
							}
						}
					}
				}
			}
			System.out.println(ans);
		}
	}
}