class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        int yellowRow = yellow;
        int yellowCol = 1;
        
        while(yellowRow >= yellowCol){
            if(yellow % yellowRow != 0){
                yellowRow--;
                continue;
            }
            
            yellowCol = yellow / yellowRow;
            int around = (yellowRow + yellowCol) * 2;
            if(brown - around == 4) {
                answer[0] = yellowRow + 2;
                answer[1] = yellowCol + 2;
                break;
            }
            yellowRow--;
        }
        return answer;
    }
}