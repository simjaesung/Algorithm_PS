import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int r = Integer.parseInt(st.nextToken());
			char[] arr = st.nextToken().toCharArray();
			
			StringBuilder sb = new StringBuilder();
			for(char c : arr){
				for(int i = 0; i < r; i++){
					sb.append(c);
				}
			}
			System.out.println(sb.toString());
		}
	}
}