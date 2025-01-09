import java.io.*;
import java.util.*;

class Main {
	public static int[] arr;
	public static int[] c;
	public static int n;
	public static int m;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st1.nextToken());
		m = Integer.parseInt(st1.nextToken());
		arr = new int[n];
		c = new int[n];
		
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st2.nextToken());
		}
		Arrays.sort(arr);
		go(0,0);
		System.out.println(sb.toString());
	}
	
	public static void go(int k, int l){
		if(k == m){
			for(int i = 0; i<m; i++) sb.append(c[i] + " ");
			sb.append("\n");
			return;
		}
		
		for(int i = l; i < n; i++){
			if(c[k] != 0) continue;
			c[k] = arr[i];
			go(k + 1, i + 1);
			c[k] = 0;
		}
	}
	
}