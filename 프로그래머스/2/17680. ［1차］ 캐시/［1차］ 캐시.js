let cache = new Map();

function LRU(city,i){
    let arr = [...cache];
    arr.sort((a,b)=>a[1] - b[1]);
    cache.delete(arr[0][0]);
    cache.set(city,i);
}

function solution(cacheSize, cities) {
    var answer = 0;
    let remain = cacheSize;
    
    for(let i = 0; i<cities.length; i++){
        cities[i] = cities[i].toLowerCase();
        if(cache.has(cities[i])) {
            cache.set(cities[i],i);
            answer +=1;
        }
        else{
            if(remain > 0){
                cache.set(cities[i],i);
                remain--;
            }
            else{
                if(cacheSize > 0) LRU(cities[i],i);
            }
            answer += 5;
        }
        
    }
    return answer;
}