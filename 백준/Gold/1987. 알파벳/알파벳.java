import java.io.*;
import java.util.*;

class Main {
	static char[][] arr;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int R,C,ans;
	static boolean[] visited = new boolean[26];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		arr = new char[R][C];
		for(int i = 0; i < R; i++){
			String input = br.readLine();
			for(int j = 0; j < C; j++) arr[i][j] = input.charAt(j);
		}
		visited[arr[0][0] - 'A'] = true;
		dfs(0,0,1);
		System.out.println(ans);
	}

	public static void dfs(int x, int y, int cnt){
		ans = Math.max(ans, cnt);

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if(visited[arr[nx][ny] - 'A']) continue;
			visited[arr[nx][ny] - 'A'] = true;
			dfs(nx,ny,cnt+1);
			visited[arr[nx][ny] - 'A'] = false;
		}
	}
}