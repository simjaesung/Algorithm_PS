import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		
		while(n-- > 0){
			st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			String b = st.nextToken();

			int[] arr = new int[26];

			for(char c : a.toCharArray()) arr[c - 'a']++;
			for(char c : b.toCharArray()) arr[c - 'a']--;

			boolean check = true;
			
			for(int i : arr){
				if(i != 0) {
					check = false;
					break;
				}
			}

			if(check) sb.append("Possible\n");
			else sb.append("Impossible\n");
		}
		
		System.out.println(sb);
	}
}