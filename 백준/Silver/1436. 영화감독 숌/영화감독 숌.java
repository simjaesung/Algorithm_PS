import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int ans = 0;
		int title = 666;
		
		while(ans != n){
			String sTitle = "" + title;
			if(sTitle.contains("666")) ans++;
			title++;
		}
		
		System.out.println(title - 1);
	}
}