import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		while(n-- > 0){
			st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			String b = st.nextToken();

			char[] aToCharArr = a.toCharArray();
			char[] bToCharArr = b.toCharArray();
			
			Arrays.sort(aToCharArr);
			Arrays.sort(bToCharArr);

			a = new String(aToCharArr);
			b = new String(bToCharArr);

			if(a.equals(b)) sb.append("Possible\n");
			else sb.append("Impossible\n");
		}
		
		System.out.println(sb);
	}
}