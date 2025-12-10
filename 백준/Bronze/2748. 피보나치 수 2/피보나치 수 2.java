import java.io.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long[] fibo = new long[95];
		fibo[1] = 1;
		for(int i = 2; i <= 90; i++) fibo[i] = fibo[i-1] + fibo[i-2];

		int n = Integer.parseInt(br.readLine());
		System.out.println(fibo[n]);
	}
}