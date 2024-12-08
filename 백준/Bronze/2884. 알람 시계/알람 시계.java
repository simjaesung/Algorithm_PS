import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int h = scanner.nextInt();
		int m = scanner.nextInt();
		if(m >= 45) m -= 45;
		else{
			m = 60 - (45- m);
			h--;
			if(h < 0) h = 23;
		}
		System.out.print(h + " " + m);
	}
}