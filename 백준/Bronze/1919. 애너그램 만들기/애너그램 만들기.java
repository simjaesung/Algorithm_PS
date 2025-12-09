import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();

		int[] cnt = new int[26];
		for(char c : a.toCharArray()) cnt[c - 'a']++;
		for(char c : b.toCharArray()) cnt[c - 'a']--;

		int ans = 0;
		for(int k : cnt) ans += Math.abs(k);
		
		System.out.print(ans);
	}
}