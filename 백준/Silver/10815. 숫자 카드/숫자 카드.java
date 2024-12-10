import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception { 
		Map<String, Integer> map = new HashMap<>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		
		for(int i = 0; i<n; i++) map.put(st1.nextToken(),1);
		
		StringBuilder sb = new StringBuilder();
		int m = Integer.parseInt(br.readLine());
		StringTokenizer st2 = new StringTokenizer(br.readLine());
        
		for(int i = 0; i<m; i++) {
			if(map.containsKey(st2.nextToken())) sb.append("1 ");
			else sb.append("0 ");
		}
		System.out.println(sb.toString());
	}
}