import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}

	static int INF = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());

		int[] dist = new int[n+1];
		Arrays.fill(dist, INF);
		int[] tracking = new int[n+1];
		ArrayList<Pair>[] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
		
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			adj[a].add(new Pair(b,cost));
		}

		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.y - b.y);

		dist[start] = 0;
		pq.offer(new Pair(start, dist[start]));
		
		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(dist[cur.x] != cur.y) continue;

			for(Pair nxt : adj[cur.x]){
				if(dist[cur.x] + nxt.y >= dist[nxt.x]) continue;
				dist[nxt.x] = dist[cur.x] + nxt.y;
				tracking[nxt.x] = cur.x; //nxt.x는 cur.x로 부터 왔음
				pq.offer(new Pair(nxt.x, dist[nxt.x]));
			}
		}
		
		System.out.println(dist[end]);

		ArrayList<Integer> arr = new ArrayList<>();
		int cnt = 0;
		int cur = end;
		while(cur != start){
			cnt++;
			arr.add(cur);
			cur = tracking[cur];
		}
		arr.add(cur);
		System.out.println(arr.size());
		for(int i = arr.size() - 1; i >= 0; i--) System.out.print(arr.get(i) + " ");
	}
}