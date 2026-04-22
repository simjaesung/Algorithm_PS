import java.io.*;
import java.util.*;

class Main {
	//0:북,1:동,2:남,3:서
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());

		int[][] arr = new int[n][m];
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}

		int ans = 0;
		Deque<int[]> dq = new ArrayDeque<>();
		dq.addLast(new int[]{r,c});

		while(!dq.isEmpty()){
			int[] cur = dq.removeFirst();
			int cx = cur[0], cy = cur[1];
			
			//현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
			if(arr[cx][cy] == 0){
				ans++; 
				arr[cx][cy] = 2;
			}

			boolean isNotClear = false;
			//현재 칸의 주변 4칸 중 청소되지 않았는지
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if(arr[nx][ny] == 0) isNotClear = true;
			}

			//청소되지 않은 빈 칸이 있는 경우
			if(isNotClear){
				//반시계 회전
				d = (d - 1 + 4) % 4;
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if(arr[nx][ny] == 0) dq.addLast(new int[]{nx,ny});
				else dq.addLast(new int[]{cx,cy});
			}else{
				//청소되지 않은 빈 칸이 없는 경우
				//방향 유지, 한 칸 후진하고 돌아간다
				int nx = cx + dx[(d + 2) % 4];
				int ny = cy + dy[(d + 2) % 4];
				if(arr[nx][ny] == 1) break;
				dq.addLast(new int[]{nx,ny});
			}
			
		}
		
		System.out.println(ans);
	}
}