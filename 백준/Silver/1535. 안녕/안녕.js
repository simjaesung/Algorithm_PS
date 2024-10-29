const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map(item => +item));
const [n] = input.shift();
const L = input.shift();
const J = input.shift();
let ans = 0;

const go = (s,k,idx) =>{
    if(s < 100)ans = Math.max(ans,k);
    if(s >= 100 || idx >= n) return;
    
    go(s + L[idx], k + J[idx], idx+1);
    go(s,k,idx+1);
}

const sol = () => {
    go(0,0,0);
    console.log(ans);
}   

sol();