import java.util.*;

class Solution {
    
    static class Pair{
        int x; int y; int z;
        public Pair(int x, int y, int z){
            //소요 시간, 요청 시각, 작업 번호
            this.x = x; this.y = y; this.z = z;
        }
    }
    
    public int solution(int[][] jobs) {
        int n = jobs.length;
        
        //입력: [작업이 요청되는 시점, 작업의 소요시간]
        Arrays.sort(jobs, (a,b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            else return a[0] - b[0];
        });
            
        PriorityQueue<Pair>pq = new PriorityQueue<>((a,b)->{
            if(a.x != b.x) return a.x - b.x;
            if(a.y != b.y) return a.y - b.y;
            return a.z - b.z;
        });
        
        int idx = 0, time = 0, answer = 0;
        while(idx < n || !pq.isEmpty()){
            while(idx < n && jobs[idx][0] <= time){
                pq.offer(new Pair(jobs[idx][1], jobs[idx][0], idx++));
            }
            
            if(pq.isEmpty()) {
                time = jobs[idx][0];
                continue;
            }
            
            Pair cur = pq.poll();
            time += cur.x;
            answer += time - cur.y;
        }
        
        return answer / n;
    }
}