import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		Map<String, Integer> map;
        
		while(t-- > 0){
			map = new HashMap<>();
			int n = Integer.parseInt(br.readLine());
			while(n-- > 0){
				StringTokenizer st = new StringTokenizer(br.readLine());
				String s1 = st.nextToken();
				String s2 = st.nextToken();
				map.put(s2, map.getOrDefault(s2, 0) + 1);
			}
            
			int ans = 1;
			for(int val : map.values()){
				ans *= (val + 1);
			}
			sb.append((ans - 1) + "\n");
		}
		System.out.println(sb);
	}
}