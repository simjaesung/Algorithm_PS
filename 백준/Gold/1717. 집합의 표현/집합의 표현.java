import java.io.*;
import java.util.*;

class Main {
	static int[] p;
	public static int find(int x){
		if(x != p[x]){
			return p[x] = find(p[x]);
		}
		return p[x];
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		p = new int[n+1];
		for(int i = 1; i <= n; i++) p[i] = i;
		
		StringBuilder sb = new StringBuilder();
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int mode = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if(mode == 0){
				int p1 = find(a);
				int p2 = find(b);
				p[p1] = p2;
			}else{
				if(find(a) == find(b)) sb.append("YES\n");
				else sb.append("NO\n");
			}
		}
		
		System.out.println(sb);
	}
}