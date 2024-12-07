import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n];
		
		for(int i = 0; i<n; i++) 
			arr[i] = scanner.nextInt();
		
		int v = scanner.nextInt();
		int ans = 0;
		for(int i = 0; i<n; i++) 
			if(arr[i] == v) ans++;
		
		System.out.println(ans);
	}
}