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
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[][] arr = new int[n][m];
		for(int i = 0; i < n; i++){
			String s = br.readLine();
			char[] charArr = s.toCharArray();
			for(int j = 0; j < m; j++) arr[i][j] = charArr[j] - '0';
		}

		int[] dx = {-1,1,0,0};
		int[] dy = {0,0,-1,1};
		Deque<Pair> dq = new ArrayDeque<>();
		dq.addLast(new Pair(0,0));
		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();

			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(nx == 0 && ny == 0) continue;
				if(arr[nx][ny] != 1) continue;
				arr[nx][ny] = arr[cur.x][cur.y] + 1;
				dq.addLast(new Pair(nx,ny));
			}
		}
		System.out.println(arr[n-1][m-1]);
	}
}