import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int n = s.length();
		boolean isP = true;
		
		for(int i = 0; i < n / 2; i++){
			if(s.charAt(i) != s.charAt(n - 1 - i)) {
				isP = false;
				break;
			}
		}
	
		if(isP) System.out.println(1);
		else System.out.println(0);
	}
}