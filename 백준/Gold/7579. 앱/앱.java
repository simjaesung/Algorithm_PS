import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] memory = new int[n + 1];
		int[] c = new int[n+1];

		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) memory[i] = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int sumC = 0;
		for(int i = 1; i <= n; i++) {
			c[i] = Integer.parseInt(st.nextToken());
			sumC += c[i];
		}

		int[][] dp = new int[n+1][sumC+1];
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= sumC; j++){
				if(j < c[i]) dp[i][j] = dp[i-1][j];
				else dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-c[i]] + memory[i]);
			}
		}

		int ans = sumC;
		for(int j = 0; j <= sumC; j++){
			if(dp[n][j] >= m) ans = Math.min(ans, j);
		}
		
		System.out.println(ans);
	}
}