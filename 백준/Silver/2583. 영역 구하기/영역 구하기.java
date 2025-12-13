import java.io.*;
import java.util.*;

class Main {
	static int n,m,k;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,1,-1};
	static boolean[][] visited;
	static int[][] arr;

	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}

	public static int bfs(int x, int y){
		int cnt = 1;
		visited[x][y] = true;
		Deque<Pair> dq = new ArrayDeque<>();
		dq.addLast(new Pair(x,y));
		
		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();
			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if(visited[nx][ny] || arr[nx][ny] != 0) continue;
				cnt++;
				visited[nx][ny] = true;			
				dq.addLast(new Pair(nx,ny));
			}
		}
		return cnt;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		arr = new int[m][n];
		visited = new boolean[m][n];

		while(k-- > 0){
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			for(int i = y1; i < y2; i++){
				for(int j = x1; j < x2; j++){
					arr[i][j] = 1;
				}
			}
		}

		List<Integer> ans = new ArrayList<>();
		
		for(int i = 0; i < m; i++){
				for(int j = 0; j < n; j++){
					if(arr[i][j] == 0 && !visited[i][j]){
						ans.add(bfs(i,j));
					}
				}
		}

		System.out.println(ans.size());
		Collections.sort(ans);
		for(int k : ans) System.out.print(k + " ");
	}
}