import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Map<Integer,Integer>m = new HashMap<>();
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st1 = new StringTokenizer(br.readLine());
		while(n-- > 0){
			int k = Integer.parseInt(st1.nextToken());
			m.put(k,1);
		}
		
		StringBuilder sb = new StringBuilder();
		
		int l = Integer.parseInt(br.readLine());
		StringTokenizer st2 = new StringTokenizer(br.readLine());
		while(l-- >0){
			int k = Integer.parseInt(st2.nextToken());
			if(m.containsKey(k)) sb.append("1\n");
			else sb.append("0\n");
		}
		
		System.out.println(sb.toString());
	}
}