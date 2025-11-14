import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n+1];
		int[] dp = new int[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());

		//dp[i] 는 i번째까지 중 가장 합이 큰 경우
		int ans = arr[1];
		dp[1] = arr[1];
		for(int i = 2; i <= n; i++){
			dp[i] = Math.max(dp[i-1] + arr[i], arr[i]);
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
	}
}