import java.io.*;
import java.util.*;

class Main {
	static class Tuple{
		int x; int y; int cost;
		public Tuple(int x, int y, int cost){
			this.x = x; this.y = y; this.cost = cost;
		}
	}
	static int ans = Integer.MAX_VALUE / 2;
	static int[] p;

	static int find(int x){
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		p = new int[n+1];
		for(int i = 1; i <= n; i++) p[i] = i;

		PriorityQueue<Tuple> pq = new PriorityQueue<>((a,b) -> b.cost - a.cost);
		
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			pq.offer(new Tuple(a,b,c));
		}

		st = new StringTokenizer(br.readLine());
		int start = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());

		while(!pq.isEmpty()){
			Tuple cur = pq.poll();
			int px = find(cur.x);
			int py = find(cur.y);
			if(px != py) p[py] = px;
			ans = Math.min(ans, cur.cost);
			
			if(find(start) == find(end)) break;
		}
		
		System.out.println(ans);
	}
}