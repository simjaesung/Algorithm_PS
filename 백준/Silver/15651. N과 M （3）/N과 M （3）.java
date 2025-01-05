import java.io.*;
import java.util.*;

class Main {
	public static int n;
	public static int m;
	public static int[] arr;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[m];
		go(0);
		System.out.print(sb.toString());
	}
	
	public static void go(int cnt){
		if(cnt == m){
			for(int i = 0; i < m; i++){
				sb.append(arr[i] + " ");
			}
			sb.append("\n");
			return;
		}
		
		for(int i = 0; i < n; i++){
			arr[cnt] = i + 1;
			go(cnt + 1);
		}
	}
}