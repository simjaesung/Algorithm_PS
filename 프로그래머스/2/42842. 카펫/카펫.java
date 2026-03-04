class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        for(int col = 1; col <= yellow; col++){
            if(yellow % col != 0) continue;
            int row = yellow / col;
            int around = (col + row) * 2;
            if(brown - around == 4) {
                answer[0] = row + 2;
                answer[1] = col + 2;
                break;
            }
        }
        
        return answer;
    }
}