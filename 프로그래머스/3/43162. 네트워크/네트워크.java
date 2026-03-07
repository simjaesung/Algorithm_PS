import java.util.*;

class Solution {
    static List<Integer> adj[];
    static boolean[] visited;
    static int answer;
    public int solution(int n, int[][] computers) {
        init(n, computers);
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            answer++;
            dfs(i);
        }
        return answer;
    }
    
    public void dfs(int k){
        visited[k] = true;
        for(int nxt : adj[k]){
            if(!visited[nxt]) dfs(nxt);
        }
    }
    
    public void init(int n, int[][] computers){
        adj = new ArrayList[n];
        visited = new boolean[n];
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(computers[i][j] == 1) adj[i].add(j);
            }
        }
    }
}