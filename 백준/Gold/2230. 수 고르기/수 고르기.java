import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		int ans = Integer.MAX_VALUE;
		int i = 0; int j = 0;
		while(j < n && i <= j){
			int diff = arr[j] - arr[i];
			if(diff < m) j++;
			else {
				ans = Math.min(ans, diff);
				i++;
			}
		}
		
		System.out.println(ans);
	}
}