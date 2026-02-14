import java.util.*;

class Solution {
    static class Pair{
        int x; int y;
        public Pair(int x, int y){
            this.x = x; this.y = y;
        }
    }
    
    public int solution(int[][] maps) {
        int n = maps.length;
        int m = maps[0].length;
        int[][] visited = new int[n][m];
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        
        Deque<Pair> dq = new ArrayDeque<>();
        dq.add(new Pair(0,0));
        visited[0][0] = 1;
        
        while(!dq.isEmpty()){
            Pair cur = dq.removeFirst();
            int cx = cur.x;
            int cy = cur.y;
            
            for(int i = 0; i < 4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(maps[nx][ny] == 0 || visited[nx][ny] > 0) continue;
                visited[nx][ny] = visited[cx][cy] + 1;
                dq.add(new Pair(nx,ny));
            }
        }
        
        if(visited[n-1][m-1] == 0) return -1;
        return visited[n-1][m-1];
    }
}