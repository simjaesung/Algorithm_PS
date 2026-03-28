import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] dp = new int[n+1][2];
		for(int i = 2; i <= n; i++){
			dp[i][0] = dp[i-1][0] + 1; //횟수
			dp[i][1] = i - 1; //이전 idx
			if(i % 3 == 0){
				if(dp[i][0] > dp[i/3][0] + 1){
					dp[i][0] = dp[i/3][0] + 1;
					dp[i][1] = i/3;
				}
			}
			if(i % 2 == 0){
				if(dp[i][0] > dp[i/2][0] + 1){
					dp[i][0] = dp[i/2][0] + 1;
					dp[i][1] = i/2;
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		int val = n;
		while(val > 0){
			sb.append(val + " ");
			val = dp[val][1];
		}
		System.out.println(dp[n][0]);
		System.out.println(sb);
	}
}