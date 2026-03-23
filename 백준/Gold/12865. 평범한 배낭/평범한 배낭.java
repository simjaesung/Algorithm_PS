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

		//dp[i][j] = i번째 물건을 넣으려고할때 무게가 j이상일때 최대 가치
		int[][] dp = new int[n+1][k+1];
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= k; j++){
				if(arr[i][0] <= j) dp[i][j] = Math.max(dp[i-1][j-arr[i][0]] + arr[i][1], dp[i-1][j]);
				else dp[i][j] = dp[i-1][j];
			}
		}
		System.out.println(dp[n][k]);
	}
}