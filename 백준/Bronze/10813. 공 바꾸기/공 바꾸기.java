import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] arr = new int[n];
		for(int i = 1; i<=n; i++) arr[i-1] = i;
		
		while(m-- > 0){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			int i = Integer.parseInt(st2.nextToken());
			int j = Integer.parseInt(st2.nextToken());
			int tmp = arr[i-1];
			arr[i-1] = arr[j-1];
			arr[j-1] = tmp;
		}
		
		for(int i = 1; i<=n; i++) System.out.print(arr[i-1] + " ");
	}
}