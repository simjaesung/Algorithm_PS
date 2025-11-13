import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] names = new String[n]; //이름 배열
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++) names[i] = st.nextToken();
		Arrays.sort(names);

		Map<String,Integer> map = new HashMap<>(); //이름의 인덱스값 저장
		for(int i = 0; i < n; i++) map.put(names[i], i);

		ArrayList<Integer>[] adj = new ArrayList[n]; //자식 -> 조상 간선
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
		int[] recev = new int[n]; // 받는 간선 수
		int m = Integer.parseInt(br.readLine());
		while(m-- > 0){
			st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			adj[map.get(a)].add(map.get(b));
			recev[map.get(b)]++;
		}

		TreeSet<String>[] ts = new TreeSet[n]; //바로 자식 저장 리스트
		for(int i = 0; i<n; i++) ts[i] = new TreeSet<>();
		
		TreeSet<String> high = new TreeSet<>(); //최고 조상 리스트

		Deque<Integer> dq = new ArrayDeque<>();
		for(int i = 0; i < n; i++) if(recev[i] == 0) dq.addLast(i);

		while(!dq.isEmpty()){
			int cur = dq.removeFirst();
			//조상인 경우
			if(adj[cur].size() == 0) {
				high.add(names[cur]);
				continue;
			}
			
			boolean checkZero = false;
			for(int nxt : adj[cur]){
				ts[nxt].add(names[cur]); //자식 후보 이름 추가
				recev[nxt]--;
				if(recev[nxt] == 0) {
					dq.add(nxt);
					checkZero = true;
				}
			}

			if(checkZero){
				for(int nxt : adj[cur]){
					if(recev[nxt] != 0) {
						ts[nxt] = new TreeSet<>();
					}
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		sb.append(high.size() + "\n");
		for(String h : high) sb.append(h + " ");
		sb.append("\n");
		for(int i = 0; i < n; i++){
			sb.append(names[i] + " " + ts[i].size() + " ");
			for(String s : ts[i]) sb.append(s + " ");
			sb.append("\n");
		}

		System.out.print(sb);
	}
}