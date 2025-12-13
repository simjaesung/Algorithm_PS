import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		s = s.toLowerCase();

		int[] cnt = new int[26];
		for(char c : s.toCharArray()) cnt[c-'a']++;

		int max_cnt = 0;
		int max_idx = 0;
		for(int i = 0; i < 26; i++){
			if(cnt[i] > max_cnt) {
				max_cnt = cnt[i];
				max_idx = i;
			}
		}

		int same_ans = 0;
		for(int i = 0; i < 26; i++){
			if(cnt[i] == max_cnt) same_ans++;
		}

		if(same_ans > 1) System.out.println("?");
		else System.out.println((char)(max_idx + 'A'));
	}
}