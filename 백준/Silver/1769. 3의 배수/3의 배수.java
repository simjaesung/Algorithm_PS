import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n = br.readLine();
		
		int ans = 0;
		while(n.length() > 1){
			ans ++;
			int tmp = 0;
			for(char c : n.toCharArray()){
				tmp += c - '0';
			}
			n = String.valueOf(tmp);
		}
		
		System.out.println(ans);
		if (Integer.parseInt(n) % 3 == 0) System.out.println("YES");
		else System.out.println("NO");
	}
}