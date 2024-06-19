function isPass(s){
    let len = s.length;
    let mo = 0; //연속모음
    let ja = 0; //연속자음
    let used = 0; //모음이 사용되었는지?
    
    //같은 문자
     for(let j = 0; j<len-1; j++){
        if(s[j] === s[j+1]){
            if(!(s[j] == 'o' || s[j] == 'e')) return false;
        }
    }
    
    //연속 3개 사용
    for(let i = 0; i<len; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            used = 1;
            mo++;
            ja = 0;
            if(mo == 3) return false;
        }
        else{
            mo = 0;
            ja++;
            if(ja == 3) return false;
        }
    }
    return used;
}

const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let i = 0;
while(input[i] !== "end"){
    if(isPass(String(input[i]))) console.log("<"+input[i]+"> is acceptable.");
    else console.log("<"+input[i]+"> is not acceptable.");
    i++;
}
