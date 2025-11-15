import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	static int[] dx = {1,0,-1,0};
	static int[] dy = {0,1,0,-1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] arr = new int[n][n];
		int[][] cost = new int[n][n];
		
		for(int i = 0; i < n; i++){
			String s = br.readLine();
			char[] sToChar = s.toCharArray();
			for(int j = 0; j < n; j++) arr[i][j] = sToChar[j] - '0';
			Arrays.fill(cost[i],n*n);
		}

		cost[0][0] = 0; 

		Deque<Pair> dq = new ArrayDeque<>();
		dq.addLast(new Pair(0,0));
		
		
		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();
			if(cur.x == n-1 && cur.y == n-1) continue;
			
			for(int i = 0; i < 4; i++){
				int nx = dx[i] + cur.x;
				int ny = dy[i] + cur.y;
				if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;

				int nxtCost = cost[cur.x][cur.y];
				if(arr[nx][ny] == 0) nxtCost++;
				if(cost[nx][ny] <= nxtCost) continue;
				cost[nx][ny] = nxtCost;

				if(arr[nx][ny] == 0) dq.addLast(new Pair(nx,ny));
				else dq.addFirst(new Pair(nx,ny));
			}
		}

		int ans = cost[n-1][n-1];
		if(ans == n * n) ans = 0;
		System.out.println(ans);
	}
}