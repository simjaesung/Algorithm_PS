import java.io.*;
class Main {
	static int n, ans;
	static int[][] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		go(0);
		System.out.println(ans);
	}

	static void go(int h){
		if(h == n) {
			ans++;
			return;
		}

		for(int i = 0; i < n; i++){
			if(!sameSero(h,i)) continue;
			if(!sameCross(h,i)) continue;
			arr[h][i] = 1;
			go(h + 1);
			arr[h][i] = 0;
		}
	}

	static boolean sameSero(int h, int k){
		for(int i = 0; i < h; i++){
			if(arr[i][k] == 1) return false;
		}
		return true;
	}

	static boolean sameCross(int i, int j){
		int i1 = i; int j1 = j;
		while(i1 < n && j1 < n){
			if(arr[i1][j1] == 1) return false;
			i1++; j1++;
		}

		int i2 = i; int j2 = j;
		while(i2 >= 0 && j2 >= 0){
			if(arr[i2][j2] == 1) return false;
			i2--; j2--;
		}

		int i3 = i; int j3 = j;
		while(i3 >=0 && j3 < n){
			if(arr[i3][j3] == 1) return false;
			i3--; j3++;
		}

		int i4 = i; int j4 = j;
		while(i4 < n && j4 >= 0){
			if(arr[i4][j4] == 1) return false;
			i4++; j4--;
		}
		return true;
	}
}