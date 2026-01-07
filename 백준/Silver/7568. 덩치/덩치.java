import java.io.*;
import java.util.*;

class Main {
	static class Human{
		int x; int y;
		public Human(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Human[] arr = new Human[n];
		StringTokenizer st;
		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr[i] = new Human(x,y);
		}

		for(int i = 0; i < n; i++){
			int cnt = 0;
			int cx = arr[i].x;
			int cy = arr[i].y;
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				if(cx < arr[j].x && cy < arr[j].y) cnt++;
			}
			System.out.print(cnt+1 + " ");
		}
	}
}