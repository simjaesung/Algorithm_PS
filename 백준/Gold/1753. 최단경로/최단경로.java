import java.io.*;
import java.util.*;

class Main {
	static int INF = Integer.MAX_VALUE;
	static class Pair{
		int x; //간선
		int y; //가중치
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
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

		PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.y - b.y);

		int[] dist = new int[V+1];
		Arrays.fill(dist, INF);
		dist[start] = 0;

		pq.offer(new Pair(start, 0));
		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(dist[cur.x] != cur.y) continue;

			for(Pair nxt : adj[cur.x]){
				if(dist[cur.x] + nxt.y >= dist[nxt.x]) continue;
				dist[nxt.x] = dist[cur.x] + nxt.y;
				pq.offer(new Pair(nxt.x, dist[nxt.x]));
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= V; i++){
			if(dist[i] == INF) sb.append("INF\n");
			else sb.append(dist[i] + "\n");
		}
		
		System.out.println(sb);
	}
}