import java.io.*;
import java.util.*;

class Main {
	static class Person{
		int age;
		String name;

		public Person(int age, String name){
			this.age = age;
			this.name = name;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Person[] arr = new Person[n];
		for(int i = 0; i < n; i++){
			StringTokenizer st = new StringTokenizer(br.readLine());
			int age = Integer.parseInt(st.nextToken());
			String name = st.nextToken();
			arr[i] = new Person(age,name);
		}

		Arrays.sort(arr, (a,b) -> a.age - b.age);

		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++) sb.append(arr[i].age + " " + arr[i].name + "\n");
		
		System.out.println(sb);
	}
}