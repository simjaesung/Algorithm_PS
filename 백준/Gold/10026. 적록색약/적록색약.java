import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	static int n;
	static char[][] arr;
	static boolean[][] visited;
	static int normal, sameRG;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,1,-1};

	public static void bfs(int x, int y, boolean SameRG){
		visited[x][y] = true;
		Deque<Pair> dq = new ArrayDeque<>();
		dq.addLast(new Pair(x,y));
		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();
			char nowC = arr[cur.x][cur.y];
			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if(visited[nx][ny]) continue;
				if(SameRG){
					if(nowC == 'R' || nowC == 'G'){
						if(arr[nx][ny] == 'B') continue;
					}else{
						if(nowC != arr[nx][ny]) continue;
					}
				}
				else {
					if(nowC != arr[nx][ny]) continue;
				}
				visited[nx][ny] = true;
				dq.addLast(new Pair(nx,ny));
			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new char[n][n];
		visited = new boolean[n][n];
		
		for(int i = 0; i < n; i++){
			String input = br.readLine();
			char[] charArr = input.toCharArray();
			for(int j = 0; j < n; j++) arr[i][j] = charArr[j];
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j]) {
					bfs(i,j,false);
					normal++;
				}
			}
		}

		for(int i = 0; i < n; i++) Arrays.fill(visited[i],false);

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!visited[i][j]) {
					bfs(i,j,true);
					sameRG++;
				}
			}
		}

		System.out.println(normal + " " + sameRG);
	}
}