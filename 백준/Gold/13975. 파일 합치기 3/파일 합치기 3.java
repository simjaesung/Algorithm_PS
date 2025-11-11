import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(t-- > 0){
			PriorityQueue<Long> pq = new PriorityQueue<>((a,b) -> Long.compare(a,b));
			int k = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(k-- > 0) pq.offer(Long.parseLong(st.nextToken()));

			long cost = 0;
			while(pq.size() > 1){
				long c1 = pq.poll();
				long c2 = pq.poll();
				cost += c1 + c2;
				pq.offer(c1 + c2);
			}
			sb.append(cost + "\n");
		}
		System.out.println(sb);
	}
}