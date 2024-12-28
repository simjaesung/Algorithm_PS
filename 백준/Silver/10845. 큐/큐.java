import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Deque<String> queue = new ArrayDeque<>();
		
		while(n-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			if(cmd.equals("push")){
				queue.offer(st.nextToken());
			}else if(cmd.equals("pop")){
				if(queue.isEmpty()) System.out.println(-1);
				else System.out.println(queue.poll());
			}else if(cmd.equals("size")){
				System.out.println(queue.size());
			}else if(cmd.equals("front")){
				if(queue.isEmpty()) System.out.println(-1);
				else System.out.println(queue.peek());
			}else if(cmd.equals("back")){
				if(queue.isEmpty()) System.out.println(-1);
				else System.out.println(queue.peekLast());
			}else if(cmd.equals("empty")){
				if(queue.isEmpty()) System.out.println(1);
				else System.out.println(0);
			}
		}
	}
}