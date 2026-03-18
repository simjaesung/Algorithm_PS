import java.util.*;

class Solution {
    public long check(int[] times, long time){
        long cnt = 0;
        for(int t : times){
            //time안에 최대 몇명을 확인할수있는지
            cnt += time / t;
        }
        return cnt;
    }
    
    public long solution(int n, int[] times) {
        Arrays.sort(times);
        int counter = times.length; //창구 개수
        long st = 1; //최소
        //최대값: 균등한 사람 수 * 시간 최대값
        long end = (long) n * times[counter-1];
        
        while(st + 1 < end){
            long mid = st + (end - st) / 2;
            if(check(times, mid) >= n) end = mid;
            else st = mid;
        }
        
        return end;
    }
}