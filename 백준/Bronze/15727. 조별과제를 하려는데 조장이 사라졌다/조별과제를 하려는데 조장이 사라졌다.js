const input = require('fs').readFileSync('/dev/stdin').toString().split(' ');
solution(+input)
function solution(a){
    let s = a % 5;
    if(s > 0) console.log(Math.floor(a/5) + 1);
    else console.log(a/5);
}   