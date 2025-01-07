import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Map<String,String> map = new HashMap<>();
		
		while(n-- > 0){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			String s1 = st2.nextToken();
			String s2 = st2.nextToken();
			map.put(s1,s2);
		}
		
		StringBuffer sb = new StringBuffer();
		
		while(m-- > 0){
			StringTokenizer st3 = new StringTokenizer(br.readLine());
			sb.append(map.get(st3.nextToken()) + "\n");
		}
		System.out.println(sb.toString());
	}
}