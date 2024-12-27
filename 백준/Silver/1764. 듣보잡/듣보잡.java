import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		Map<String,Integer> map =new HashMap<>();
		
		while(n-- > 0){
			String name = br.readLine();
			map.put(name,1);
		}
		
		StringBuilder sb = new StringBuilder();
		int cnt = 0;
		while(m-- > 0){
			String name = br.readLine();
			if(map.containsKey(name)) {
				cnt++;
				sb.append(name + " ");
			}
		}
		
		String[] names = sb.toString().split(" ");
		Arrays.sort(names);

		System.out.println(cnt);
		System.out.println(String.join("\n",names));
	}
}