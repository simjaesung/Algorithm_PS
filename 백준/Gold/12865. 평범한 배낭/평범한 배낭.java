import java.io.*;
import java.util.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[][] arr = new int[n+1][2];
		for(int i = 1; i <= n; i++){
			st = new StringTokenizer(br.readLine());
			int w = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			arr[i][0] = w; 
			arr[i][1] = v;
		}

		int[] dp = new int[k+1];
		for(int i = 1; i <= n; i++){
			int w = arr[i][0];
			int v = arr[i][1];
			
			for(int j = k; j >= w; j--){
				dp[j] = Math.max(dp[j], dp[j-w]+v);
			}
		}
		System.out.println(dp[k]);
	}
}