import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        Map<String, Integer> cache = new HashMap<>();
        Deque<String> queue = new ArrayDeque<>();
        
        int answer = 0;
        
        for(int i = 0; i < cities.length; i++){
            String city = cities[i].toLowerCase();
            
            if(cacheSize == 0){ //캐시 공간 없음
                answer += 5;
                continue;
            } else if(cache.containsKey(city)){ //캐시 히트
                answer += 1;
            } else if(cache.size() < cacheSize){  //캐시 공간 있음
                answer += 5;
            } else if(cache.size() == cacheSize){
                answer += 5;
                int min = i;
                String delCity = "";
                for(var cityInCache: cache.entrySet()){
                    if(min > cityInCache.getValue()) {
                        delCity = cityInCache.getKey();
                        min = cityInCache.getValue();
                    }
                }
                cache.remove(delCity);
            }
            cache.put(city, i);
        }
        
        return answer;
    }
}