import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();        
        String[] cAlpha = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
		int index = 0;

		for (int i = 0; i < cAlpha.length; i++) {		
            index = s.indexOf(cAlpha[i]);            
			if (index >= 0) { 
				s = s.replaceAll(cAlpha[i], "A");
			}
		}
		System.out.println(s.length());
	}
}