import java.util.*;

class Solution {
    public boolean[] winV, loseV;
    public ArrayList<Integer>[] adjWin, adjLose;
    
    public void dfsWin(int x){
        for(int nx : adjWin[x]){
            if(!winV[nx]){
                winV[nx] = true;
                dfsWin(nx);
            }
        }
    }
    
    public void dfsLose(int x){
        for(int nx : adjLose[x]){
            if(!loseV[nx]){
                loseV[nx] = true;
                dfsLose(nx);
            }
        }
    }
    
    public int solution(int n, int[][] results) {
        adjWin = new ArrayList[n+1];
        adjLose = new ArrayList[n+1];
        winV = new boolean[n+1];
        loseV = new boolean[n+1];
        
        for(int i = 1; i <= n; i++){
            adjWin[i] = new ArrayList<>();
            adjLose[i] = new ArrayList<>();
        }
        
        for(int[] r : results){
            adjWin[r[0]].add(r[1]);
            adjLose[r[1]].add(r[0]);
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++){
            Arrays.fill(winV, false);
            Arrays.fill(loseV, false);
            
            dfsWin(i);
            dfsLose(i);
            
            int tmp = 0;
            for(int k = 1; k <= n; k++){
                if(winV[k] || loseV[k]) tmp++;
            }
            if(tmp == n-1) ans++;
        }
        
        return ans;
    }
}