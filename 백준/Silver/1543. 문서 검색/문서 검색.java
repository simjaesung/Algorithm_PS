import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();
		int ans = 0;
		
		int st = 0;
		while(st <= a.length()){
			int idx = a.substring(st, a.length()).indexOf(b);
			if(idx != -1){
				ans++;
				st += idx + b.length();
			} else break;
		}

		System.out.println(ans);
	}
}