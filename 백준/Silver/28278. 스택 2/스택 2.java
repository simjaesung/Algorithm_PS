import java.util.*;
import java.io.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		Stack<Integer> s = new Stack<>();
		
		int n = Integer.parseInt(br.readLine());
		
		while(n-- > 0){
			st = new StringTokenizer(br.readLine());
			int opt = Integer.parseInt(st.nextToken());
			
			if(opt == 1) {
				s.push(Integer.parseInt(st.nextToken()));
			}else if(opt == 2){
				if(s.empty()) System.out.println(-1);
				else{
					int top = s.pop();
					System.out.println(top);
				}
			}else if(opt == 3){
				System.out.println(s.size());
			}else if(opt == 4){
				if(s.empty()) System.out.println(1);
				else System.out.println(0);
			}else{
				if(s.empty()) System.out.println(-1);
				else System.out.println(s.peek());
			}
		}
	}
}