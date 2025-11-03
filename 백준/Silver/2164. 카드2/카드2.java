import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Deque<Integer> dq = new ArrayDeque<>();
		for(int i = 1; i <=n; i++) dq.addFirst(i);

		boolean toggle = true;
		while(dq.size() > 1){
			if(toggle) dq.removeLast();
			else dq.addFirst(dq.removeLast());
			toggle = !toggle;
		}
		System.out.println(dq.peek());
	}
}