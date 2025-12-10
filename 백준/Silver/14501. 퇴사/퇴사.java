import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] t = new int[n];
		int[] p = new int[n];
		
		for(int i = 0; i < n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			t[i] = Integer.parseInt(st.nextToken());
			p[i] = Integer.parseInt(st.nextToken());
		}
		
		int[] dp = new int[n+1];
		for(int i = 1; i <= n; i++){
			dp[i] = dp[i-1];
			for(int j = 0; j < i; j++){
				if(i == t[j] + j) {
					dp[i] = Math.max(dp[i], p[j] + dp[j]);
				}
			}
		}

		System.out.print(dp[n]);
	}
}