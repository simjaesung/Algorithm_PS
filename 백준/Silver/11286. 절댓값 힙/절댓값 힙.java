import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		PriorityQueue<Integer>pq = new PriorityQueue<>((a,b) -> {
			if(Math.abs(a) == Math.abs(b)) return a - b;
			return Math.abs(a) - Math.abs(b);
		});
		while(n-- > 0){
			int val = Integer.parseInt(br.readLine());
			if(val == 0){
				if(pq.isEmpty()) sb.append(0 + "\n");
				else sb.append(pq.poll() + "\n");
			}else pq.offer(val);
		}
		System.out.println(sb);
	}
}