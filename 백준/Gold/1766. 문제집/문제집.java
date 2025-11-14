import java.io.*;
import java.util.*;

class Main {	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		ArrayList<Integer>[] adj = new ArrayList[n+1];
		for(int i = 1; i <=n; i++) adj[i] = new ArrayList<>();
		int[] rece = new int[n+1];

		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			rece[b]++;
			adj[a].add(b);
		}

		PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> a - b);
		for(int i = 1; i <= n; i++) if(rece[i] == 0) pq.offer(i);

		StringBuilder sb = new StringBuilder();
		while(!pq.isEmpty()){
			int cur = pq.poll();
			sb.append(cur + " ");
			for(int nxt : adj[cur]){
				rece[nxt]--;
				if(rece[nxt] == 0) pq.offer(nxt);
			}
		}
		
		System.out.println(sb);
	}
}