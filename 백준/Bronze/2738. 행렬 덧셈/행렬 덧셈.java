import java.util.Scanner;

class Main {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		
		int[][] A = new int[n][m];
		int[][] B = new int[n][m];
		
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				A[i][j] = scanner.nextInt();
			}
		}
		
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				B[i][j] = scanner.nextInt();
			}
		}
		
		for(int i = 0; i<n; i++){
			for(int j = 0; j<m; j++){
				System.out.print(A[i][j] + B[i][j] + " ");
			}
			System.out.println();
		}
			
	}
}