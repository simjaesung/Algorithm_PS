import java.io.*;
import java.util.*;

class Main {
	static int r,c,t,x1,x2;
	static int[][] arr;
	static int[] dx = {-1,1,0,0};
	static int[] dy = {0,0,-1,1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(st.nextToken());
		arr = new int[r+1][c+1];
		for(int i = 1; i <= r; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= c; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] == -1){
					if(x1 == 0) x1 = i;
					else x2 = i;
				}
			}
		}

		while(t-- > 0){
			int[][] copyArr = new int[r+1][c+1];
		
			//확산
			spread(copyArr);

			//위쪽 순환(반시계)
			rotateTop(copyArr);

			//아래쪽 순환(시계)
			rotateBottom(copyArr);

			copyArr[x1][1] = -1;
			copyArr[x2][1] = -1;

			//복사
			for(int i = 1; i <= r; i++){
				for(int j = 1; j <= c; j++) {
					arr[i][j] = copyArr[i][j];
				}
			}
		}

		int ans = 0;
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++) {
				if(arr[i][j] != -1) ans += arr[i][j];
			}
		}
		
		System.out.println(ans);
	}

	static void spread(int[][] copyArr){
		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++) {
				if(arr[i][j] == 0 || arr[i][j] == -1) continue;
				int cnt = 0;
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx <= 0 || nx > r || ny <= 0 || ny > c) continue;
					if(arr[nx][ny] == -1) continue;
					copyArr[nx][ny] += arr[i][j] / 5;
					cnt++;
				}
				copyArr[i][j] += arr[i][j] - (arr[i][j] / 5) * cnt;
			}
		}
	}

	static void rotateTop(int[][] copyArr){
		int prev = copyArr[x1][2];
		copyArr[x1][2] = 0;
		for(int i = 3; i <= c; i++){
			int tmp = copyArr[x1][i];
			copyArr[x1][i] = prev;
			prev = tmp;
		}

		for(int i = x1-1; i >= 1; i--){
			int tmp = copyArr[i][c];
			copyArr[i][c] = prev;
			prev = tmp;
		}

		for(int i = c - 1; i >= 1; i--){
			int tmp = copyArr[1][i];
			copyArr[1][i] = prev;
			prev = tmp;
		}

		for(int i = 2; i < x1; i++){
			int tmp = copyArr[i][1];
			copyArr[i][1] = prev;
			prev = tmp;
		}
	}

	static void rotateBottom(int[][] copyArr){
		int prev = copyArr[x2][2];
		copyArr[x2][2] = 0;
		for(int i = 3; i <= c; i++){
			int tmp = copyArr[x2][i];
			copyArr[x2][i] = prev;
			prev = tmp;
		}

		for(int i = x2+1; i <= r; i++){
			int tmp = copyArr[i][c];
			copyArr[i][c] = prev;
			prev = tmp;
		}

		for(int i = c-1; i>=1; i--){
			int tmp = copyArr[r][i];
			copyArr[r][i] = prev;
			prev = tmp;
		}

		for(int i = r-1; i > x2; i--){
			int tmp = copyArr[i][1];
			copyArr[i][1] = prev;
			prev = tmp;
		}
	}
}