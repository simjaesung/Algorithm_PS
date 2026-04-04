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
			for(int j = 0; j < 3; j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}

		int maxR = 3; //최대 행(가로)
		int maxC = 3; //최대 열(세로)

		int cnt = 100;
		while(cnt-- > 0){ //100초가 지나도 
			if(arr[r-1][c-1] == k) break;
			int[][] arrCopy = new int[100][100];
			if(maxR >= maxC){
				for(int i = 0; i < maxR; i++){
					Set<Integer> set = new HashSet<>();
					Map<Integer,Integer> map = new HashMap<>();
					for(int j = 0; j < maxC; j++){
						if(arr[i][j] == 0) continue;
						set.add(arr[i][j]);
						map.put(arr[i][j], map.getOrDefault(arr[i][j],0) + 1);
					}
					List<Integer> setToList = new ArrayList<>(set);
					Collections.sort(setToList, (a,b) -> {
						if(map.get(a) == map.get(b)) return a - b;
						return map.get(a) - map.get(b);
					});

					int len = Math.min(50, setToList.size());
					maxC = Math.max(len * 2, maxC);
					for(int l = 0; l < len * 2; l+=2){
						arrCopy[i][l] = setToList.get(l / 2);
						arrCopy[i][l+1] = map.get(setToList.get(l / 2));
					}
				}
			}else{
				for(int i = 0; i < maxC; i++){
					Set<Integer> set = new HashSet<>();
					Map<Integer,Integer> map = new HashMap<>();

					for(int j = 0; j < maxR; j++){
						if(arr[j][i] == 0) continue;
						set.add(arr[j][i]);
						map.put(arr[j][i], map.getOrDefault(arr[j][i],0) + 1);
					}

					List<Integer> setToList = new ArrayList<>(set);
					Collections.sort(setToList, (a,b) -> {
						if(map.get(a) == map.get(b)) return a - b;
						return map.get(a) - map.get(b);
					});

					int len = Math.min(50, setToList.size());
					maxR = Math.max(maxR, len * 2);
					for(int l = 0; l < len * 2; l+=2){
						arrCopy[l][i] = setToList.get(l / 2);
						arrCopy[l+1][i] = map.get(setToList.get(l / 2));
					}
				}
			}
			arr = arrCopy;
		}

		System.out.println(arr[r-1][c-1] == k ? 100 - cnt - 1 : -1);
	}
}