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
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());

		ArrayList<Pair>[] adj1 = new ArrayList[n+1];
		ArrayList<Pair>[] adj2 = new ArrayList[n+1];
		for(int i = 1; i <= n; i++){
			adj1[i] = new ArrayList<>();
			adj2[i] = new ArrayList<>();
		}
		
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			adj1[a].add(new Pair(b,t));
			adj2[b].add(new Pair(a,t));
		}

		//x에서 각각 노드로 가는 거리
		int[] xToPer = new int[n+1];
		Arrays.fill(xToPer, INF);
		PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.y - b.y);
		pq.offer(new Pair(x,0));
		xToPer[x] = 0;

		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(xToPer[cur.x] != cur.y) continue;
			for(Pair nxt : adj1[cur.x]){
				if(xToPer[nxt.x] <= nxt.y + xToPer[cur.x]) continue;
				xToPer[nxt.x] = nxt.y + xToPer[cur.x];
				pq.offer(new Pair(nxt.x, xToPer[nxt.x]));
			}
		}

		//각각 노드에서 x로 가는 거리
		int[] perToX = new int[n+1];
		Arrays.fill(perToX, INF);
		pq.offer(new Pair(x,0));
		perToX[x] = 0;

		while(!pq.isEmpty()){
			Pair cur = pq.poll();
			if(perToX[cur.x] != cur.y) continue;
			for(Pair nxt : adj2[cur.x]){
				if(perToX[nxt.x] <= nxt.y + perToX[cur.x]) continue;
				perToX[nxt.x] = nxt.y + perToX[cur.x];
				pq.offer(new Pair(nxt.x, perToX[nxt.x]));
			}
		}

		int ans = 0;
		for(int i = 1; i<=n; i++){
			ans = Math.max(ans, perToX[i] + xToPer[i]);
		}
		System.out.println(ans);
	}
}