import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long[][] dp = new long[91][2]; //i자리 이친수, 마지막자리가 0/1
		
		dp[1][1] = 1; dp[2][0] = 1;
		for(int i = 3; i <= n; i++){
			dp[i][0] = dp[i-1][0] + dp[i-1][1];
			dp[i][1] = dp[i-1][0];
		}
		System.out.println(dp[n][0] + dp[n][1]);
	}
}