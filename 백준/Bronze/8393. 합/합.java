import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int sum = 0;
		for(int i = 1; i <= n; i++)
			sum += i;
		System.out.println(sum);
	}
}