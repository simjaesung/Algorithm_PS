class Solution {
    public int solution(int[][] triangle) {
        int n = triangle.length;
        int[][] dp = new int[n][n];
        dp[0][0] = triangle[0][0];
        
        int ans = 0;
        
        for(int i = 1; i < n; i++){
            int row = triangle[i].length;
            for(int j = 0; j < row; j++){
                if(j == 0) dp[i][j] = dp[i-1][j];
                else if(j == row - 1) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = Math.max(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] += triangle[i][j];
                
                if(i == n-1) ans = Math.max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
}