import java.io.*;
import java.util.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int[] visited = new int[100001];
		int INF = Integer.MAX_VALUE;
		Arrays.fill(visited, INF);
		
		Deque<Integer> q = new ArrayDeque<>();
		q.addLast(n);
		visited[n] = 0;
		while(!q.isEmpty()){
			int loc = q.removeFirst();
			int cnt = visited[loc];
			if(loc * 2 <= 100000 && cnt < visited[loc*2]){
				visited[loc*2] = cnt;
				q.addFirst(loc*2);
			}
			if(loc + 1 <= 100000 && cnt + 1 < visited[loc+1]){
				visited[loc+1] = cnt+1;
				q.addLast(loc+1);
			}
			if(loc - 1 >= 0 && cnt + 1 < visited[loc-1]){
				visited[loc-1] = cnt+1;
				q.addLast(loc-1);
			}
		}
		System.out.println(visited[k]);
	}
}