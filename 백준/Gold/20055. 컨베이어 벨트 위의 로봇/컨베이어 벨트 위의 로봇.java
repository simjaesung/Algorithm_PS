import java.io.*;
import java.util.*;

class Main {
	static class Pair{
		int nagu; boolean isRobot;
		public Pair(int nagu, boolean isRobot){
			this.nagu = nagu; this.isRobot = isRobot;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()); //컨베이어벨트 2*n
		int k = Integer.parseInt(st.nextToken()); //내구도 종료 조건

		Deque<Pair> dq = new ArrayDeque<>();
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < 2*n; i++) {
			dq.addLast(new Pair(Integer.parseInt(st.nextToken()),false));
		}

		int phase = 1;
		while(true){
			//1. 컨베이어 벨트 이동
			dq.addFirst(dq.removeLast());
			List<Pair> belt = new ArrayList<>(dq);
			//내리는위치 버리기
			if(belt.get(n-1).isRobot) belt.set(n-1, new Pair(belt.get(n-1).nagu, false));

			//2. 로봇 이동
			for(int i = n-2; i>=0; i--){
				if(!belt.get(i).isRobot) continue;
				if(!belt.get(i+1).isRobot && belt.get(i+1).nagu > 0){
					belt.set(i+1, new Pair(belt.get(i+1).nagu - 1, true));
					belt.set(i, new Pair(belt.get(i).nagu, false));
				}
			}
            //내리는위치 버리기
			if(belt.get(n-1).isRobot) belt.set(n-1, new Pair(belt.get(n-1).nagu, false));

			//3. 올리는 위치에 있는 칸의 내구도가 0이 아니면
			if(!belt.get(0).isRobot && belt.get(0).nagu > 0){
				belt.set(0, new Pair(belt.get(0).nagu-1, true));
			}

			int cnt = 0;
			for(Pair b : belt) if(b.nagu == 0) cnt++;
			if(cnt >= k) break;
			dq = new ArrayDeque<>(belt);
			phase++;
		}
		System.out.println(phase);
	}
}