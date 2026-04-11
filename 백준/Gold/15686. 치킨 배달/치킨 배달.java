import java.io.*;
import java.util.*;

class Main {
	static int n,m,ans = Integer.MAX_VALUE;
	static boolean[] used;
	static List<Pair> chicken = new ArrayList<>();
	static List<Pair> house = new ArrayList<>();

	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for(int i = 0; i < n; i++){
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++){
				int val = Integer.parseInt(st.nextToken());
				if(val == 1) house.add(new Pair(i,j));
				if(val == 2) chicken.add(new Pair(i,j));
			}
		}
		used = new boolean[chicken.size()];
		go(0,0);
		System.out.println(ans);
	}

	static void go(int k, int idx){
		if(k == m){
			int tmp = calChickenLoad();
			ans = Math.min(ans,tmp);
            return;
		}
		
		for(int i = idx; i < chicken.size(); i++){
			if(used[i]) continue;
			used[i] = true;
			go(k + 1, i + 1);
			used[i] = false;
		}
	}

	static int calChickenLoad(){
		int tmp = 0;
		for(int i = 0; i < house.size(); i++){
			int chickenLoad = 101;
			int x = house.get(i).x;
			int y = house.get(i).y;
			for(int j = 0; j < chicken.size(); j++){
				if(!used[j]) continue;
				int len = Math.abs(chicken.get(j).x - x) + Math.abs(chicken.get(j).y - y);
				chickenLoad = Math.min(chickenLoad, len);
			}
			tmp += chickenLoad;
		}
		return tmp;
	}
}