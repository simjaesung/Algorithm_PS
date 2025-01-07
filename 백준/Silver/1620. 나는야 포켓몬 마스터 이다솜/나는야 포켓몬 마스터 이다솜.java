import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Map<String,String>map = new HashMap<>();
		
		for(int i = 1; i <= n; i++){
			StringTokenizer st2 = new StringTokenizer(br.readLine());
			String s = st2.nextToken();
			map.put(s,i+"");
			map.put(i+"",s);
		}
		
		StringBuffer sb = new StringBuffer();
		
		while(m-- > 0){
			StringTokenizer st3 = new StringTokenizer(br.readLine());
			sb.append(map.get(st3.nextToken()) + "\n");
		}
		System.out.println(sb.toString());
	}
}