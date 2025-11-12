import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n + 1];
		for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
		
		int ans = 0;
		int[] dp = new int[n + 1];
		for(int i = 1; i <= n; i++){
			for(int j = i - 1; j >= 0; j--){
				if(arr[i] > arr[j]) {
					dp[i] = Math.max(dp[i], dp[j] + arr[i]);
				}
			}
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
	}
}