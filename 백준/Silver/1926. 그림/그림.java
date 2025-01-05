import java.io.*;
import java.util.*;

class Main {
	public static int[][] arr;
	public static boolean[][] visited;
	public static int n, m, cnt, maxArea;
	public static int[] dx = {-1,1,0,0};
	public static int[] dy = {0,0,-1,1};
	
	public static boolean inRange(int x, int y){
		return x >= 0 && x < n && y >= 0 && y < m;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		visited = new boolean[n][m];
		
		for(int i = 0; i<n; i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++){
				arr[i][j] = Integer.parseInt(st2.nextToken());
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] == 1 && !visited[i][j]){
					cnt++;
					visited[i][j] = true;
					bfs(i,j);
				}
			}
		}
		
		System.out.println(cnt);
		System.out.println(maxArea);
	}
	
	public static void bfs(int x, int y){
		Queue<Pair>queue = new ArrayDeque<>();
		int area = 1;
		queue.offer(new Pair(x,y));
		
		while(!queue.isEmpty()){
			Pair first = queue.poll();
			int cx = first.x;
			int cy = first.y;
			
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(!inRange(nx,ny)) continue;
				if(arr[nx][ny] == 0) continue;
				if(visited[nx][ny]) continue;
				visited[nx][ny] = true;
				area++;
				queue.offer(new Pair(nx,ny));
			}
		}
		
		maxArea = Math.max(maxArea,area);
	}
	
	static class Pair{
		int x;
		int y;
		
		Pair(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
}