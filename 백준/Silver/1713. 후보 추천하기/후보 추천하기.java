import java.io.*;
import java.util.*;
class Main {
	static class Pair{
		int num; int seq;
		public Pair(int num, int seq){
			this.num = num; this.seq = seq;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		int[] vote = new int[101];

		List<Pair> arr = new ArrayList<>();

		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < k; i++){
			int student = Integer.parseInt(st.nextToken());
			vote[student]++;
			if(vote[student] == 1){
				if(arr.size() == n){
					Collections.sort(arr, (a,b) -> {
						if(vote[a.num] == vote[b.num]) return a.seq - b.seq;
						return vote[a.num] - vote[b.num];
					});
					Pair exit = arr.remove(0);
					vote[exit.num] = 0;
				}
				arr.add(new Pair(student,i));
			}
		}

		Collections.sort(arr, (a,b) -> a.num - b.num);
		for(Pair a : arr) System.out.print(a.num + " ");
	}
}