import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        Set<Integer> reserves = new HashSet<>();
        Set<Integer> losts = new HashSet<>();
        for(int r : reserve) reserves.add(r);
        
        for(int l : lost){
            if(reserves.contains(l)) reserves.remove(l);
            else losts.add(l);
        }
        
        for(int r : reserves){
            if(losts.contains(r-1)) losts.remove(r-1);
            else if(losts.contains(r+1)) losts.remove(r+1);
        }
        
        return n-losts.size();
    }
}