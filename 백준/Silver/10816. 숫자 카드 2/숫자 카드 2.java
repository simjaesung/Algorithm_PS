import java.io.*;
import java.util.*;

class Main {
	public static int lower_bound(int target, int[] arr){
		int st = -1;
		int end = arr.length;

		while(st + 1 < end){
			int mid = st + (end - st) / 2;
			if(arr[mid] >= target) end = mid;
			else st = mid;
		}
		return end;
	}

	public static int upper_bound(int target, int[] arr){
		int st = -1;
		int end = arr.length;

		while(st + 1 < end){
			int mid = st + (end - st) / 2;
			if(arr[mid] > target) end = mid;
			else st = mid;
		}
		return end;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);

		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());

		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < m; i++) {
			int val = Integer.parseInt(st.nextToken());
			int lower = lower_bound(val, arr);
			int upper = upper_bound(val, arr);
			sb.append(upper - lower + " ");
		}
		System.out.println(sb);
	}
}