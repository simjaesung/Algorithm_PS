import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Deque<String> deque = new ArrayDeque<>();
		
		while(n-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			if(cmd.equals("push_front")){
				deque.offerFirst(st.nextToken());
			}else if(cmd.equals("push_back")){
				deque.offerLast(st.nextToken());
			}else if(cmd.equals("pop_front")){
				if(deque.isEmpty()) System.out.println(-1);
				else System.out.println(deque.removeFirst());
			}else if(cmd.equals("pop_back")){
				if(deque.isEmpty()) System.out.println(-1);
				else System.out.println(deque.removeLast());
			}else if(cmd.equals("size")){
				System.out.println(deque.size());
			}else if(cmd.equals("front")){
				if(deque.isEmpty()) System.out.println(-1);
				else System.out.println(deque.peek());
			}else if(cmd.equals("back")){
				if(deque.isEmpty()) System.out.println(-1);
				else System.out.println(deque.peekLast());
			}else if(cmd.equals("empty")){
				if(deque.isEmpty()) System.out.println(1);
				else System.out.println(0);
			}
		}
		
	}
}