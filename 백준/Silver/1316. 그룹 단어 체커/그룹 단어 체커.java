import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ans = 0;
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++){
			if(isGroup(br.readLine())) ans++;
		}
		System.out.println(ans);
	}

	public static boolean isGroup(String s){
		char[] charArr = s.toCharArray();
		Map<Character, Integer> map = new HashMap<>();
		map.put(charArr[0],1);
		for(int i = 1; i < s.length(); i++){
			if(charArr[i-1] != charArr[i]){
				if(map.containsKey(charArr[i])) return false;
			}
			map.put(charArr[i],1);
		}

		return true;
	}
}