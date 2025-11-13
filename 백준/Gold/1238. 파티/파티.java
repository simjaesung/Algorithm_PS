import java.io.*;
import java.util.*;

class Main {
	static int INF = Integer.MAX_VALUE / 2;
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());

		ArrayList<Pair>[] adj = new ArrayList[n + 1];
		for(int i = 1; i <=n; i++) adj[i] = new ArrayList<>();
		
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			adj[a].add(new Pair(b,t));
		}
		
		int[] XtoPer = new int[n + 1];
		Arrays.fill(XtoPer, INF);
		
		PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.y - b.y);
		pq.offer(new Pair(x,0));
		XtoPer[x] = 0;
		
		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(XtoPer[cur.x] != cur.y) continue;

			for(Pair nxt : adj[cur.x]){
				if(XtoPer[nxt.x] <= XtoPer[cur.x] + nxt.y) continue;
				XtoPer[nxt.x] = XtoPer[cur.x] + nxt.y;
				pq.offer(new Pair(nxt.x, XtoPer[nxt.x]));
			}
		}

		//X외 지역에서 X까지의 최단 거리를 구하기 위한
		int[] perToX = new int[n + 1];
		for(int i = 1; i <= n; i++) {
			if(i == x) continue;
			int[] tmp = new int[n+1]; //임시 배열
			pq.offer(new Pair(i,0));
			Arrays.fill(tmp, INF);
			tmp[i] = 0;

			while(!pq.isEmpty()){
				Pair cur = pq.poll();
				if(tmp[cur.x] != cur.y) continue;
	
				for(Pair nxt : adj[cur.x]){
					if(tmp[nxt.x] <= tmp[cur.x] + nxt.y) continue;
					tmp[nxt.x] = tmp[cur.x] + nxt.y;
					pq.offer(new Pair(nxt.x, tmp[nxt.x]));
				}
			}
			perToX[i] = tmp[x];
		}
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = Math.max(perToX[i] + XtoPer[i], ans);
		}
		System.out.print(ans);
	}
}