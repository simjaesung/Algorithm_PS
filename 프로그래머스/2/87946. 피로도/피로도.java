class Solution {
    static int n;
    static int answer = 0;
    static boolean[] visited;
    static int[][] dungeonsCopy;
    public int solution(int k, int[][] dungeons) {
        n = dungeons.length;
        visited = new boolean[n];
        dungeonsCopy = dungeons;
        go(0, k);
        return answer;
    }
    
    public void go(int cnt, int remain){
        answer = Math.max(answer, cnt);
        
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            if(dungeonsCopy[i][0] > remain) continue;
            visited[i] = true;
            go(cnt + 1, remain - dungeonsCopy[i][1]);
            visited[i] = false;
        }
    }
}