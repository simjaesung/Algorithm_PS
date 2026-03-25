import java.io.*;
import java.util.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer str = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(str.nextToken());
		int c = Integer.parseInt(str.nextToken());
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
		Arrays.sort(arr);

		int st = 1; int end = arr[n-1] - arr[0] + 1;
		while(st + 1 < end){
			int m = st + (end - st) / 2;
			int cnt = count(arr, m);
			if(cnt >= c) st = m;
			else end = m;
		}

		System.out.println(st);
	}

	public static int count(int[] arr, int dist){
		int cnt = 1;
		int last = arr[0];
		for(int i = 1; i < arr.length; i++){
			if(arr[i] - last >= dist){
				last = arr[i];
				cnt++;
			}
		}
		return cnt;
	}
}