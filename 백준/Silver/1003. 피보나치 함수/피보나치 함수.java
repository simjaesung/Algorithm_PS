import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++){
            int n = Integer.parseInt(br.readLine());
            int[] f0 = new int[41];
            int[] f1 = new int[41];
            f0[0] = 1;
            f0[1] = 0;
            f1[0] = 0;
            f1[1] = 1;
            for(int k = 2; k <= n; k++){
                f0[k] = f0[k-1] + f0[k-2];
                f1[k] = f1[k-1] + f1[k-2];
            }
            System.out.println(f0[n] + " " + f1[n]);
        }
    }
}