import java.util.*;
class Solution {
    public List<Long> num = new ArrayList<>();
    public List<Character> oper = new ArrayList<>();
    public List<Character> operSet;
    public boolean[] used;
    public long ans;
    
    public long solution(String expression) {
        init(expression);
        List<Character> startOper = new ArrayList<>();
        go(startOper);
        return ans;
    }
    
    public void go(List<Character> selectOper){
        if(selectOper.size() == operSet.size()){
            cal(selectOper);
            return;
        }
        
        for(int i = 0; i < operSet.size(); i++){
            if(used[i]) continue;
            selectOper.add(operSet.get(i));
            used[i] = true;
            go(selectOper);
            
            used[i] = false;
            selectOper.remove(selectOper.size()-1);
        }
    }
    
    public void cal(List<Character> selectOper){
        List<Long> numCopy = new ArrayList<>(num);
        List<Character> operCopy = new ArrayList<>(oper);
        
        for(char select : selectOper){
            List<Long> tmpNum = new ArrayList<>();
            List<Character> tmpOper = new ArrayList<>();
            tmpNum.add(numCopy.get(0));
            
            for(int i = 1; i < numCopy.size(); i++){
                if(select == operCopy.get(i-1)){
                    long last = tmpNum.get(tmpNum.size() - 1);
                    tmpNum.remove(tmpNum.size() - 1);
                    if(select == '+') tmpNum.add(last + numCopy.get(i));
                    else if(select == '-') tmpNum.add(last - numCopy.get(i));
                    else tmpNum.add(last * numCopy.get(i));
                } else{
                    tmpNum.add(numCopy.get(i));
                    tmpOper.add(operCopy.get(i-1));
                }
            }
            numCopy = new ArrayList<>(tmpNum);
            operCopy = new ArrayList<>(tmpOper);
        }
        
        ans = Math.max(ans, Math.abs(numCopy.get(0)));
    }
    
    public void init(String expression){
        char[] arr = expression.toCharArray();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < expression.length(); i++){
            if(arr[i] != '+' && arr[i] != '-' && arr[i] != '*'){
                sb.append(arr[i]);
            }else{
                num.add(Long.parseLong(sb.toString()));
                oper.add(arr[i]);
                sb = new StringBuilder();
            }
        }
        
        num.add(Long.parseLong(sb.toString()));
        Set<Character> set = new HashSet<>(oper);
        operSet = new ArrayList<>(set);
        used = new boolean[operSet.size()];
    }
}