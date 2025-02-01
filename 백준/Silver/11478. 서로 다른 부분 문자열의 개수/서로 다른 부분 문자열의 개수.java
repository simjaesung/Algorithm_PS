import java.io.*;
import java.util.*;

class Main {
	public static Map<String,Integer> map = new HashMap<>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int ans = 0;
		for(int i = 0; i < s.length(); i++){
			for(int j = i; j < s.length(); j++){
				String k = s.substring(i, j + 1);
				if(!map.containsKey(k)){
					ans++;
					map.put(k,1);
				}
			}
		}
		System.out.println(ans);
	}
}