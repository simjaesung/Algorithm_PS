import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(n-- > 0){
			String s = br.readLine();
			Deque<Character> dq = new ArrayDeque<>();
			
			for(char c : s.toCharArray()){
				if(c == '(') dq.addLast(c);
				else{
					if(!dq.isEmpty() && dq.getLast() == '(') dq.removeLast();
					else dq.addLast(c);
				}
			}

			if(dq.isEmpty()) sb.append("YES\n");
			else sb.append("NO\n");
		}
		System.out.print(sb);
	}
}