function isNum(s){
    let num = '0123456789';
    if(num.includes(s)) return true;
    else false;
}

function solution(dart) {
    var answer = [];
    
    let val = +(dart[0]);
    for(let i = 1; i<dart.length; i++){
        let s = dart[i];
        if(isNum(s)) {
            console.log(val);
            if(!isNum(dart[i-1])) {
                answer.push(val);
                val = +(dart[i]);
            }
            else val = 10;
        }
        else if(s == 'S') val = val**1;
        else if(s == 'D') val = val**2;
        else if(s == 'T') val = val**3;
        else if(s == '*'){
            if(answer.length > 0){
                answer[answer.length-1] *= 2;
            }
            val *= 2;
        }
        else if(s == '#') val = val * -1;
    }
    answer.push(val);
    
    let ans = 0;
    for(let i = 0; i<3; i++) ans += answer[i];
    return ans;
}