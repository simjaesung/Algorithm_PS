import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] cnt = new int[10001];
		for(int i = 0; i < n; i++){
			int k = Integer.parseInt(br.readLine());
			cnt[k]++;
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i < 10001; i++) {
			while(cnt[i] > 0){
				sb.append(i + "\n");
				cnt[i]--;
			}
		}
		System.out.println(sb);
	}
}