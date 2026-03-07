import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] arr = new int[n+2];
        Arrays.fill(arr,1);
        for(int l : lost) arr[l]--;
        for(int r : reserve) arr[r]++;
        
        for(int i = 1; i <= n; i++){
            if(arr[i] < 2) continue;
            if(arr[i-1] == 0) {
                arr[i-1]++; arr[i]--;
            }else if(arr[i+1] == 0){
                arr[i+1]++; arr[i]--;
            }
        }
        
        int answer = 0;
        for(int i = 1; i <= n; i++) if(arr[i] > 0) answer++;
        return answer;
    }
}