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
	static int[][] arr, arr_copy;
	static ArrayList<Pair> emptys, virus;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n][m];
		arr_copy = new int[n][m];
		emptys = new ArrayList<>();
		virus = new ArrayList<>();
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				int tmp = Integer.parseInt(st.nextToken());
				arr[i][j] = tmp;
				arr_copy[i][j] = tmp;
				if(arr[i][j] == 0) emptys.add(new Pair(i,j));
				if(arr[i][j] == 2) virus.add(new Pair(i,j));
			}
		}

		int k = emptys.size();
		for(int i = 0; i < k; i++){
			for(int j = i + 1; j < k; j++){
				for(int l = j + 1; l < k; l++){
					Pair e1 = emptys.get(i);
					Pair e2 = emptys.get(j);
					Pair e3 = emptys.get(l);
					arr[e1.x][e1.y] = 1;
					arr[e2.x][e2.y] = 1;
					arr[e3.x][e3.y] = 1;
					ans = Math.max(ans, bfs());
					init();
				}
			}
		}
		
		System.out.println(ans);
	}

	public static int bfs(){
		ArrayDeque<Pair> dq = new ArrayDeque();
		for(Pair v : virus) dq.addLast(v);

		while(!dq.isEmpty()){
			Pair cur = dq.removeFirst();

			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(arr[nx][ny] == 1 || arr[nx][ny] == 2) continue;
				arr[nx][ny] = 2;
				dq.addLast(new Pair(nx,ny));
			}
		}
		
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(arr[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}

	public static void init(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				arr[i][j] = arr_copy[i][j];
			}
		}
	}
}