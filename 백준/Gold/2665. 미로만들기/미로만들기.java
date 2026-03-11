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
	static int[][] arr, visited;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		visited = new int[n][n];
		
		for(int i = 0; i < n; i++){
			String input = br.readLine();
			char[] tmp = input.toCharArray();
			for(int j = 0; j < n; j++) arr[i][j] = tmp[j] - '0';
			Arrays.fill(visited[i], n * n);
		}

		Deque<Pair>dq = new ArrayDeque<>();
		visited[0][0] = 0;
		dq.addLast(new Pair(0,0));
		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();

			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				int nxtBroken = visited[cur.x][cur.y];
				if(arr[nx][ny] == 0) nxtBroken++;
				if(visited[nx][ny] <= nxtBroken) continue;
				visited[nx][ny] = nxtBroken;
				dq.addLast(new Pair(nx,ny));
			}
		}

		if(visited[n-1][n-1] == n * n) System.out.print(0);
		else System.out.print(visited[n-1][n-1]);
	}
}