import java.io.*;
import java.util.*;

class Main {
	static int INF = Integer.MAX_VALUE / 2;
	static int[][] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		arr = new int[n+1][n+1];
		for(int i = 1; i <= n; i++){
			Arrays.fill(arr[i], INF);
			arr[i][i] = 0;
		}

		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int t = Integer.parseInt(st.nextToken());
			arr[a][b] = t;
		}

		for(int k = 1; k <= n; k++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}

		int k = Integer.parseInt(br.readLine());
		int[] city = new int[k+1];
		st = new StringTokenizer(br.readLine());
		for(int i = 1; i <= k; i++) city[i] = Integer.parseInt(st.nextToken());

		ArrayList<Integer> ans = new ArrayList<>();
		
		int minDist = INF;
		for(int i = 1; i <= n; i++){
			boolean check = true;
			int maxDist = 0;
			for(int j = 1; j <= k; j++){
				if(arr[i][city[j]] == INF || arr[city[j]][i] == INF) {
					check = false;
					break; //갈수없는 도시
				}
				maxDist = Math.max(arr[i][city[j]] + arr[city[j]][i], maxDist);
			}
			
			if(check) {
				if(minDist == maxDist) ans.add(i);
				if(minDist > maxDist){
					ans = new ArrayList<>();
					ans.add(i);
					minDist = maxDist;
				}
			}
		}
		for(int meetCity : ans) System.out.print(meetCity + " ");
	}
}