import java.io.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int ans = 0;

		for(int i = 0; i < n; i++){
			int k = i;
			int sum = 0;

			while(k > 0){
				sum += k % 10;
				k /= 10;
			}

			if(sum + i == n){
				ans = i;
				break;
			}
		}
		
		System.out.println(ans);
	}
}