import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		int [] arr = new int[n];
		for(int i = 0; i<m; i++){
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			int k = scanner.nextInt();
			for(int j = a-1; j < b; j++){
				arr[j] = k;
			}
		}
		for(int i = 0; i<n; i++){
			System.out.print(arr[i] + " ");
		}
	}
}