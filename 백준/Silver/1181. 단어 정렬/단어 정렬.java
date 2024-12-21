import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		HashSet<String>set = new HashSet<>();
		
		while(n-- > 0){
			set.add(br.readLine());
		}
		
		int setSize = set.size();
		String[] arr = set.toArray(new String[setSize]);
		
		Arrays.sort(arr, new Comparator<String>(){
			@Override
			public int compare(String a, String b){
				if(a.length() == b.length()){
					return a.compareTo(b);
				}else{
					return a.length() - b.length();
				}
			}
		});
		
		StringBuilder sb = new StringBuilder();
		for(String s : arr) sb.append(s).append("\n");
		System.out.println(sb.toString());
	}
}