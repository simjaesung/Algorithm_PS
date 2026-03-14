import java.io.*;
import java.util.*;

class Main {
	static int[] arr;
	static int n;
	static int lower_bound(int target){
		int st = -1; 
		int end = n;

		while(st + 1 < end){
			int mid = st + (end - st) / 2;
			if(arr[mid] >= target) end = mid;
			else st = mid;
		}
		if(end == n || arr[end] != target) return -1;
		return end;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		arr = new int[n];
		
		for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		StringBuilder sb = new StringBuilder();
		while(m-- > 0){
			int target = Integer.parseInt(br.readLine());
			sb.append(lower_bound(target) + "\n");
		}
		System.out.println(sb);
	}
}