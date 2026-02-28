class Solution {
    static int ans, numLen;
    static int n = 10000005;
    static boolean[] isPrime = new boolean[n];
    static char[] arr;
    static boolean[] used;
    static boolean[] ansUsed = new boolean[n];
    
    public int solution(String numbers) {
        init(numbers);
        go("");
        return ans;
    }
    
    public void go(String tmp){
        if(!tmp.equals("")){
            int tmpNum = Integer.parseInt(tmp);
            if(isPrime[tmpNum] && !ansUsed[tmpNum]) {
                ans++;
                ansUsed[tmpNum] = true;
            }
        }
        
        for(int i = 0; i < numLen; i++){
            if(used[i]) continue;
            used[i] = true;
            go(tmp + arr[i]);
            used[i] = false;
        }
    }
    
    public void init(String numbers){
        //소수 설정
        for(int i = 2; i < n; i++) isPrime[i] = true;
        for(int i = 2; i * i < n; i++){
            if(!isPrime[i]) continue;
            for(int j = i * i; j < n; j += i) isPrime[j] = false;
        }
        
        arr = numbers.toCharArray();
        numLen = numbers.length();
        used = new boolean[numLen];
    }
}