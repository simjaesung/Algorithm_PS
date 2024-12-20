import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		String a = st.nextToken();
		String b = st.nextToken();
		
		StringBuilder sb1 = new StringBuilder(a);
		StringBuilder sb2 = new StringBuilder(b);
		
		int A = Integer.parseInt(sb1.reverse().toString());
		int B = Integer.parseInt(sb2.reverse().toString());
		
		if(A > B) System.out.println(A);
		else System.out.println(B);
	}
}