const input = require('fs').readFileSync('/dev/stdin').toString().split(' ');
solution(+input)

function solution(len){
    let a = [];
    let b = [];
    a.push(1); a.push(0);
    b.push(0); b.push(1);
    
    for(let i = 2; i<=len; i++){
        a.push(a[i-2] + a[i-1]);
        b.push(b[i-2] + b[i-1]);
    }
    console.log(a[len], b[len]);
}   