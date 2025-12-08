import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();
		char[] sortA = a.toCharArray();
		char[] sortB = b.toCharArray();
		Arrays.sort(sortA);
		Arrays.sort(sortB);

		int idxA = 0; int idxB = 0; int same = 0;
		while(idxA < a.length() && idxB < b.length()){
			if(sortA[idxA] == sortB[idxB]){
				same++; idxA++; idxB++;
			} else if(sortA[idxA] < sortB[idxB]) idxA++;
			else idxB++; 
		}

		System.out.print(a.length() - same + b.length() - same);
	}
}