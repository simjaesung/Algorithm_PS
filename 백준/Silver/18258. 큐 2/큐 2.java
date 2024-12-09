import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Deque<String> deque = new ArrayDeque<>();
		StringBuilder sb = new StringBuilder();
		
		while(n-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String option = st.nextToken();
			if(option.equals("push")){
				String val = st.nextToken();
				deque.addLast(val);
			}
			else if(option.equals("pop")){
				if(deque.isEmpty()) sb.append("-1\n");
				else sb.append(deque.pollFirst()+ "\n");
			}
			else if(option.equals("size")){
				sb.append(deque.size() + "\n");
			}
			else if(option.equals("empty")){
				if(deque.isEmpty()) sb.append("1\n");
				else sb.append("0\n");
			}
			else if(option.equals("front")){
				if(deque.isEmpty()) sb.append("-1\n");
				else sb.append(deque.peekFirst() + "\n");
			}
			else if(option.equals("back")){
				if(deque.isEmpty()) sb.append("-1\n");
				else sb.append(deque.peekLast()+"\n");
			}
			else{
				System.out.println("잘못된 입력");
			}
		}
		System.out.println(sb.toString());
	}
}