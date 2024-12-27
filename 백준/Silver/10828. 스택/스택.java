import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Deque<String> stack = new ArrayDeque<>();
		
		while(n-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			if(cmd.equals("push")){
				String k = st.nextToken();
				stack.push(k);
			}else if(cmd.equals("pop")){
				if(stack.isEmpty()) {
					System.out.println(-1);
				}
				else {
					System.out.println(stack.peek());
					stack.pop();
				}
			}else if(cmd.equals("size")){
				System.out.println(stack.size());
			}else if(cmd.equals("empty")){
				if(stack.isEmpty()) System.out.println(1);
				else System.out.println(0);
			}else if(cmd.equals("top")){
				if(stack.isEmpty()) System.out.println(-1);
				else System.out.println(stack.peek());
			}
		}
		
	}
}