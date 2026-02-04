class Solution {
    public int n, target_copy, answer;
    public int[] numbers_copy;
    
    public void dfs(int idx, int sum){
        if(idx == n){
            if(sum == target_copy) answer++;
            return;
        }
        dfs(idx + 1, sum + numbers_copy[idx]);
        dfs(idx + 1, sum - numbers_copy[idx]);
    }
    
    public int solution(int[] numbers, int target) {
        target_copy = target;
        n = numbers.length;
        numbers_copy = numbers;
        dfs(0,0);
        return answer;
    }
}