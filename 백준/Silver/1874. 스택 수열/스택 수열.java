import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Deque<Integer> stack = new ArrayDeque<>();
		StringBuilder sb = new StringBuilder();
		
		int val = 1;
		
		while(n-- > 0){
			int k = Integer.parseInt(br.readLine());
			while(val <= k){
				stack.push(val++);
				sb.append("+\n");
			}
			
			if(stack.peek() == k){
				stack.pop();
				sb.append("-\n");
			}
		}
		
		if(stack.isEmpty()) System.out.println(sb.toString());
		else System.out.println("NO");
	}
}