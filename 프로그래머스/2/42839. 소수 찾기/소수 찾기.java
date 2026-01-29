import java.util.*;

class Solution {
    public static int n, ans;
    public static boolean[] isPrime = new boolean[10000005];
    public static char[] number;
    public static boolean[] visited;
    public static Map<Integer, Boolean> map = new HashMap<>();
    
    public int solution(String numbers) {
        n = numbers.length();
        number = numbers.toCharArray();
        visited = new boolean[n];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= 9999999; i++){
            if(isPrime[i]){
                for(int j = i * i; j <= 9999999; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        findNum(0,"");
        return ans;
    }
    
    public void findNum(int idx, String tmp){
        if(idx > 0){
            int toInt = Integer.parseInt(tmp);
            if(!map.containsKey(toInt)){
                if(isPrime[toInt]) ans++;
                map.put(toInt, true);
            }
        }
        
        if(idx == n) return;
        
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            visited[i] = true;
            findNum(idx + 1,tmp + number[i]);
            visited[i] = false;
        }
    }
}