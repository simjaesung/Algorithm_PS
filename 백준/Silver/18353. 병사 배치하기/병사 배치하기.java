import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Long[] arr = new Long[n];
		Long[] dp = new Long[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++){
			arr[i] = Long.parseLong(st.nextToken());
		}
		Arrays.fill(dp, 0L);
		Long dpMax = 0L;
		
		for(int i = 0; i < n; i++){
			for(int j = i - 1; j >= 0; j--){
				if(arr[j] > arr[i]) {
					dp[i] = Math.max(dp[i],dp[j] + 1);
				}
			}
			if(dp[i] == 0) dp[i] = 1L;
			dpMax = Math.max(dpMax,dp[i]);
		}
		
		System.out.println(n - dpMax);
	}
}