import java.io.*;
import java.util.*;

class Main {
	static int[] p;

	static int find(int x){
		if(p[x] != x) return p[x] = find(p[x]);
		return x;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		p = new int[n+1];
		for(int i = 0; i <= n; i++) p[i] = i;

		StringBuilder sb = new StringBuilder();
		
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if(k == 0) {
				int pa = find(a);
				int pb = find(b);
				p[pa] = pb;
			}else{
				if(find(a) == find(b)) sb.append("YES\n");
				else sb.append("NO\n");
			}
		}
		System.out.println(sb);
	}
}