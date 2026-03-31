import java.io.*;
import java.util.*;
class Main {
	static int[][] arr, arr_copy;
	static int R,C,T,H1,H2,ans;
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		arr = new int[R][C];
		for(int i = 0; i < R; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < C; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0; i < R; i++){
			if(arr[i][0] == -1){
				H1 = i;
				H2 = i+1;
				break;
			}
		}
		
		while(T-- > 0){
			phase1();
			phase2();
			copy();
		}
		cntAns();
		System.out.println(ans);
	}

	//먼지 확산
	static void phase1(){
		arr_copy = new int[R][C];
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++) {
				if(arr[i][j] == 0 || arr[i][j] == -1) continue;
				int tmp = arr[i][j] / 5;
				int cnt = 0;
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];
					if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
					if(arr[nx][ny] == -1) continue;
					arr_copy[nx][ny] += tmp;
					cnt++;
				}
				arr_copy[i][j] += arr[i][j] - (tmp * cnt);
			}
		}
	}

	//이동
	static void phase2(){
		//상단 왼쪽
		for(int i = H1-1; i > 0; i--) arr_copy[i][0] = arr_copy[i-1][0];
		
		//상단 위쪽
		for(int i = 0; i < C - 1; i++) arr_copy[0][i] = arr_copy[0][i+1];
		
		//상단 오른쪽
		for(int i = 0; i < H1; i++) arr_copy[i][C-1] = arr_copy[i+1][C-1];

		//상단 아래쪽
		for(int i = C -1; i > 0; i--) arr_copy[H1][i] = arr_copy[H1][i-1];

		//하단 왼쪽
		for(int i = H2+1; i < R-1; i++) arr_copy[i][0] = arr_copy[i+1][0];

		//하단 아래쪽
		for(int i = 0; i < C-1; i++) arr_copy[R-1][i] = arr_copy[R-1][i+1];

		//하단 오른쪽
		for(int i = R-1; i > H2; i--) arr_copy[i][C-1] = arr_copy[i-1][C-1];

		//하단 위쪽
		for(int i = C-1; i > 0; i--) arr_copy[H2][i] = arr_copy[H2][i-1];
	}

	static void copy(){
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++) {
				if(arr[i][j] == -1) continue;
				arr[i][j] = arr_copy[i][j];
			}
		}
	}

	static void cntAns(){
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++) {
				if(arr[i][j] == -1) continue;
				ans += arr[i][j];
			}
		}
	}
}