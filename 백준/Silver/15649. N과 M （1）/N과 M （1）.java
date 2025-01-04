import java.io.*;
import java.util.*;

class Main {
	public static int n,m;
	public static int[] c = new int[9];
	public static int[] arr = new int[9];
	
	public static void go(int cnt){
		if(cnt == m){
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < m; i++){
				sb.append((arr[i] + 1) + " ");
			}
			System.out.println(sb.toString());
			return;
		}
		
		for(int i = 0; i < n; i++){
			if(c[i] == 1) continue;
			arr[cnt] = i;
			c[i] = 1;
			go(cnt + 1);
			c[i] = 0;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st =  new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		go(0);
	}
}