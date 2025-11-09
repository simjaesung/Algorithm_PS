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

		int[] dx = {-1,1,0,0};
		int[] dy = {0,0,-1,1};
		
		int[][] arr = new int[55][55];
		int[][] visited = new int[55][55];
		int m; //가로
		int n; //세로
		int k; //배추 위치 개수
		StringBuilder sb = new StringBuilder();
		while(t-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			m = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			for(int i = 0; i < m; i++){
				Arrays.fill(arr[i],0);
				Arrays.fill(visited[i],0);
			}

			while(k-- > 0){
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				arr[x][y] = 1;
			}

			int ans = 0;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					if(arr[i][j] == 1 && visited[i][j] == 0){
						ans++;
						visited[i][j] = 1;
						Deque<Pair> dq = new ArrayDeque<>();
						dq.addLast(new Pair(i,j));

						while(!dq.isEmpty()){
							Pair cur = dq.peekFirst(); dq.removeFirst();
							for(int s = 0; s < 4; s++){
								int nx = cur.x + dx[s];
								int ny = cur.y + dy[s];
								if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
								if(arr[nx][ny] != 1 || visited[nx][ny] == 1) continue;
								visited[nx][ny] = 1;
								dq.addLast(new Pair(nx,ny));
							}
						}
					}
				}
			}
			sb.append(ans + "\n");
		}
		System.out.println(sb);
	}
}