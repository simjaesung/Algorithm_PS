import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		Map<String,Integer> m1 = new HashMap<>();
		Map<Integer,String> m2 = new HashMap<>();

		for(int i = 1; i <= n; i++){
			String s = br.readLine();
			m1.put(s,i);
			m2.put(i,s);
		}

		StringBuilder sb = new StringBuilder();
		
		while(m-- > 0){
			String s = br.readLine();
			if(m1.containsKey(s)){
				sb.append(m1.get(s) + "\n");
				continue;
			}else sb.append(m2.get(Integer.parseInt(s)) + "\n");
		}
		System.out.print(sb);
	}
}