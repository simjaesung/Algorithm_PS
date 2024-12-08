import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		int n = scanner.nextInt();
		long check = 0;
		for(int i = 1; i <= n; i++){
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			check += (a * b);
		}
		
		if(check == x) System.out.println("Yes");
		else System.out.println("No");
	}
}