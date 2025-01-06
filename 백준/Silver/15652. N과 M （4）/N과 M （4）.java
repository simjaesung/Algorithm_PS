import java.io.*;
import java.util.*;

class Main {
	public static StringBuilder sb = new StringBuilder();
	public static int n,m;
	public static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[m];
		
		go(0,0);
		System.out.println(sb.toString());
	}
	
	public static void go(int cnt, int val){
		if(cnt == m){
			for(int i = 0; i < m; i++) sb.append(arr[i] + " ");
			sb.append("\n");
			return;
		}
		
		for(int i = val; i < n; i++){
			arr[cnt] = i + 1;
			go(cnt + 1, i);
		}
	}
}