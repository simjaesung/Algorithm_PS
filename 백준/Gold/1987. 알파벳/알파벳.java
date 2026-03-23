import java.io.*;
import java.util.*;

class Main {
	static int R,C,ans;
	static String[][] arr;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static boolean[][] visited;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new String[R][C];
		visited = new boolean[R][C];
		
		for(int i = 0; i < R; i++){
			String input = br.readLine();
			for(int j = 0; j < C; j++) arr[i][j] = input.charAt(j)+"";
		}
		go(0,0,arr[0][0]);
		visited[0][0] = true;
		System.out.println(ans);
	}

	static void go(int cx, int cy, String tmp){
		ans = Math.max(tmp.length(), ans);

		for(int i = 0; i < 4; i++){
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if(tmp.contains(arr[nx][ny])) continue;
			if(visited[nx][ny]) continue;
			visited[nx][ny] = true;
			go(nx,ny,tmp + arr[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}