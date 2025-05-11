import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] arr = new int[42];
		for(int i = 0; i < 10; i++){
			int k = Integer.parseInt(br.readLine());
			arr[k % 42]++;
		}

		int ans = 0;
		for(int s : arr){
			if(s > 0) ans++;
		}

		System.out.print(ans);
	}
}