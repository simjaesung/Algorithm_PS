import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		List<String> sNum = new ArrayList<>();
		
		for(int i = 0; i < n; i++){
			String name = br.readLine();
			sNum.add(name);
		}

		int numLen = sNum.get(0).length();
		int k = numLen - 1;

		while(k >= 0){
			Map<String, Integer> map = new HashMap<>();

			boolean check = false;
			for(String num : sNum){
				String shortNum = num.substring(k, numLen);
				if(map.containsKey(shortNum)) {
					check = true;
					break;
				}
				map.put(shortNum,1);
			}
			if(!check) break;
			k--;
		}
		System.out.println(numLen - k);
	}
}