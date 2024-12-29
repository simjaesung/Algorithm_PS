import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		Deque<Integer> deque = new ArrayDeque<>();
		for(int i = 1; i <= n; i++) deque.add(i);
		
		int ans = 0;
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < m; i++){
			int k = Integer.parseInt(st2.nextToken());
			int idx = getIndex(deque,k);
			if(idx > deque.size() / 2){
				while(deque.peekFirst() != k){
					int tmp = deque.pollLast();
					deque.offerFirst(tmp);
					ans++;
				}
			}else{
				while(deque.peekFirst() != k){
					int tmp = deque.pollFirst();
					deque.offerLast(tmp);
					ans++;
				}
			}
			deque.pollFirst();
		}
		System.out.println(ans);
	}
	
	public static int getIndex(Deque<Integer> deque, int k){
		int idx = 0;
		for(Integer i : deque){
			if(i == k) break;
			idx++;
		}
		return idx;
	}
}