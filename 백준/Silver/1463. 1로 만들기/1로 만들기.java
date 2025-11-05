import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] dp = new int[1000005];
		for(int i = 2; i <= n; i++){
			if(i % 2 == 0 && i % 3 == 0){
				dp[i] = Math.min(dp[i/2], Math.min(dp[i/3],dp[i-1])) + 1;
			}else if(i % 2 == 0){
				dp[i] = Math.min(dp[i/2],dp[i-1]) + 1;
			}else if(i % 3 == 0){
				dp[i] = Math.min(dp[i/3],dp[i-1]) + 1;
			} else dp[i] = dp[i-1] + 1;
		}
		System.out.println(dp[n]);
	}
}