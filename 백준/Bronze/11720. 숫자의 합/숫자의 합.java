import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String s = br.readLine();
		char[] arr = s.toCharArray();
		int ans = 0;
		for(char c : arr){
			ans += Character.getNumericValue(c);
		}
		System.out.print(ans);
	}
}