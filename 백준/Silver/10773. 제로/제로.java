import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		Stack<Integer> s = new Stack<>();
		int k = Integer.parseInt(br.readLine());
		
		while(k-- > 0){
			int val = Integer.parseInt(br.readLine());
			if(val == 0){
				if(!s.empty()) s.pop();
			}else{
				s.push(val);
			}
		}
		
		int ans = 0;
		while(!s.empty()){
			ans += s.pop();
		}
		System.out.println(ans);
	}
}