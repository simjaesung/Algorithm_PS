import java.io.*;
import java.util.*;
class Main {
	static String t1,t2,t3,t4;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t1 = br.readLine();
		t2 = br.readLine();
		t3 = br.readLine();
		t4 = br.readLine();

		int k = Integer.parseInt(br.readLine());
		while(k-- > 0){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int t = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			if(t == 1) startAtT1(d);
			else if(t == 2) startAtT2(d);
			else if(t == 3) startAtT3(d);
			else startAtT4(d);
		}

		int score1 = (t1.charAt(0) == '1')? 1:0;
		int score2 = (t2.charAt(0) == '1')? 2:0;
		int score3 = (t3.charAt(0) == '1')? 4:0;
		int score4 = (t4.charAt(0) == '1')? 8:0;
		System.out.println(score1 + score2 + score3 + score4);
	}

	public static void rotateT(int d, int num){
		if(d == 1){
			//시계
			if(num  == 1) t1 = t1.charAt(7) + t1.substring(0,7);
			else if(num  == 2) t2 = t2.charAt(7) + t2.substring(0,7);
			else if(num  == 3) t3 = t3.charAt(7) + t3.substring(0,7);
			else t4 = t4.charAt(7) + t4.substring(0,7);
		}else{
			//반시계
			if(num  == 1) t1 = t1.substring(1,8) + t1.charAt(0);
			else if(num  == 2) t2 = t2.substring(1,8) + t2.charAt(0);
			else if(num  == 3) t3 = t3.substring(1,8) + t3.charAt(0);
			else t4 = t4.substring(1,8) + t4.charAt(0);
		}
	}

	public static void startAtT1(int d){
		boolean rotateT2 = false;
		boolean rotateT3 = false;
		boolean rotateT4 = false;
		if(t1.charAt(2) != t2.charAt(6)) {
			rotateT2 = true;
			if(t2.charAt(2) != t3.charAt(6)) {
				rotateT3 = true;
				if(t3.charAt(2) != t4.charAt(6)){
					rotateT4 = true;
				}
			}
		}
		rotateT(d,1);
		if(rotateT2) rotateT(d * -1,2);
		if(rotateT3) rotateT(d,3);
		if(rotateT4) rotateT(d * -1 ,4);	
	}

	public static void startAtT2(int d){
		boolean rotateT1 = false;
		boolean rotateT3 = false;
		boolean rotateT4 = false;
		if(t2.charAt(2) != t3.charAt(6)) {
			rotateT3 = true;
			if(t3.charAt(2) != t4.charAt(6)) rotateT4 = true;
		}
		if(t2.charAt(6) != t1.charAt(2)) rotateT1 = true;

		rotateT(d,2);
		if(rotateT1) rotateT(d * -1,1);
		if(rotateT3) rotateT(d * -1,3);
		if(rotateT4) rotateT(d,4);
	}

	public static void startAtT3(int d){
		boolean rotateT1 = false;
		boolean rotateT2 = false;
		boolean rotateT4 = false;
		if(t3.charAt(6) != t2.charAt(2)) {
			rotateT2 = true;
			if(t2.charAt(6) != t1.charAt(2)) rotateT1 = true;
		}
		if(t3.charAt(2) != t4.charAt(6)) rotateT4 = true;

		rotateT(d,3);
		if(rotateT1) rotateT(d,1);
		if(rotateT2) rotateT(d * -1,2);
		if(rotateT4) rotateT(d * -1 ,4);
	}

	public static void startAtT4(int d){
		boolean rotateT1 = false;
		boolean rotateT2 = false;
		boolean rotateT3 = false;
		if(t4.charAt(6) != t3.charAt(2)) {
			rotateT3 = true;
			if(t3.charAt(6) != t2.charAt(2)) {
				rotateT2 = true;
				if(t2.charAt(6) != t1.charAt(2)){
					rotateT1 = true;
				}
			}
		}

		rotateT(d,4);
		if(rotateT1) rotateT(d * -1,1);
		if(rotateT2) rotateT(d,2);
		if(rotateT3) rotateT(d * -1 ,3);	
	}
}