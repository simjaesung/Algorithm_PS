import java.io.*;
import java.util.*;

class Main {
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
		
		//1:벽, 0:빈칸, -1:청소
		int ans = 0;
		while(true){
			if(arr[cx][cy] == 0){
				ans++; 
				arr[cx][cy] = -1;
			}

			boolean isDirty = false;
			
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(arr[nx][ny] == 0) {
					isDirty = true;
					break;
				}
			}

			if(isDirty){
				//청소되지 않은 빈 칸이 있는 경우
				d = (d + 4 - 1) % 4;
				int nx = cx + dx[d];
				int ny = cy + dy[d];
				if(arr[nx][ny] == 0) {
					cx = nx; 
					cy = ny;
				}
			}else{
				//청소되지 않은 빈 칸이 없는 경우
				int back = (d + 2) % 4;
				cx += dx[back]; cy += dy[back];
				if(arr[cx][cy] == 1) break;
			}
		}
		
		System.out.println(ans);
	}
}