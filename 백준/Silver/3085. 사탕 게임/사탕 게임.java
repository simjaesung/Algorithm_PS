import java.io.*;

class Main {
	public static char[][] arr = new char[55][55];
	public static char[][] copyArr = new char[55][55];
	public static int n;
	public static int ans;
	
	public static boolean inRange(int x, int y){
		return x >= 0 && x < n && y >= 0 && y < n;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n; i++){
			String s = br.readLine();
			for(int j = 0; j < n; j++){
				arr[i][j] = s.charAt(j);
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				change(i,j);
			}
		}
		
		System.out.println(ans);
	}
	
	public static void change(int x, int y){
		for(int i = 0; i < 4; i++){
			copyingArr();
			//동
			if(i == 0 && inRange(x, y + 1)){
				swapArr(x,y,x,y+1);
			}
			//서
			else if(i == 1 && inRange(x, y - 1)){
				swapArr(x,y,x,y-1);
			}
			//남
			else if(i == 2 && inRange(x + 1, y)){
				swapArr(x,y,x+1,y);
			}
			//북
			else if(i == 3 && inRange(x - 1, y)){
				swapArr(x,y,x-1,y);
			}
			findMax();
		}
	}
	
	public static void copyingArr(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				copyArr[i][j] = arr[i][j];
			}
		}
	}
	
	public static void swapArr(int cx, int cy, int nx, int ny){
		char tmp = copyArr[cx][cy];
		copyArr[cx][cy] = copyArr[nx][ny];
		copyArr[nx][ny] = tmp;
	}
	
	public static void findMax(){
		int[] dp = new int[n];
		dp[0] = 1;
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j < n; j++){
				if(copyArr[i][j] == copyArr[i][j-1]){
					dp[j] = dp[j-1] + 1;
				}else {
					dp[j] = 1;
				}
			}
			
			for(int k : dp){
				ans = Math.max(ans,k);
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j < n; j++){
				if(copyArr[j][i] == copyArr[j-1][i]){
					dp[j] = dp[j-1] + 1;
				} else {
					dp[j] = 1;
				}
			}
			
			for(int k : dp){
				ans = Math.max(ans,k);
			}
		}
	}
}