class Solution {
    int a,b;
    public int solution(int[][] sizes) {
        for(int[] size : sizes){
            if(size[0] < size[1]){
                a = Math.max(a, size[1]);
                b = Math.max(b, size[0]);
            }else{
                a = Math.max(a, size[0]);
                b = Math.max(b, size[1]);
            }
        }
        return a * b;
    }
}