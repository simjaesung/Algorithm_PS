import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Map<String,Integer> map = new TreeMap<>(Collections.reverseOrder());
		
		while(n-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			String option = st.nextToken();
			
			if(option.equals("enter")) map.put(name,1);
			else map.put(name,0);
		}
		StringBuilder sb = new StringBuilder();
		
		for(String key : map.keySet()){
			if(map.get(key) == 1) sb.append(key + "\n");
		}
		
		System.out.println(sb.toString());
	}
}