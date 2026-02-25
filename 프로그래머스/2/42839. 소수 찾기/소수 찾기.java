class Solution {
    public static int n = 10000005;
    public static int numN;
    public static int[] arr = new int[n];
    public static char[] charArr;
    public static boolean[] used = new boolean[n];
    public static boolean[] visited;
    public static int ans;
    
    public int solution(String numbers) {
        init();
        numN = numbers.length();
        charArr = numbers.toCharArray();
        visited = new boolean[numN];
        go("");
        return ans;
    }
    
    public static void init(){
        for(int i = 2; i < n; i++) arr[i] = i;
        for(int i = 2; i < n; i++){
            if(arr[i] == 0) continue;
            for(long j = (long)i*i; j < n; j+=i){
                arr[(int)j] = 0;
            }
        }
    }
    
    public static void go(String tmp){
        if(tmp.length() > 0){
            int tmpToN = Integer.parseInt(tmp);
            if(arr[tmpToN] != 0 && !used[tmpToN]) {
                ans++;
                used[tmpToN] = true;
            }
        }
        for(int i = 0; i < numN; i++){
            if(visited[i]) continue;
            visited[i] = true;
            go(tmp + charArr[i]);
            visited[i] = false;
        }
    }
}