import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Map<String, Integer> map = new HashMap<>();
		
		for(int i = 0; i < n; i++){
			String book = br.readLine();
			int val = map.getOrDefault(book, 0);
			map.put(book, val + 1);
		}

		List<String> keySet = new ArrayList<>(map.keySet());
		Collections.sort(keySet);
		int cnt = 0;
		String ans = "";
		for(String key : keySet){
			if(map.get(key) > cnt){
				ans = key;
				cnt = map.get(key);
			}
		}

		System.out.print(ans);
	}
}