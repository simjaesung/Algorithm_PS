import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[10];
		while(n > 0){
			arr[n % 10]++;
			n /= 10;
		}
		
		int sixNine = 0;
		int remain = 0;
		for(int i = 0; i < 10; i++){
			if(i == 6 || i == 9){
				sixNine += arr[i];
				continue;
			}
			remain = Math.max(remain, arr[i]);
		}
		int ans = 0;
		if(sixNine % 2 == 1){
			ans = Math.max(remain, (sixNine / 2) + 1);
		}else ans = Math.max(remain, (sixNine / 2));
		
		System.out.print(ans);
	}
}