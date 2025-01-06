import java.io.*;
import java.util.*;

class Main {
	public static StringBuilder sb = new StringBuilder();
	public static int n,m;
	public static int[] arr;
	public static int[] save;
	public static boolean[] c;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n];
		save = new int[m];
		c = new boolean[n];
		
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st2.nextToken());
		}
		Arrays.sort(arr);
		
		go(0);
		System.out.println(sb.toString());
	}
	
	public static void go(int cnt){
		if(cnt == m){
			for(int i = 0; i < m; i++) sb.append(save[i] + " ");
			sb.append("\n");
			return;
		}
		
		for(int i = 0; i < n; i++){
			if(c[i]) continue;
			c[i] = true;
			save[cnt] = arr[i];
			go(cnt + 1);
			c[i] = false;
		}
	}
}