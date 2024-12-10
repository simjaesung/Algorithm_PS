import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		Map<String,Integer> map = new HashMap<>();
		while(n-- > 0){
			StringTokenizer st1 = new StringTokenizer(br.readLine());
			map.put(st1.nextToken(),1);
		}
		
		int ans = 0;
		
		while(m-- >0){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			if(map.containsKey(st2.nextToken())) ans++;
		}
		
		System.out.println(ans);
	}
}