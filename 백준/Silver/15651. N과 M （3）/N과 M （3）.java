import java.io.*;
import java.util.*;

class Main {
	static int n,m;
	static int[] arr;
	static StringBuilder sb = new StringBuilder();
	
	static void go(int k){
		if(k == m){
			for(int val : arr) sb.append(val + " ");
			sb.append("\n");
			return;
		}

		for(int i = 1; i <= n; i++){
			arr[k] = i;
			go(k + 1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		arr = new int[m];
		go(0);
		System.out.println(sb);
	}
}