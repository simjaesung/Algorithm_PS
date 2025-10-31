import java.io.*;
import java.util.*;

class Main {
	public static int n,m;
	public static ArrayList<Integer>[] adj;
	public static int inCnt[];
	public static void input() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		adj = new ArrayList[n+1];
		inCnt = new int[n+1];

		for(int i = 0; i <= n; i++) adj[i] = new ArrayList<>();

		for(int i = 0; i < m; i++){
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			inCnt[b]++;
		}
	}
	
	public static void main(String[] args) throws Exception {
		input();
		Deque<Integer>dq = new LinkedList<>();
		for(int i = 1; i <=n; i++) {
			if(inCnt[i] == 0) dq.addLast(i);
		}

		StringBuilder sb = new StringBuilder();

		while(!dq.isEmpty()){
			int front = dq.removeFirst();
			sb.append(front + " ");
			for(int k : adj[front]){
				inCnt[k]--;
				if(inCnt[k] == 0) dq.addLast(k);
			}
		}

		System.out.print(sb.toString());
	}
}