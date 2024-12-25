import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		double[] doubleArr = new double[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		double maxScore = 0;
		for(int i = 0; i < n; i++){
			doubleArr[i] = Integer.parseInt(st.nextToken());
			maxScore = Math.max(maxScore,doubleArr[i]);
		}
		
		double sum = 0;
		for(int i = 0; i < n; i++){
			doubleArr[i] = doubleArr[i] / maxScore * 100;
			sum += doubleArr[i];
		}
		
		System.out.println((double) sum / n);
	}
}