import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0){
			String s = br.readLine();
			System.out.println("" + s.charAt(0) + s.charAt(s.length() - 1));
		}
	}
}