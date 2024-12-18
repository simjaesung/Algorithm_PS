import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		if(s.equals(" ")) System.out.println(0);
		else{
			String[] splitS = s.trim().split(" ");
			System.out.println(splitS.length);
		}
	}
}