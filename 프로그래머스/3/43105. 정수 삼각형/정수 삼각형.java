class Solution {
    public int solution(int[][] triangle) {
        int ans = 0;
        for(int i = 1; i < triangle.length; i++){
            for(int j = 0; j <= i; j++){
                int tmp = triangle[i][j];
                if(j == 0) triangle[i][j] = triangle[i-1][j];
                else if(j == i) triangle[i][j] = triangle[i-1][j-1];
                else triangle[i][j] = Math.max(triangle[i-1][j-1], triangle[i-1][j]);
                triangle[i][j] += tmp;
                
                if(i == triangle.length - 1) ans = Math.max(ans, triangle[i][j]);
            }
        }
        
        return ans;
    }
}