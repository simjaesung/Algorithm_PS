import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        TreeSet<Integer> remains = new TreeSet<>();
        for(int r : reserve) remains.add(r);
        
        int[] arr = new int[n+2];
        Arrays.fill(arr, 1);  // 전체 1로 초기화 (간단!)
        
        for(int l : lost){
            if(remains.contains(l)){
                remains.remove(l);  // 여벌 있으면 빌려줄 목록 제거 (본인 자동사용)
            } else {
                arr[l] = 0;         // 여벌 없으면만 도난 처리
            }
        }
        
        for(int r : remains){
            if(arr[r-1] == 0) arr[r-1] = 1;
            else if(arr[r+1] == 0) arr[r+1] = 1;
        }
        
        int answer = 0;
        for(int i = 1; i <= n; i++) if(arr[i] == 1) answer++;
        return answer;
    }
}
