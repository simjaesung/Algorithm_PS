import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		char[][] charArr = new char[n][m];
		
		for(int i = 0; i < n; i++){
			String s = br.readLine();
			char[] tmpArr = s.toCharArray();
			for(int j = 0; j < m; j++)
				charArr[i][j] = tmpArr[j];
		}
		
		int ans = 2500;
		
		for(int i = 0; i < n - 7; i++){
			for(int j = 0; j < m - 7; j++){
				int tmpMin = Math.min(checkWBVer1(charArr, i, j),checkWBVer2(charArr, i, j));
				ans = Math.min(ans,tmpMin);
			}
		}
		
		System.out.println(ans);
	}
	
	public static int checkWBVer1(char[][] arr, int x, int y){
		int cnt = 0;
		for(int i = x; i < x + 8; i++){
			for(int j = y; j < y + 8; j++){
				if(i % 2 == 0 && j % 2 == 1){
					if(arr[i][j] != 'W') cnt++;
				}else if(i % 2 == 0 && j % 2 == 0){
					if(arr[i][j] != 'B') cnt++;
				}else if(i % 2 == 1 && j % 2 == 0){
					if(arr[i][j] != 'W') cnt++;
				}else{
					if(arr[i][j] != 'B') cnt++;
				}
			}
		}
		return cnt;
	}
	
	public static int checkWBVer2(char[][] arr, int x, int y){
		int cnt = 0;
		for(int i = x; i < x + 8; i++){
			for(int j = y; j < y + 8; j++){
				if(i % 2 == 0 && j % 2 == 1){
					if(arr[i][j] != 'B') cnt++;
				}else if(i % 2 == 0 && j % 2 == 0){
					if(arr[i][j] != 'W') cnt++;
				}else if(i % 2 == 1 && j % 2 == 0){
					if(arr[i][j] != 'B') cnt++;
				}else{
					if(arr[i][j] != 'W') cnt++;
				}
			}
		}
		return cnt;
	}
}