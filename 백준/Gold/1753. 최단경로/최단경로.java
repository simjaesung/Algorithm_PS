import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; //정점
		int y; //거리
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	static int[] dist;
	static List<Pair>[] adj;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());

		dist = new int[V+1];
		for(int i = 0; i <= V; i++) dist[i] = Integer.MAX_VALUE;
		
		adj = new ArrayList[V+1];
		for(int i = 0; i <= V; i++) adj[i] = new ArrayList<>();

		int k = Integer.parseInt(br.readLine());

		while(E-- >0){
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			adj[u].add(new Pair(v,w));
		}

		PriorityQueue<Pair>pq = new PriorityQueue<>((a,b) -> a.y - b.y);
		pq.offer(new Pair(k,0));
		dist[k] = 0;

		while(!pq.isEmpty()){
			Pair cur = pq.peek(); pq.poll();
			if(cur.y != dist[cur.x]) continue;
			for(Pair nxt : adj[cur.x]){
				if(dist[nxt.x] <= dist[cur.x] + nxt.y) continue;
				dist[nxt.x] = dist[cur.x] + nxt.y;
				pq.offer(new Pair(nxt.x, dist[nxt.x]));
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= V; i++) {
			if(dist[i] == Integer.MAX_VALUE) sb.append("INF\n");
			else sb.append(dist[i] + "\n");
		}

		System.out.println(sb);
	}
}