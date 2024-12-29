import java.io.*;
import java.util.*;

class Main {
	public static boolean[] check = new boolean[9];
	public static int[] arr = new int[9];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 9; i++){
			arr[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(arr);	
		go(0,0);
	}

	public static void go(int st, int idx){
		if(idx == 7){
			if(getSum() == 100){
				for(int i = 0; i < 9; i++){
					if(check[i]) System.out.println(arr[i]);
				}
				System.exit(0);
			}
            return;
		}
		
		for(int i = st; i < 9; i++){
			check[i] = true;
			go(i + 1, idx + 1);
			check[i] = false;
		}
	}
	
	public static int getSum(){
		int sum = 0;
		for(int i = 0; i < 9; i++){
			if(check[i]) sum += arr[i];
		}
		return sum;
	}
}