import java.io.*;
import java.util.*;

class Main {
	static class Tuple{
		int a; int b; int cost;
		public Tuple(int a, int b, int cost){
			this.a = a; this.b = b; this.cost = cost;
		}
	}
	
	static int[] p;
	static int find(int x){
		if(p[x] != x){
			return p[x] = find(p[x]);
		}
		return p[x];
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int v = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		p = new int[v+1];
		for(int i = 1; i <= v; i++) p[i] = i;

		Tuple[] adj = new Tuple[e];

		while(e-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());
			adj[e] = new Tuple(a,b,cost);
		}

		Arrays.sort(adj, (a,b) -> a.cost - b.cost);

		long ans = 0;
		int cnt_v = 0;
		
		for(Tuple t : adj){
			//두 노드의 그룹이 다를 경우 같은 그룹으로 만들어주고 묶음
			int pa = find(t.a); int pb = find(t.b);
			if(pa != pb){
				p[pa] = pb;
				ans += t.cost;
				cnt_v++;
			}
			if(cnt_v == v-1) break;
		}
		
		System.out.println(ans);
	}
}