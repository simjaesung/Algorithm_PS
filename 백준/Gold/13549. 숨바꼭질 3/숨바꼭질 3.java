import java.io.*;
import java.util.*;
class Main {
	static class Pair{
		int x; int y;
		public Pair(int x, int y){
			this.x = x; this.y = y;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] visited = new int[100001];
		int INF = Integer.MAX_VALUE;
		Arrays.fill(visited, INF);
		
		Deque<Pair> q = new ArrayDeque<>();
		q.addLast(new Pair(n,0));
		visited[n] = 0;
		while(!q.isEmpty()){
			Pair cur = q.removeFirst();
			int loc = cur.x; int cnt = cur.y;
			if(loc * 2 <= 100000 && cnt < visited[loc*2]){
				visited[loc*2] = cnt;
				q.addLast(new Pair(loc*2,cnt));
			}
			if(loc + 1 <= 100000 && cnt + 1 < visited[loc+1]){
				visited[loc+1] = cnt+1;
				q.addLast(new Pair(loc+1,cnt+1));
			}
			if(loc - 1 >= 0 && cnt + 1 < visited[loc-1]){
				visited[loc-1] = cnt+1;
				q.addLast(new Pair(loc-1,cnt+1));
			}
		}
		System.out.println(visited[k]);
	}
}