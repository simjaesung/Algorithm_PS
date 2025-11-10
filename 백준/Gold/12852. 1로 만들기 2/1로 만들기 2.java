import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] dp = new int[n+1];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[1] = 0;
		int[] pre = new int[n+1];
		
		for(int i = 2; i <= n; i++){
			if(i % 3 == 0 && dp[i] > dp[i / 3] + 1){
				dp[i] = dp[i/3] + 1;
				pre[i] = i/3;
			}
			if(i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i/2] + 1;
				pre[i] = i/2;
			}
			if(dp[i] > dp[i - 1] + 1){
				dp[i] = dp[i-1] + 1;
				pre[i] = i-1;
			}
		}
		
		System.out.println(dp[n]);
		int cur = n;
		StringBuilder sb = new StringBuilder();
		while(cur != 1){
			sb.append(cur + " ");
			cur = pre[cur];
		}
		sb.append(cur);
		System.out.print(sb);
	}
}