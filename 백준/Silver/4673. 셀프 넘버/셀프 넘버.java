import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		int[] arr = new int[20000];

		for(int i = 1; i <= 10000; i++){
			int st = i;
			int k = i;
			while(st > 0){
				k += st%10;
				st /= 10;
			}
			arr[k] = 1;
		}

		StringBuffer sb = new StringBuffer();
		for(int i = 1; i <= 10000; i++){
			if(arr[i] == 0) sb.append(i + "\n");
		}
		System.out.print(sb.toString());
	}
}