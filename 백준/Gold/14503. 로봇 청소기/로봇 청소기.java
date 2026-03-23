import java.io.*;
import java.util.*;

class Main {
	static class Tuple{
		int x; int y; int d;
		public Tuple(int x, int y, int d){
			this.x = x; this.y = y; this.d = d;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int cx = Integer.parseInt(st.nextToken());
		int cy = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());

		int[] dx = {-1,0,1,0};
		int[] dy = {0,1,0,-1};

		int[][] arr = new int[n][m];
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}
		//1:벽, 0:빈칸, 2:청소
		Deque<Tuple> q = new ArrayDeque<>();
		q.addLast(new Tuple(cx,cy,d));
		int ans = 0;
		while(!q.isEmpty()){
			Tuple cur = q.removeFirst();
			if(arr[cur.x][cur.y] == 0){
				ans++; 
				arr[cur.x][cur.y] = -1;
			}

			boolean isDirty = false;
			
			for(int i = 0; i < 4; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(arr[nx][ny] == 0) {
					isDirty = true;
					break;
				}
			}

			if(isDirty){
				//청소되지 않은 빈 칸이 있는 경우
				d = (d + 4 - 1) % 4;
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				if(arr[nx][ny] == 0) q.addLast(new Tuple(nx,ny,d));
				else q.addLast(new Tuple(cur.x,cur.y,d));
			}else{
				//청소되지 않은 빈 칸이 없는 경우
				int back = (d + 2) % 4;
				int nx = cur.x + dx[back];
				int ny = cur.y + dy[back];
				if(arr[nx][ny] == 1) break;
				q.addLast(new Tuple(nx,ny,d));
			}
		}
		
		System.out.println(ans);
	}
}