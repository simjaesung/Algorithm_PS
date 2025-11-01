import java.io.*;
import java.util.*;

class Main {
	static int n, m;
	static int[] rece;
	static ArrayList<Integer>[] adj;

	static void input() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		rece = new int[n+1];
		adj = new ArrayList[n+1];
		for(int i = 0; i <=n; i++) adj[i] = new ArrayList<>();

		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			int l = Integer.parseInt(st.nextToken());
			ArrayList<Integer> tmpArr = new ArrayList<>();
			
			for(int i = 0; i < l; i++){
				int val = Integer.parseInt(st.nextToken());
				tmpArr.add(val);
			}

			for(int i = 0; i < l-1; i++){
				int a = tmpArr.get(i);
				int b = tmpArr.get(i+1);
				rece[b]++;
				adj[a].add(b);
			}
		}
	}
	
	public static void main(String[] args) throws Exception {
		input();
		Deque<Integer>dq = new ArrayDeque<>();
		for(int i = 1; i <=n; i++) if(rece[i] ==0) dq.addLast(i);
		StringBuilder sb = new StringBuilder();

		int cnt = 0;
		while(!dq.isEmpty()){
			int front = dq.removeFirst();
			cnt++;
			sb.append(front + "\n");
			for(int val : adj[front]){
				rece[val]--;
				if(rece[val] == 0) dq.addLast(val);
			}
		}
		if(cnt != n) System.out.println(0);
		else System.out.println(sb);
	}
}