import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[] arr = new int[n+1];
		for(int i = 2; i <= n; i++) arr[i] = i;
		int cnt = 0;
		int ans = 0;
		
		for(int i = 2; i <= n; i++){
			if(arr[i] == 0) continue;
			for(int j = i; j <= n; j+=i){
				if(arr[j] == 0) continue;
				arr[j] = 0;
				cnt++;
				if(cnt == k) ans = j;
			}
		}
		
		System.out.println(ans);
	}
}