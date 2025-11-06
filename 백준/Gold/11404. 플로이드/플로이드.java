import java.io.*;
import java.util.*;

class Main {
	static int[][] arr;
	static int INF = Integer.MAX_VALUE / 2;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		arr = new int[n+1][n+1];
		for(int i = 1; i <= n; i++) Arrays.fill(arr[i],INF);
		for(int i = 1; i <= n; i++) arr[i][i] = 0;
		
		while(m-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			arr[a][b] = Math.min(arr[a][b],cost);
		}

		for(int k = 1; k <=n; k++){
			for(int i = 1; i <=n; i++){
				for(int j = 1; j <=n; j++){
						arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
					}
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <=n; i++){
			StringBuilder tmp = new StringBuilder();
			for(int j = 1; j <=n; j++){
					if(arr[i][j] == INF) tmp.append(0 + " ");
					else tmp.append(arr[i][j] + " ");
				}
			sb.append(tmp + "\n");
		}

		System.out.println(sb);
	}
}