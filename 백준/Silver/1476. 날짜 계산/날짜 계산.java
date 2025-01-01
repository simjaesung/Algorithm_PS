import java.io.*;
import java.util.*;

class Main {
	static int E;
	static int S;
	static int M;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < 3; i++){
			if(i == 0) E = Integer.parseInt(st.nextToken());
			if(i == 1) S = Integer.parseInt(st.nextToken());
			if(i == 2) M = Integer.parseInt(st.nextToken());
		}
		
		int e = 1, s = 1, m = 1;
		int ans = 1;
		while(true){
			if(e > 15) e %= 15;
			if(s > 28) s %= 28;
			if(m > 19) m %= 19;
			if(e == E && s == S && m == M) break;
			e++; s++; m++; ans++;
		}
		
		System.out.println(ans);
	}
}