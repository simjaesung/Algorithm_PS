import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long[] dp = new long[105];
		dp[1] = 1; dp[2] = 1; dp[3] = 1;
		dp[4] = 2; dp[5] = 2;

		for(int i = 6; i <= 101; i++) dp[i] = dp[i-1] + dp[i-5];

		int t = Integer.parseInt(br.readLine());
		while(t-- > 0){
			int n = Integer.parseInt(br.readLine());
			System.out.println(dp[n]);
		}
	}
}