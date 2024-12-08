import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		for(int i = 1; i < 10; i++)
			System.out.println(a + " * " + i + " = " + a * i);
	}
}