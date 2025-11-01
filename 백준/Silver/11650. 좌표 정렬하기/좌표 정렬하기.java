import java.io.*;
import java.util.*;

class Main {
	static class loc{
		int x;
		int y;
		public loc(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		loc[] arr = new loc[n];
		for(int i = 0; i < n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			arr[i] = new loc(x,y);
		}

		Arrays.sort(arr, (a,b) -> {
			if(a.x == b.x) return a.y - b.y;
			return a.x - b.x;
		});

		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++){
			sb.append(arr[i].x + " " + arr[i].y + "\n");
		}
		
		System.out.println(sb);
	}
}