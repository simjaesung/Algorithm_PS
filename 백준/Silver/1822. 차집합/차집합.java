import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[] A = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) A[i] = Integer.parseInt(st.nextToken());
		
		int[] B = new int[m];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++) B[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(B);
		
		
		List<Integer> ans = new ArrayList<>();
		for(int i = 0; i < n; i++) if(Arrays.binarySearch(B,A[i]) < 0) ans.add(A[i]);

		if(ans.isEmpty()) System.out.println(0);
		else{
			Collections.sort(ans);
			StringBuilder sb = new StringBuilder();
			sb.append(ans.size() + "\n");
			for(int k : ans) sb.append(k + " ");
			System.out.println(sb);
		}
	}
}