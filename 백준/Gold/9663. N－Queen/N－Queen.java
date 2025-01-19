import java.io.*;

class Main {
	public static int n,ans;
	public static int[][] arr = new int[15][15];
	public static boolean inRange(int x, int y){
		return x >= 0 && x < n && y >= 0 && y < n;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		nQueen(0);
		System.out.println(ans);
	}
	
	
	public static void nQueen(int l){
		if(l == n){
			ans++;
			return;
		}
		
		for(int i = 0; i < n; i++){
			if(check(l,i)){
				arr[l][i] = 1;
				nQueen(l + 1);
				arr[l][i] = 0;
			}
		}
	}
	
	public static boolean check(int x, int y){
		for(int i = 0; i < n; i++){
			if(arr[i][y] == 1) return false;
		}
		
		int x1 = x + 1;
		int y1 = y + 1;
		while(inRange(x1,y1)){
			if(arr[x1][y1] == 1) return false;
			x1++; y1++;
		}
		
		int x2 = x - 1;
		int y2 = y - 1;
		while(inRange(x2,y2)){
			if(arr[x2][y2] == 1) return false;
			x2--; y2--;
		}
		
		int x3 = x + 1;
		int y3 = y - 1;
		while(inRange(x3,y3)){
			if(arr[x3][y3] == 1) return false;
			x3++; y3--;
		}
		
		int x4 = x - 1;
		int y4 = y + 1;
		while(inRange(x4,y4)){
			if(arr[x4][y4] == 1) return false;
			x4--; y4++;
		}
		
		return true;
	}
}