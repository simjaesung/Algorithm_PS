class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        for(int yLow = yellow; yLow >= 1; yLow--){
            if(yellow % yLow != 0) continue;
            int yCol = yellow / yLow;
            if(yLow * 2 + yCol * 2 + 4 == brown){
                answer[0] = yLow + 2;
                answer[1] = yCol + 2;
                break;
            }
        }
        return answer;
    }
}