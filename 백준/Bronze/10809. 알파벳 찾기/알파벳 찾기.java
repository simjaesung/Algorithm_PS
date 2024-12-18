import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		char[] charArr = s.toCharArray();
		int[] arr = new int[26];
		for(int i = 0; i< 26; i++) arr[i] = -1;
		
		for(int i = 0; i<charArr.length; i++){
			int idx = (int)charArr[i] - 97;
			if(arr[idx] == -1) arr[idx] = i;
		}
		
		for(int i : arr){
			System.out.print(i + " ");
		}
	}
}