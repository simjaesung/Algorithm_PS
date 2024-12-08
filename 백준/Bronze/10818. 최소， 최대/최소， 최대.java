import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int [] arr = new int[n];
		int minAns = 1000000;
		int maxAns = -1000000;
		for(int i = 0; i<n; i++){
			arr[i] = scanner.nextInt();
			minAns = Math.min(minAns,arr[i]);
			maxAns = Math.max(maxAns,arr[i]);
		}
		System.out.print(minAns + " " + maxAns);
	}
}