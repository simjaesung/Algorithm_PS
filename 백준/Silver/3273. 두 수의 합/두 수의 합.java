import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for(int i = 0; i < n; i++){
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int x = Integer.parseInt(br.readLine());
		
		Arrays.sort(arr);
		int left = 0, right = arr.length - 1,ans = 0;
		while(left < right){
			if(arr[left] + arr[right] < x) left++;
			else if(arr[left] + arr[right] > x) right--;
			else{
				ans++;
				left++;
				right--;
			}
		}
		System.out.print(ans);
	}
}