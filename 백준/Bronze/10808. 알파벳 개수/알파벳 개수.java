import java.io.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		char[] charArr = s.toCharArray();
		int[] cnt = new int[26];
		for(char c : charArr) cnt[c-'a']++;
		for(int i : cnt) System.out.print(i + " ");
	}
}