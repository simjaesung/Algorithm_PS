class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int[][] arr = new int[rows+1][columns+1];
        int val = 1;
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= columns; j++) arr[i][j] = val++;
        }
        
        int idx = 0;
        for(int[] query : queries){
            int x1 = query[0];
            int y1 = query[1];
            int x2 = query[2];
            int y2 = query[3];
            int prev = arr[x1][y1];
            int min = prev;
            
            for(int y = y1+1; y <= y2; y++){
                int tmp = arr[x1][y];
                arr[x1][y] = prev;
                min = Math.min(min, arr[x1][y]);
                prev = tmp;
            }
            
            for(int x = x1+1; x <= x2; x++){
                int tmp = arr[x][y2];
                arr[x][y2] = prev;
                min = Math.min(min, arr[x][y2]);
                prev = tmp;
            }
            
            for(int y = y2-1; y >= y1; y--){
                int tmp = arr[x2][y];
                arr[x2][y] = prev;
                min = Math.min(min, arr[x2][y]);
                prev = tmp;
            }
            
            for(int x = x2-1; x >= x1; x--){
                int tmp = arr[x][y1];
                arr[x][y1] = prev;
                min = Math.min(min, arr[x][y1]);
                prev = tmp;
            }
            
            answer[idx++] = min;
        }
        return answer;
    }
}