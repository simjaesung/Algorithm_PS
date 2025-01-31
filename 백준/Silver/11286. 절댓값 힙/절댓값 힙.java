import java.io.*;
import java.util.*;

class Main {
	public static StringBuffer sb = new StringBuffer();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		Map<Integer,Integer> map = new HashMap<>();
		Queue<Integer>pq = new PriorityQueue<>();
		
		for(int i = 0; i < n; i++){
			int x = Integer.parseInt(br.readLine());
			if(x != 0){
				map.put(x, map.getOrDefault(x,0) + 1);
				pq.add(Math.abs(x));
			}else{
				if(pq.isEmpty()) sb.append("0\n");
				else{
					int top = pq.poll();
					if(map.containsKey(top * -1) && map.get(top * -1) > 0){
						map.put(top * -1, map.get(top * -1) - 1);
						sb.append(top * -1 + "\n");
					}else{
						map.put(top, map.get(top) - 1);
						sb.append(top + "\n");
					}
				}
			}
		}
		System.out.println(sb.toString());
	}
}