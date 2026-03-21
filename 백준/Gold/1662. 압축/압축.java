import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		char[] arr = s.toCharArray();
		int n = arr.length;

		Stack<Integer> stack = new Stack<>();
		
		for(int i = 0; i < n; i++){
			if(arr[i] == '('){
				stack.pop();
				stack.push(arr[i-1] - '0');
				stack.push(-1);
			}	else if(arr[i] == ')'){
				int len = 0;
				while(stack.peek() != -1){
					len += stack.pop();
				}
				stack.pop(); //'(' 삭제
				stack.push((len * (stack.pop())));
			} else stack.push(1);
		}
		
		int ans = 0;
		while(!stack.isEmpty()) ans += stack.pop();
		System.out.println(ans);
	}
}