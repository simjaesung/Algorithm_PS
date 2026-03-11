import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y; int z;
		public Pair(int x, int y, int z){
			this.x = x; this.y = y; this.z = z;
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

		PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.z - b.z);
		visited[0][0] = 0;
		pq.offer(new Pair(0,0,0));
		
		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(cur.x == n-1 && cur.y == n-1) break;

			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				
				int nxtBroken = cur.z;
				if(arr[nx][ny] == 0) nxtBroken++;
				if(visited[nx][ny] <= nxtBroken) continue;
				visited[nx][ny] = nxtBroken;
				pq.offer(new Pair(nx,ny,nxtBroken));
			}
		}

		if(visited[n-1][n-1] == n * n) System.out.print(0);
		else System.out.print(visited[n-1][n-1]);
	}
}