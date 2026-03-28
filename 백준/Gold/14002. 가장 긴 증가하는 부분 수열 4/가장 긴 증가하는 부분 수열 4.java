import java.io.*;
import java.util.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		int[] pre = new int[n];
		int[] dp = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			pre[i] = i;
		}

		int ans = 1, stIdx = 0;
		dp[0] = 1;
		for(int i = 1; i < n; i++){
			dp[i] = 1;
			for(int j = i - 1; j >= 0; j--){
				if(arr[i] > arr[j]) {
					if(dp[i] < dp[j] + 1){
						dp[i] = dp[j] + 1;
						pre[i] = j;
					}
				}
			}
			if(dp[i] > ans){
				ans = dp[i];
				stIdx = i;
			}
		}
		
		List<Integer> track = new ArrayList<>();
		while(true){
			track.add(arr[stIdx]);
			if(pre[stIdx] == stIdx) break;
			stIdx = pre[stIdx];
		}
		System.out.println(ans);
		StringBuilder sb = new StringBuilder();
		for(int i = track.size() - 1; i >= 0; i--) sb.append(track.get(i) + " ");
		System.out.println(sb);
	}
}