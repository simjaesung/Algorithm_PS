import java.io.*;
import java.util.*;

class Main {
	static int[] lc;
	static int[] rc;
	static StringBuilder sb = new StringBuilder();

	static void pre(int x){
		sb.append((char)('A' + x - 1));
		if(lc[x] != 0) pre(lc[x]);
		if(rc[x] != 0) pre(rc[x]);
	}

	static void in(int x){
		if(lc[x] != 0) in(lc[x]);
		sb.append((char)('A' + x - 1));
		if(rc[x] != 0) in(rc[x]);
	}

	static void post(int x){
		if(lc[x] != 0) post(lc[x]);
		if(rc[x] != 0) post(rc[x]);
		sb.append((char)('A' + x - 1));
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		lc = new int[n+1];
		rc = new int[n+1];

		for(int i = 1; i <= n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int node = st.nextToken().charAt(0) - 'A' + 1;
			String left = st.nextToken();
			String right = st.nextToken();
			if(!left.equals(".")) lc[node] = left.charAt(0) - 'A' + 1;
			if(!right.equals(".")) rc[node] = right.charAt(0) - 'A' + 1;
		}

		pre(1); sb.append("\n");
		in(1); sb.append("\n");
		post(1);
		
		System.out.println(sb);
	}
}