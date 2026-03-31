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
		int left = 0, right = 0, sum = 0, ans = n+1;
		
		while(left < n){
			if(sum < s){
				if(right == n) break;
				sum += arr[right++];
			}else{
				ans = Math.min(ans, right - left);
				sum -= arr[left++];
			}
		}
		System.out.println(ans == n+1? 0 : ans);
	}
}