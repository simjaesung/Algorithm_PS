import java.io.*;
import java.util.*;
class Main {
	static int n;
	static int[] arr;
	static int[][] dp;
	static List<Integer>[] adj;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n+1];
		dp = new int[n+1][2];
		adj = new ArrayList[n+1];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
		for(int i = 0; i < n-1; i++){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
		}

		int root = 1;
		dfs(-1,root);
		System.out.println(Math.max(dp[root][0], dp[root][1]));
	}
	
	static void dfs(int parent, int cur){
		dp[cur][1] = arr[cur];
		for(int nxt : adj[cur]){
			if(nxt == parent) continue;
			dfs(cur, nxt);
			dp[cur][0] += Math.max(dp[nxt][0], dp[nxt][1]);
			dp[cur][1] += dp[nxt][0];
		}
	}
}