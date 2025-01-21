import java.io.*;
import java.util.*;

class Main {
	public static StringBuffer sb = new StringBuffer();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			if(e - c == r) sb.append("does not matter\n");
			else if(e - c > r) sb.append("advertise\n");
			else sb.append("do not advertise\n");
		}
		
		System.out.println(sb.toString());
	}
}