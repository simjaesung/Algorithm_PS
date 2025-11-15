import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int cost;
		public Pair(int x, int cost){
			this.x = x; this.cost = cost;
		}
	}
	static int INF = Integer.MAX_VALUE / 2;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		ArrayList<Pair>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
		
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			adj[a].add(new Pair(b,c));
			adj[b].add(new Pair(a,c));
		}

		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());

		//w[i] 는 시작점에서 i까지 갈 때 가져갈 수 있는 물품 최대 중량
		int[] w = new int[n+1];
		//시작점 -> 시작점은 무게 제한이 없음
		w[start] = INF;
		
		PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> b.cost - a.cost);
		pq.offer(new Pair(start, INF));

		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(w[cur.x] != cur.cost) continue;

			for(Pair nxt : adj[cur.x]){
				//다음으로 가려고하는데 이미 더 많이 옮길 수 있을 때 
				if(w[nxt.x] >= Math.min(w[cur.x],nxt.cost)) continue;
				w[nxt.x] = Math.min(w[cur.x],nxt.cost);
				pq.offer(new Pair(nxt.x, w[nxt.x]));
			}
		}
		System.out.println(w[end]);
	}
}