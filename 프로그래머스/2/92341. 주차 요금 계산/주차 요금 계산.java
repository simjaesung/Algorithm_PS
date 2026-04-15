import java.util.*;

class Solution {
    static int basicTime, basicMoney, perTime, perMoney;
    
    public int[] solution(int[] fees, String[] records) {
        basicTime = fees[0];
        basicMoney = fees[1];
        perTime = fees[2];
        perMoney = fees[3];
        
        Map<String, String> inOutLog = new HashMap<>();
        Map<String, Integer> carTimes = new HashMap<>();
        
        for(String record : records){
            String[] recordSp = record.split(" ");
            String time = recordSp[0];
            String carNum = recordSp[1];
            String inOrOut = recordSp[2];
            
            if(inOrOut.equals("IN")) inOutLog.put(carNum, time);
            else{
                int timeDiff = diffMinute(inOutLog.get(carNum), time);
                carTimes.put(carNum, carTimes.getOrDefault(carNum, 0) + timeDiff);
                inOutLog.remove(carNum);
            }
        }
        
        for(var log : inOutLog.entrySet()){
            String carNum = log.getKey();
            String inTime = log.getValue();
            
            int timeDiff = diffMinute(inTime, "23:59");
            carTimes.put(carNum, carTimes.getOrDefault(carNum, 0) + timeDiff);
        }
        
        Map<String, Integer> carFees = new TreeMap<>();
        
        for(var carTime : carTimes.entrySet()){
            String carNum = carTime.getKey();
            int time = carTime.getValue();
            
            int finalFee = calFee(time);
            carFees.put(carNum, finalFee);
        }
        
        int[] answer = new int[carFees.size()];
        int idx = 0;
        for(var carFee : carFees.entrySet()) answer[idx++] = carFee.getValue();
        return answer;
    }
    
    
    public int diffMinute(String inTime, String outTime){
        String[] inTimeSplit = inTime.split(":");
        String[] outTimeSplit = outTime.split(":");
        
        int inTimeH = Integer.parseInt(inTimeSplit[0]);
        int inTimeM = Integer.parseInt(inTimeSplit[1]);
        
        int outTimeH = Integer.parseInt(outTimeSplit[0]);
        int outTimeM = Integer.parseInt(outTimeSplit[1]);
        
        return (outTimeH * 60 + outTimeM) - (inTimeH * 60 + inTimeM);
    }
    
    public int calFee(int minute){
        if(minute <= basicTime) return basicMoney;
        else{
            int overTime = (minute - basicTime) / perTime;
            if((minute - basicTime) % perTime != 0) overTime++;
            return basicMoney + overTime * perMoney;
        }
    }
}