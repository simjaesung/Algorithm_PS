import java.io.*;
import java.util.*;

class Main {
	static ArrayList<Integer>[] adj;
	static int[] p;

	static void dfs(int cur){
		for(int nxt : adj[cur]){
			if(p[cur] == nxt) continue;
			p[nxt] = cur;
			dfs(nxt);
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		adj = new ArrayList[n+1];
		p =  new int[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
		
		for(int i = 1; i <= n-1; i++){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
		}

		dfs(1);
		StringBuilder sb = new StringBuilder();
		for(int i = 2; i <= n; i++) sb.append(p[i] + "\n");
		System.out.println(sb);
	}
}