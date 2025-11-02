import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		PriorityQueue<Integer>pq = new PriorityQueue<>((a,b) -> b - a);
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