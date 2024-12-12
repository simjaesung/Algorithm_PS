import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		int n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) pq.add(Integer.parseInt(st.nextToken()));
		}
		
		for(int i = 0; i < n - 1; i++) pq.poll();
		System.out.println(pq.poll());
	}
}