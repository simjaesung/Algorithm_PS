import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		char c; int val;
		public Pair(char c, int val){
			this.c = c; this.val = val;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		char[] arr = input.toCharArray();
		int n = arr.length;
		
		Deque<Pair>stack = new ArrayDeque<>();
		
		for(int i = 0; i < n; i++){
			if(arr[i] == '(') stack.addLast(new Pair('(', 0));
			else if(arr[i] == '[') stack.addLast(new Pair('[', 0));
			else{
				//비어있는 경우
				if(stack.isEmpty()){
					System.out.println(0);
					return;
				}

				//0이(여는 기호) 나올때까지 합산
				int sum = 0;
				while(!stack.isEmpty() && stack.getLast().val != 0){
					Pair top = stack.removeLast();
					sum += top.val;
				}
				
				//기호 위배의 경우
				if(stack.isEmpty() || (arr[i] == ')' && stack.getLast().c != '(') || 
					 (arr[i] == ']' && stack.getLast().c != '[')){
					System.out.println(0);
					return;
				}
				
				stack.removeLast();
				if(sum == 0) {
					if(arr[i] == ']') stack.addLast(new Pair(arr[i], 3));
					else stack.addLast(new Pair(arr[i], 2));
				} else {
					if(arr[i] == ']') stack.addLast(new Pair(arr[i], sum * 3));
					else stack.addLast(new Pair(arr[i], sum * 2));
				}
			}
		}

		int ans = 0;
		while(!stack.isEmpty()) {
			Pair cur = stack.removeLast();
			if(cur.c == '(' || cur.c == '['){
				System.out.println(0);
				return;
			}
			ans += cur.val;
		}
		System.out.println(ans);
	}
}