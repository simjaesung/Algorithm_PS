import java.io.*;
import java.util.*;

class Main {
	public static int n,s,ans;
	public static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		s = Integer.parseInt(st.nextToken());
		
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		
		arr = new int[n];
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st2.nextToken());
		}
		
		go(0,0);
		if(s == 0) ans--;
		System.out.println(ans);
	}
	
	public static void go(int idx, int sum){
		if(idx == n) {
			if(sum == s) ans++;
			return;
		}
		go(idx + 1, sum);
		go(idx + 1, sum + arr[idx]);
	}
}