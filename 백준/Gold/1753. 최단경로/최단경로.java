import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int v; //간선
		int w; //가중치
		public Pair(int v, int w){
			this.v = v; this.w = w;
		}
	}
	static int INF = Integer.MAX_VALUE;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());

		int start = Integer.parseInt(br.readLine());
		ArrayList<Pair>[] adj = new ArrayList[V+1];
		for(int i = 0; i <= V; i++) adj[i] = new ArrayList<>();
		while(E-- > 0){
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			adj[u].add(new Pair(v,w));
		}

		PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.w - b.w);
		pq.offer(new Pair(start, 0));
		int[] dist = new int[V+1];
		for(int i = 0; i <= V; i++) dist[i] = INF;
		dist[start] = 0;

		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(dist[cur.v] != cur.w) continue;

			for(Pair nxt : adj[cur.v]){
				if(dist[cur.v] + nxt.w >= dist[nxt.v]) continue;
				dist[nxt.v] = dist[cur.v] + nxt.w;
				pq.offer(new Pair(nxt.v, dist[nxt.v]));
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= V; i++) {
			if(dist[i] == INF) sb.append("INF\n");
			else sb.append(dist[i] + "\n");
		}
		
		System.out.println(sb);
	}
}