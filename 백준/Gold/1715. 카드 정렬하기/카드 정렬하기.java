import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Queue<Integer> pq = new PriorityQueue<>();
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++){
			int k = Integer.parseInt(br.readLine());
			pq.add(k);
		}
		
		long ans = 0;
		while(pq.size() > 1){
			int a = pq.poll();
			int b = pq.poll();
			ans += (a + b);
			pq.add(a + b);
		}
		System.out.println(ans);
	}
}