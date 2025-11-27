import java.io.*;
import java.util.*;
import java.math.*;

class Main {
	static List<BigInteger> ans = new ArrayList<>();
	
	static void findNum(String s){
    char[] charArr = s.toCharArray();
    StringBuilder tmp = new StringBuilder();

    for(char c : charArr){
        if (c >= '0' && c <= '9') tmp.append(c);
        else {
            if (tmp.length() > 0) {
                ans.add(new BigInteger(tmp.toString()));
                tmp.setLength(0);
            }
        }
	    }
	    if (tmp.length() > 0) ans.add(new BigInteger(tmp.toString()));
	}

	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0){
			String s = br.readLine();
			findNum(s);
		}

		Collections.sort(ans);
		StringBuilder printAns = new StringBuilder();
		for(BigInteger k : ans) printAns.append(k + "\n");
		System.out.println(printAns);
	}
}