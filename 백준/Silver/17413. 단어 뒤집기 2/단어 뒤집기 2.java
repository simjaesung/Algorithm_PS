import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		char[] arr = input.toCharArray();

		StringBuilder ans = new StringBuilder();
		StringBuilder tmp = new StringBuilder();
		boolean isTag = false;
		for(int i = 0; i < arr.length; i++){
			if(arr[i] == '<') {
				if(isTag) ans.append(tmp);
				else ans.append(tmp.reverse());
				isTag = true;
				tmp = new StringBuilder();
				tmp.append('<');
			} else if(arr[i] == '>'){
				isTag = false;
				tmp.append('>');
				ans.append(tmp);
				tmp = new StringBuilder();
			} else if(arr[i] == ' '){
				if(!isTag){
					ans.append(tmp.reverse());
					ans.append(' ');
					tmp = new StringBuilder();
				}else tmp.append(' ');
			}
			else tmp.append(arr[i]);
		}

		if(!isTag) ans.append(tmp.reverse());
		System.out.println(ans);
	}
}