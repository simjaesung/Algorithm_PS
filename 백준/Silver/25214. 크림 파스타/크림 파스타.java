import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st.nextToken());
		}

		StringBuilder sb = new StringBuilder();
		sb.append("0 ");
		
		int cur_min = arr[0];
		int[] ansArr = new int[n];
		for(int i = 1; i < n; i++){
			cur_min = Math.min(cur_min, arr[i]);
			ansArr[i] = Math.max(ansArr[i-1], arr[i] - cur_min);
			sb.append(ansArr[i] + " ");
		}
		
		System.out.println(sb.toString());
	}
}