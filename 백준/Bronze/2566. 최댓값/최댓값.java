import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int [][] arr = new int[9][9];
		int maxAns = -1;
		int maxX = 1;
		int maxY = 1;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				arr[i][j] = scanner.nextInt();
				if(arr[i][j] > maxAns){
					maxAns = arr[i][j];
					maxX = i + 1;
					maxY = j + 1;
				}
			}
		}
		System.out.println(maxAns);
		System.out.println(maxX + " " + maxY);
	}
}