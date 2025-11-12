import java.util.*;

class Solution {
    static class Pair{
        int x; int y;
        public Pair(int x, int y){
            this.x = x; this.y = y;
        }
    }
    static int INF = Integer.MAX_VALUE;
    
    public int solution(int n, int[][] edge) {
        ArrayList<Pair>[] adj = new ArrayList[n+1];
        for(int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for(int[] ed : edge){
            adj[ed[0]].add(new Pair(ed[1],1));
            adj[ed[1]].add(new Pair(ed[0],1));
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.y - b.y);
        int[] dist = new int[n+1];
        Arrays.fill(dist,INF);
        dist[1] = 0;
        pq.offer(new Pair(1,0));
        
        while(!pq.isEmpty()){
            Pair cur = pq.poll();
            if(dist[cur.x] != cur.y) continue;
            for(Pair nxt : adj[cur.x]){
                if(dist[nxt.x] <= dist[cur.x] + nxt.y) continue;
                dist[nxt.x] = dist[cur.x] + nxt.y;
                pq.offer(new Pair(nxt.x, dist[nxt.x]));
            }
        }
    
        
        int answer = 1; int max = dist[1];
        for(int i = 2; i<=n; i++){
            if(dist[i] < max) continue;
            if(dist[i] > max){
                max = dist[i];
                answer = 0;
            }
            answer++;
        }
        return answer;
    }
}