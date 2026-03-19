import java.io.*;
import java.util.*;

class Main {
	static char[][] arr;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	static int R,C,ans;
	
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

		int start = arr[0][0] - 'A';
		dfs(0,0,(1 << start));
		System.out.println(ans);
	}

	public static void dfs(int x, int y, int mask){
		ans = Math.max(ans, Integer.bitCount(mask));

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			int nxt = arr[nx][ny] - 'A';
			if((mask & 1 << nxt) != 0) continue;
			dfs(nx,ny, mask | (1 << nxt));
		}
	}
}