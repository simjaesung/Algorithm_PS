import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] dp = new int[n + 1][n];
		
		int k = 1;
		while(k <= n){
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < k; i++){
				int val = Integer.parseInt(st.nextToken());
				if(i == 0) dp[k][i] = dp[k-1][i] + val;
				else if(i == k - 1) dp[k][i] = dp[k-1][i - 1] + val;
				else dp[k][i] = Math.max(dp[k-1][i-1], dp[k-1][i]) + val;
			}
			k++;
		}
		
		int ans = dp[n][0];
		for(int val : dp[n]) ans = Math.max(ans, val);
		System.out.println(ans);
	}
}