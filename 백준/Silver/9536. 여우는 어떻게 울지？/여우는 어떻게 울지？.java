import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Map<String, Integer> map;
		ArrayList<String> arr;
		StringTokenizer st;
		StringBuilder sb;

		StringBuilder ans = new StringBuilder();
		while(n-- > 0){
			arr = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			map = new HashMap<>();
			
			int stCnt = st.countTokens();
			while(stCnt-- > 0) {
				String tmp = st.nextToken();
				arr.add(tmp);
				map.put(tmp, 1);
			}

			while(true){
				st = new StringTokenizer(br.readLine());
				if(st.countTokens() == 5) break;
				for(int i = 0; i < 2; i++) st.nextToken();
				map.put(st.nextToken(), 0);
			}
			
			sb = new StringBuilder();
			for(String cry : arr){
				if(map.get(cry) > 0) sb.append(cry + " ");
			}
			ans.append(sb + "\n");
		}
		
		System.out.println(ans);
	}
}