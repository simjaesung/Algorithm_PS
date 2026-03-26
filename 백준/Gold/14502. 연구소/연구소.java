import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	static int n,m;
	static int[][] arr;
	static int[][] arr_copy;
	static int[][] visited;
	static ArrayList<Pair> area;
	static ArrayList<Pair> virus;
	static int ans = 0;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int[] wall = new int[3];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		arr = new int[n][m]; //원본 연구소
		arr_copy = new int[n][m]; // 카피본 연구소
		visited = new int[n][m];
		area = new ArrayList<>(); //연구소 빈곳
		virus = new ArrayList<>(); //초기 바이러스 위치

		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == 2) virus.add(new Pair(i,j));
				if(arr[i][j] == 0) {
					area.add(new Pair(i,j));
				}
			}
		}
		select(0,0);
		System.out.println(ans);
	}

	public static void select(int idx, int k){
		if(k == 3){
			init();
			for(int i = 0; i < 3; i++) {
				Pair p = area.get(wall[i]);
				arr_copy[p.x][p.y] = 1;
			}
			ans = Math.max(ans, bfs());
			return;
		}

		for(int i = idx; i < area.size(); i++){
			wall[k] = i;
			select(i + 1, k + 1);
		}
	}

	public static void init(){
		for(int i = 0; i < n; i++){
			Arrays.fill(visited[i], 0);
			for(int j = 0; j < m; j++) {
				arr_copy[i][j] = arr[i][j];
			}
		}
	}

	public static int bfs(){
		Deque<Pair> dq = new ArrayDeque<>();
		for(Pair v : virus) dq.addLast(v);

		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();

			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if(arr_copy[nx][ny] != 0 || visited[nx][ny] == 1) continue;
				visited[nx][ny] = 1;
				arr_copy[nx][ny] = 2;
				dq.addLast(new Pair(nx,ny));
			}
		}
		
		int safe = 0;
		for(int[] tmp : arr_copy){
			for(int k : tmp) if(k == 0) safe++;
		}
		return safe;
	}
}