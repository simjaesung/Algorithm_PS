import java.io.*;
import java.util.*;
class Main {
	static int n,m,ans;
	static int[][] arr;
	static List<Pair> cctv = new ArrayList<>();
	static class Pair{
		int x; int y; int cctv;
		public Pair(int x, int y,int cctv){
			this.x = x; this.y = y; this.cctv = cctv;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ans = n * m;
		int[][] arr = new int[n][m];
		
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] != 0 && arr[i][j] != 6) {
					cctv.add(new Pair(i,j,arr[i][j]));
				}
			}
		}
		go(arr, 0);
		System.out.println(ans);
	}

	static void go(int[][] arr, int idx){
		if(idx == cctv.size()) {
			int cnt = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++) if(arr[i][j] == 0) cnt++;
			}
			ans = Math.min(ans, cnt);
			return;
		}
		
		int cctvX = cctv.get(idx).x;
		int cctvY = cctv.get(idx).y;
		int cctvNum = cctv.get(idx).cctv;

		if(cctvNum == 1){
			for(int i = 0; i < 4; i++){
				cctv1(arr,cctvX,cctvY,i,false);
				go(arr, idx + 1);
				cctv1(arr,cctvX,cctvY,i,true);
			}
		}else if(cctvNum == 2){
			for(int i = 0; i < 2; i++){
				cctv2(arr,cctvX,cctvY,i,false);
				go(arr, idx + 1);
				cctv2(arr,cctvX,cctvY,i,true);
			}
		}else if(cctvNum == 3){
			for(int i = 0; i < 4; i++){
				cctv3(arr,cctvX,cctvY,i,false);
				go(arr, idx + 1);
				cctv3(arr,cctvX,cctvY,i,true);
			}
		}else if(cctvNum == 4){
			for(int i = 0; i < 4; i++){
				cctv4(arr,cctvX,cctvY,i,false);
				go(arr, idx + 1);
				cctv4(arr,cctvX,cctvY,i,true);
			}
		}else if(cctvNum == 5){
			cctv5(arr,cctvX,cctvY,false);
			go(arr, idx + 1);
			cctv5(arr,cctvX,cctvY,true);
		}
	}

	static void cctv1(int[][] arr, int cctvX, int cctvY, int dir, boolean isRecover){
		if(dir == 0) detected(arr, cctvX, cctvY, 0, isRecover);
		else if(dir == 1) detected(arr, cctvX, cctvY, 1, isRecover);
		else if(dir == 2) detected(arr, cctvX, cctvY, 2, isRecover);
		else if(dir == 3) detected(arr, cctvX, cctvY, 3, isRecover);
	}

	static void cctv2(int[][] arr, int cctvX, int cctvY,int dir, boolean isRecover){
		if(dir == 0){
			detected(arr, cctvX, cctvY, 0, isRecover);
			detected(arr, cctvX, cctvY, 1, isRecover);
		}else if(dir == 1){
			detected(arr, cctvX, cctvY, 2, isRecover);
			detected(arr, cctvX, cctvY, 3, isRecover);
		}
	}

	static void cctv3(int[][] arr, int cctvX, int cctvY,int dir, boolean isRecover){
		if(dir == 0){
			detected(arr, cctvX, cctvY, 2, isRecover);
			detected(arr, cctvX, cctvY, 0, isRecover);
		}else if(dir == 1){
			detected(arr, cctvX, cctvY, 0, isRecover);
			detected(arr, cctvX, cctvY, 3, isRecover);
		}
		else if(dir == 2){
			detected(arr, cctvX, cctvY, 3, isRecover);
			detected(arr, cctvX, cctvY, 1, isRecover);
		}
		else if(dir == 3){
			detected(arr, cctvX, cctvY, 1, isRecover);
			detected(arr, cctvX, cctvY, 2, isRecover);
		}
	}

	static void cctv4(int[][] arr, int cctvX, int cctvY,int dir, boolean isRecover){
		if(dir == 0){
			detected(arr, cctvX, cctvY, 2, isRecover);
			detected(arr, cctvX, cctvY, 0, isRecover);
			detected(arr, cctvX, cctvY, 3, isRecover);
		}else if(dir == 1){
			detected(arr, cctvX, cctvY, 0, isRecover);
			detected(arr, cctvX, cctvY, 3, isRecover);
			detected(arr, cctvX, cctvY, 1, isRecover);
		}
		else if(dir == 2){
			detected(arr, cctvX, cctvY, 3, isRecover);
			detected(arr, cctvX, cctvY, 1, isRecover);
			detected(arr, cctvX, cctvY, 2, isRecover);
		}
		else if(dir == 3){
			detected(arr, cctvX, cctvY, 1, isRecover);
			detected(arr, cctvX, cctvY, 2, isRecover);
			detected(arr, cctvX, cctvY, 0, isRecover);
		}
	}

	static void cctv5(int[][] arr, int cctvX, int cctvY,boolean isRecover){
		detected(arr, cctvX, cctvY, 0, isRecover);
		detected(arr, cctvX, cctvY, 1, isRecover);
		detected(arr, cctvX, cctvY, 2, isRecover);
		detected(arr, cctvX, cctvY, 3, isRecover);
	}

	static void detected(int[][] arr, int cctvX, int cctvY, int dir, boolean isRecover){
		if(dir == 0){ //우
			for(int i = cctvY; i < m; i++){
				if(arr[cctvX][i] == 6) break;
				if(arr[cctvX][i] <= 0){
					if(isRecover) arr[cctvX][i]++;
					else arr[cctvX][i]--;
				}
			}
		}else if(dir == 1){ //좌
			for(int i = cctvY; i >=0; i--){
				if(arr[cctvX][i] == 6) break;
				if(arr[cctvX][i] <= 0){
					if(isRecover) arr[cctvX][i]++;
					else arr[cctvX][i]--;
				}
			}
		}else if(dir == 2){ //상
			for(int i = cctvX; i >= 0; i--){
				if(arr[i][cctvY] == 6) break;
				if(arr[i][cctvY] <= 0){
					if(isRecover) arr[i][cctvY]++;
					else arr[i][cctvY]--;
				}
			}
		}else if(dir == 3){ //하
			for(int i = cctvX; i < n; i++){
				if(arr[i][cctvY] == 6) break;
				if(arr[i][cctvY] <= 0) {
					if(isRecover) arr[i][cctvY]++;
					else arr[i][cctvY]--;
				}
			}
		}
	}
}