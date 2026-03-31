import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
		int p1 = 0, p2 = 0, sum = 0, ans = n+1;
		
		while(p2 < n){
			if(sum < s){
				sum += arr[p2++];
			}else{
				ans = Math.min(ans, p2 - p1);
				sum -= arr[p1++];
			}
		}
		
		while(p1 < n){
			if(sum >= s){
				ans = Math.min(ans, p2 - p1);
			}
			sum -= arr[p1++];
		}
		
		if(ans == n+1) System.out.println(0);
		else System.out.println(ans);
	}
}