import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int[] belt = new int[n*2];
		for(int i = 0; i < n*2; i++) belt[i] = Integer.parseInt(st.nextToken());

		boolean[] robot = new boolean[n];

		int phase = 0;
		int start = 0;
		while(true){
			phase++;
			start = (start - 1 + 2*n) % (2*n);
			for(int i = n-1; i > 0; i--) robot[i] = robot[i-1];
			robot[n-1] = false;
			robot[0] = false;

			for(int i = n-1; i > 0; i--){
				if(!robot[i] && robot[i-1] && belt[(start + i) % (2*n)] > 0){
					robot[i-1] = false;
					robot[i] = true;
					belt[(start + i) % (2*n)]--;
				}
			}
			robot[n-1] = false;

			if(belt[start] > 0){
				belt[start]--;
				robot[0] = true;
			}
			
			int cnt = 0;
			for(int nagu : belt) if(nagu == 0) cnt++;
			if(cnt >= k) break;
		}
		
		System.out.println(phase);
	}
}