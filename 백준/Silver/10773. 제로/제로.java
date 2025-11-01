import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Deque<Integer> dq = new ArrayDeque<>();
		while(n-- > 0){
			int val = Integer.parseInt(br.readLine());
			if(val == 0) dq.removeLast();
			else dq.addLast(val);
		}
		List<Integer> list = new ArrayList(dq);
		int ans = 0;
		for(int i : list) ans += i;
		System.out.print(ans);
	}
}