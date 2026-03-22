import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		StringBuilder ans = new StringBuilder();
		
		while(T-- > 0){
			String p = br.readLine();//RDD
			char[] cmd = p.toCharArray();//['R',..]
			int n = Integer.parseInt(br.readLine());
			String s = br.readLine(); //[1,2,3,4]
			String[] arr = s.substring(1, s.length() - 1).split(",");
			
			int st = 0; 
			int end = n;
			
			boolean isR = false;
			for(char c : cmd){
				if(c == 'R') isR = !isR;
				else{
					if(isR) end--;
					else st++;
				}
			}

			if(end < st) ans.append("error\n");
			else{
				StringBuilder sb = new StringBuilder();
				if(!isR) {
					for(int i = st; i < end; i++) {
						if(i == end - 1) sb.append(arr[i]);
						else sb.append(arr[i] + ",");
					}
				}else{
					for(int i = end - 1; i >= st; i--) {
						if(i == st) sb.append(arr[i]);
						else sb.append(arr[i] + ",");
					}
				}
				ans.append("[" + sb + "]\n");
			}
		}
		System.out.println(ans);
	}
}