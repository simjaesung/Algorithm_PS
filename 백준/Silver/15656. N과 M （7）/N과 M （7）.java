import java.io.*;
import java.util.*;

class Main {
	public static int n,m;
	public static int[] arr,c;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[n];
		c = new int[m];
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st2.nextToken());
		}
		Arrays.sort(arr);
		go(0);
		System.out.println(sb.toString());
	}
	
	public static void go(int k){
		if(k == m){
			for(int i = 0; i < m; i++){
				sb.append(c[i] + " ");
			}
			sb.append("\n");
			return;
		}
		
		for(int i = 0; i < n; i++){
			c[k] = arr[i];
			go(k + 1);
		}
	}
}