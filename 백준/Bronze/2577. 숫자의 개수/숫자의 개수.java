import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int abc  = 1;
		for(int i = 0; i < 3; i++){
			int val = Integer.parseInt(br.readLine());
			abc *= val;
		}
		
		int[] arr = new int[10];
		while(abc > 0){
			arr[abc % 10]++;
			abc /= 10;
		}
		
		for(int i : arr) System.out.println(i);
	}
}