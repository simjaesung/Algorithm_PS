import java.io.*;
import java.util.*;

class Main {
	static int[][] dp;
	static List<Integer>[] adj;
	static int n;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
		for(int i = 0; i < n-1; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			adj[v].add(u);
			adj[u].add(v);
		}

		dp = new int[n+1][2];
		dfs(-1,1);
		System.out.println(Math.min(dp[1][0], dp[1][1]));
	}
	
	static void dfs(int parent, int cur){
		dp[cur][1] = 1;
		for(int child : adj[cur]){
			if(child == parent) continue;
			dfs(cur, child);
			dp[cur][0] += dp[child][1];
			dp[cur][1] += Math.min(dp[child][0], dp[child][1]);
		}
	}
}