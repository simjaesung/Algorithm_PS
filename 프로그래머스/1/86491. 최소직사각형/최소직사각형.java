class Solution {
    int a,b;
    public int solution(int[][] sizes) {
        for(int[] size : sizes){
            a = Math.max(a, Math.max(size[0],size[1]));
            b = Math.max(b, Math.min(size[0],size[1]));
        }
        return a * b;
    }
}