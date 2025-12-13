import java.io.*;
import java.util.*;

class Main {
	static ArrayList<Integer>[] adj;
	static int[] rece;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
		rece = new int[n+1];

		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			rece[b]++;
		}

		Deque<Integer> dq = new ArrayDeque<>();
		for(int i = 1; i <= n; i++) {
			if(rece[i] == 0) dq.addLast(i);
		}

		StringBuilder sb = new StringBuilder();
		while(!dq.isEmpty()){
			int cur = dq.removeFirst();
			sb.append(cur + " ");
			for(int nxt : adj[cur]){
				rece[nxt]--;
				if(rece[nxt] == 0) dq.addLast(nxt);
			}
		}

		System.out.println(sb);
	}
}