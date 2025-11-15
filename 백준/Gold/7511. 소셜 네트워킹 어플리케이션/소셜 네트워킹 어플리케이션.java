import java.io.*;
import java.util.*;

class Main {
	static int[] p;
	static int find(int x){
		if(p[x] != x) p[x] = find(p[x]);
		return p[x];
	}
	static void union(int a, int b){
		int pa = find(a);
		int pb = find(b);
		if(pa != pb) p[pa] = pb;
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		for(int i = 1; i <= t; i++){
			sb.append("Scenario " + i + ":\n");
			int n = Integer.parseInt(br.readLine());
			p = new int[n + 1];
			for(int j = 1; j <= n; j++) p[j] = j;

			int k = Integer.parseInt(br.readLine());
			while(k -- > 0){
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				union(a,b);
			}

			int m = Integer.parseInt(br.readLine());
			while(m-- > 0){
				st = new StringTokenizer(br.readLine());
				int u = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				if(find(u) == find(v)) sb.append(1 + "\n");
				else sb.append(0 + "\n");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}