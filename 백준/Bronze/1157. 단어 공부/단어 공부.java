import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		s = s.toUpperCase();
		char[] charArr = s.toCharArray();
		int[] arr = new int[26];
		for(char c : charArr) arr[c-'A']++;
	
		int maxCnt = 0;
		int maxIdx = 0;
		
		for(int i = 0; i < 26; i++){
			if(arr[i] > maxCnt){
				maxCnt = arr[i];
				maxIdx = i;
			}
		}
		
		if(!checkMax(arr,maxCnt,maxIdx)) System.out.println("?");
		else System.out.println((char)(maxIdx + 'A'));
	}
	
	public static boolean checkMax(int[] arr, int maxCnt, int maxIdx){
		for(int i = 0; i < 26; i++){
			if(arr[i] == maxCnt && i != maxIdx ){
				return false;
			}
		}
		return true;
	}
}