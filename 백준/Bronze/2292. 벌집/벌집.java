import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int ans = 1;
		while(n - 1 > 0){
			n -= ans * 6;
			ans++;
		}
		
		System.out.println(ans);
	}
}