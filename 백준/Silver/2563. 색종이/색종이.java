import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] arr = new int[100][100];
		
		for(int i = 0; i<n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			for(int j = a; j < a + 10; j++){
				for(int k = b; k < b + 10; k++) 
					arr[j][k] = 1;
			}
		}
		
		int ans = 0;
		for(int j = 0; j < 100; j++){
			for(int k = 0; k < 100; k++) 
				if(arr[j][k] == 1) ans++;
		}
		System.out.println(ans);
	}
}