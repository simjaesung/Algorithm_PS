import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());

		//dp[i][j] : i번째수까지 사용했을 때 j가 나오는 경우의 수
		long[][] dp = new long[n][21];
		dp[0][arr[0]] = 1;
		for(int i = 1; i < n; i++){
			for(int j = 0; j <= 20; j++){
				if(j-arr[i] >= 0) dp[i][j] += dp[i-1][j-arr[i]];
				if(j+arr[i] <= 20) dp[i][j] += dp[i-1][j+arr[i]];
			}
		}
		System.out.println(dp[n-2][arr[n-1]]);
	}
}