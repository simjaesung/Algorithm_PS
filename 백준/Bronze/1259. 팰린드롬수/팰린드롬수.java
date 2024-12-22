import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		while(true){
			String s = br.readLine();
			if(s.equals("0")) break;
			if(checkP(s)) sb.append("yes\n");
			else sb.append("no\n");
		}
		System.out.println(sb.toString());
	}
	
	public static boolean checkP(String s){
		int n = s.length() / 2;
		char[] c = s.toCharArray();
		for(int i = 0; i<n; i++){
			if(c[i] != c[s.length() - 1 - i])
				return false;
		}
		return true;
	}
}