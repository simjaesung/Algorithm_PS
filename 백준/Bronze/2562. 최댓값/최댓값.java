import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int [] arr = new int[9];
		int maxAns = 1;
		int maxIdx = 0;
		for(int i = 0; i<9; i++){
			arr[i] = scanner.nextInt();
			if(arr[i] > maxAns){
				maxAns = arr[i];
				maxIdx = i;
			}
		}
		System.out.println(maxAns);
		System.out.println(maxIdx + 1);
	}
}