import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		long[] dp = new long[n];
		
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.fill(dp,Long.MAX_VALUE);
		dp[0] = 0;
		
		for(int i = 1; i < n; i++){
			for (int j = 0; j < i; j++) {
				long cost = (long) (i - j) * (1 + Math.abs(arr[i] - arr[j]));
				dp[i] = Math.min(dp[i], Math.max(dp[j], cost));
			}
		}
		System.out.println(dp[n-1]);
	}
}