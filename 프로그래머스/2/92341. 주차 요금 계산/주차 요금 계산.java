import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        //records: 시각, 차량번호, 내역
        Map<String, String> recordInOut = new HashMap<>();
        TreeMap<String, Integer> recordMin = new TreeMap<>();
        
        for(String record : records){
            String[] recordSplit = record.split(" ");
            String time = recordSplit[0];
            String carNum = recordSplit[1];
            String inOrOut = recordSplit[2];
            
            if(inOrOut.equals("IN")) recordInOut.put(carNum, time);
            else{
                String inTime = recordInOut.get(carNum);
                int min = calMin(inTime, time);
                recordInOut.remove(carNum);
                recordMin.put(carNum, recordMin.getOrDefault(carNum, 0) + min);
            }
        }
        
        for(var entry : recordInOut.entrySet()){
            int min = calMin(entry.getValue(), "23:59");
            recordMin.put(entry.getKey(), 
                          recordMin.getOrDefault(entry.getKey(),0) + min);
        }
        
        //차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로
        int[] ans = new int[recordMin.size()];
        
        int idx = 0;
        for(var entry : recordMin.entrySet()){
            ans[idx++] = calFee(fees, recordMin.get(entry.getKey()));
        }
        
        return ans;
    }
    
    //시간 차 계산
    public int calMin(String in, String out){
        String[] inSplit = in.split(":");
        String[] outSplit = out.split(":");
        
        int inH = Integer.parseInt(inSplit[0]);
        int inM = Integer.parseInt(inSplit[1]);
        int outH = Integer.parseInt(outSplit[0]);
        int outM = Integer.parseInt(outSplit[1]);
        
        if(outM >= inM) {
            return (outH - inH) * 60 + (outM - inM);
        }
        else{
            return (outH - inH - 1) * 60  + outM - inM + 60;
        }
    }
    
    public int calFee(int[] fees, int min){
        //fees: 기본 시간(분),기본 요금(원),단위 시간(분),단위 요금(원)
        int fee = 0;
        if(min > fees[0]){
            min -= fees[0];
            int per = min / fees[2];
            int remain = min % fees[2];
            if(remain != 0) per++;
            fee = fees[1] + per * fees[3];
        }else fee += fees[1];
        return fee;
    }
}