import java.io.*;
import java.util.*;
class Main {
	static class Tuple{
		int x; int y; int cost;
		public Tuple(int x, int y, int cost){
			this.x = x; this.y = y; this.cost = cost;
		}
	}

	static int[] p;
	static int find(int x){
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		p = new int[n+1];
		for(int i = 1; i <= n; i++) p[i] = i;

		PriorityQueue<Tuple> pq = new PriorityQueue<>((a,b) -> a.cost - b.cost);
		for(int i = 1; i <= n; i++){
			int cost = Integer.parseInt(br.readLine());
			pq.offer(new Tuple(0,i,cost));
		}
		
		for(int i = 1; i <= n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= n; j++){
				int cost = Integer.parseInt(st.nextToken());
				if(i == j) continue;
				pq.offer(new Tuple(i,j,cost));
			}
		}

		int v = 0;
		int ans = 0;

		while(v < n){
			Tuple cur = pq.poll();
			int pa = find(cur.x);
			int pb = find(cur.y);
			if(pa == pb) continue;
			v++; ans += cur.cost;
			p[pa] = pb;
		}
		
		System.out.println(ans);
	}
}