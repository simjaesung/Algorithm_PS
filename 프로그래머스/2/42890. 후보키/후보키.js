let answer = 0;
let arr;
let col,row;
let visit = new Array(10).fill(0);
let candid = [];

function isCandid(){
    let map = new Map();
    
    for(let i = 0; i<row; i++){
        let tmp = "";
        for(let j = 0; j<col; j++){
            if(visit[j]) tmp+= arr[i][j];
        }
        if(map.has(tmp)) return false;
        else map.set(tmp,1);
    }
    return true;
} 

function isAlreadyCandid(tmp){
    for(let i = 0; i<candid.length; i++){
        let cnt = 0;
        for(let l = 0; l<candid[i].length; l++){
            if(tmp.includes(candid[i][l])) cnt++;
        }
        if(cnt == candid[i].length) return false;
    }
    
    return true;
}

function go(k,cnt,idx){
    if(k == cnt){
        if(!isCandid()) return; 
        
        let tmp = "";
        for(let i = 0; i<col; i++){
            if(visit[i]) tmp += String(i);
        }
        if(!isAlreadyCandid(tmp)) return;
        
        candid.push(tmp);
        answer++;
        
        return;
    }
    
    for(let i = idx; i<col; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        go(k,cnt+1,i);
        visit[i] = 0;
    }
}

function solution(relation) {
    arr = relation; 
    col = relation[0].length;
    row = relation.length;
      
    for(let i = 1; i<=col; i++){
        for(let l = 0; l<col; l++) visit[l] = 0;
        go(i,0,0);
    } 
    
    return answer;
}