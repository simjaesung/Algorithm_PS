function solution(n, t, m, p) {
    var answer = '';
    let num = 0;
    let turn = 0;
    while(1){
        let val = num.toString(n);
        
        for(let i = 0; i<val.length; i++){
            if((turn % m) + 1 == p) {
                if(isNaN(val[i])) answer += val[i].toUpperCase();
                else answer += val[i];
            }
            if(answer.length == t) break;
            turn++;
        }
        
        if(answer.length == t) break;
        num++;
    }
    return answer;
}