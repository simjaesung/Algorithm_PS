import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[][] arr = new int[100][100];
		for(int i = 0; i < 3; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 3; j++){
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	
		int maxR = 3, maxC = 3;
		int ans = 0;

		while(ans < 100){
			if(arr[r-1][c-1] == k) break;
			int[][] arrCopy = new int[100][100];
			if(maxR >= maxC){ //R연산
				for(int i = 0; i < maxR; i++){
					Map<Integer, Integer> map = new HashMap<>();
					for(int j = 0; j < maxC; j++){
						if(arr[i][j] == 0) continue;
						map.put(arr[i][j], map.getOrDefault(arr[i][j], 0) + 1);
					}

					List<int[]> list = new ArrayList<>();
					for(var valCnt : map.entrySet()){
						list.add(new int[]{valCnt.getKey(), valCnt.getValue()});
					}

					Collections.sort(list, (a,b) -> {
						if(a[1] == b[1]) return a[0] - b[0];
						return a[1] - b[1];
					});

					int len = Math.min(50, list.size());
					for(int l = 0; l < len; l++){
						arrCopy[i][l * 2] = list.get(l)[0];
						arrCopy[i][l * 2+1] = list.get(l)[1];
					}
					
					maxC = Math.max(maxC, len * 2);
				}
			}else{ //C연산
				for(int i = 0; i < maxC; i++){
					Map<Integer, Integer> map = new HashMap<>();
					for(int j = 0; j < maxR; j++){
						if(arr[j][i] == 0) continue;
						map.put(arr[j][i], map.getOrDefault(arr[j][i], 0) + 1);
					}

					List<int[]> list = new ArrayList<>();
					for(var valCnt : map.entrySet()){
						list.add(new int[]{valCnt.getKey(), valCnt.getValue()});
					}

					Collections.sort(list, (a,b) -> {
						if(a[1] == b[1]) return a[0] - b[0];
						return a[1] - b[1];
					});

					int len = Math.min(50, list.size());
					for(int l = 0; l < len; l++){
						arrCopy[l * 2][i] = list.get(l)[0];
						arrCopy[l * 2+1][i] = list.get(l)[1];
					}
					maxR = Math.max(maxR, len * 2);
				}
			}

			for(int i = 0; i < 100; i++){
				for(int j = 0; j < 100; j++) arr[i][j] = arrCopy[i][j];
			}
			ans++;
		}

		if(arr[r-1][c-1] != k) System.out.println(-1);
		else System.out.println(ans);
	}
}