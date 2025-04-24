import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int burdger_min = Integer.parseInt(br.readLine());
        for (int i = 0; i < 2; i++) {
            burdger_min = Math.min(burdger_min, Integer.parseInt(br.readLine()));
        }
        int drink_min = Math.min(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()));
        System.out.print(burdger_min + drink_min - 50);
    }
}