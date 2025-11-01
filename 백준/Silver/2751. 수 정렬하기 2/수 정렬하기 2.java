import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Integer[] arr = new Integer[n];
		for(int i = 0; i < n; i++){
			Integer k = Integer.parseInt(br.readLine());
			arr[i] = k;
		}
		//Arrays.sort(arr,(a,b) -> b - a);
		Arrays.sort(arr);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++) sb.append(arr[i] + "\n");
		System.out.println(sb);
	}
}