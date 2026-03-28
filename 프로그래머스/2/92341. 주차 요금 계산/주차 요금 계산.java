import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        //records: 시각, 차량번호, 내역
        Map<String, String> recordInOut = new HashMap<>();
        Map<String, Integer> recordMin = new HashMap<>();
        Set<String> carNums = new HashSet<>();
        
        for(String record : records){
            String[] recordSplit = record.split(" ");
            String time = recordSplit[0];
            String carNum = recordSplit[1];
            String inOrOut = recordSplit[2];
            
            if(inOrOut.equals("IN")){
                recordInOut.put(carNum, time);
                carNums.add(carNum);
            }else{
                String inTime = recordInOut.get(carNum);
                int min = calMin(inTime, time);
                recordMin.put(carNum, recordMin.getOrDefault(carNum, 0) + min);
                recordInOut.remove(carNum);
            }
        }
        
        for(String carNum : carNums){
            if(recordInOut.containsKey(carNum)){
                String inTime = recordInOut.get(carNum);
                int min = calMin(inTime, "23:59");
                recordMin.put(carNum, recordMin.getOrDefault(carNum, 0) + min);
            }
        }
        
        //차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로
        String[][] arr = new String[carNums.size()][2];
        
        int idx = 0;
        for(String carNum : carNums){
            arr[idx][0] = carNum;
            arr[idx][1] = calFee(fees, recordMin.get(carNum)) + "";
            idx++;
        }
        
        Arrays.sort(arr,(a,b) -> a[0].compareTo(b[0]));
        int[] ans = new int[carNums.size()];
        for(int i = 0; i < carNums.size(); i++){
            ans[i] = Integer.parseInt(arr[i][1]);
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