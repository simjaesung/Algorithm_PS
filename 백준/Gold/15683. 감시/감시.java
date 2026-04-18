import java.io.*;
import java.util.*;

class Main {
	static int n,m,ans;
	static int[][] arr;
	static List<int[]> cctvs = new ArrayList<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		ans = n * m;
		arr = new int[n][m];
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if(arr[i][j] != 0 && arr[i][j] != 6) cctvs.add(new int[]{i,j});
			}
		}

		go(0);
		System.out.println(ans);
	}

	static void go(int idx){
		if(idx == cctvs.size()){
			int cnt = 0;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++) {
					if(arr[i][j] == 0) cnt++;
				}
			}
			ans = Math.min(ans, cnt);
			return;
		} 

		int x = cctvs.get(idx)[0];
		int y = cctvs.get(idx)[1];
		int cctvNums = arr[x][y];

		if(cctvNums == 1){
			upWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			
			downWorker(x,y,false);
			go(idx + 1);
			downWorker(x,y,true);
			
			leftWorker(x,y,false);
			go(idx + 1);
			leftWorker(x,y,true);
			
			rightWorker(x,y,false);
			go(idx + 1);
			rightWorker(x,y,true);
			
		}else if(cctvNums == 2){
			upWorker(x,y,false);
			downWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			downWorker(x,y,true);

			leftWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			leftWorker(x,y,true);
			rightWorker(x,y,true);
		}else if(cctvNums == 3){
			//상우
			upWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			rightWorker(x,y,true);

			//우하
			downWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			downWorker(x,y,true);
			rightWorker(x,y,true);

			//하좌
			downWorker(x,y,false);
			leftWorker(x,y,false);
			go(idx + 1);
			downWorker(x,y,true);
			leftWorker(x,y,true);

			//좌상
			upWorker(x,y,false);
			leftWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			leftWorker(x,y,true);
		}else if(cctvNums == 4){
			//상좌우
			upWorker(x,y,false);
			leftWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			leftWorker(x,y,true);
			rightWorker(x,y,true);

			//상우하
			upWorker(x,y,false);
			downWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			downWorker(x,y,true);
			rightWorker(x,y,true);

			//좌하우
			downWorker(x,y,false);
			leftWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			downWorker(x,y,true);
			leftWorker(x,y,true);
			rightWorker(x,y,true);

			//하좌상
			upWorker(x,y,false);
			downWorker(x,y,false);
			leftWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			downWorker(x,y,true);
			leftWorker(x,y,true);
		}else if(cctvNums == 5){
			upWorker(x,y,false);
			downWorker(x,y,false);
			leftWorker(x,y,false);
			rightWorker(x,y,false);
			go(idx + 1);
			upWorker(x,y,true);
			downWorker(x,y,true);
			leftWorker(x,y,true);
			rightWorker(x,y,true);
		}
	}


	//위쪽 감시
	static void upWorker(int x, int y, boolean isRecover){
		while(x >= 0){
			if(arr[x][y] == 6) break;
			if(arr[x][y] <= 0) {
				if(!isRecover) arr[x][y]--;
				else {
					if(arr[x][y] != 0) arr[x][y]++;
				}
			}
			x--;
		}
	}

	static void downWorker(int x, int y, boolean isRecover){
		while(x < n){
			if(arr[x][y] == 6) break;
			if(arr[x][y] <= 0) {
				if(!isRecover) arr[x][y]--;
				else {
					if(arr[x][y] != 0) arr[x][y]++;
				}
			}
			x++;
		}
	}

	static void leftWorker(int x, int y, boolean isRecover){
		while(y >= 0){
			if(arr[x][y] == 6) break;
			if(arr[x][y] <= 0) {
				if(!isRecover) arr[x][y]--;
				else {
					if(arr[x][y] != 0) arr[x][y]++;
				}
			}
			y--;
		}
	}

	static void rightWorker(int x, int y, boolean isRecover){
		while(y < m){
			if(arr[x][y] == 6) break;
			if(arr[x][y] <= 0) {
				if(!isRecover) arr[x][y]--;
				else {
					if(arr[x][y] != 0) arr[x][y]++;
				}
			}
			y++;
		}
	}
}