const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=>+item));

const [n] = input.shift();
const isQS = input.shift();
const queuestack = input.shift();
const [m] = input.shift();
const C = input.shift();

let ans = [];

const sol = () => {
    for(let i = n-1; i>=0; i--){
        if(!isQS[i]) ans.push(queuestack[i]);
        if(ans.length === m) break;
    }
    
    if(ans.length < m){
        for(let i = 0; i<m; i++){
            ans.push(C[i]);
            if(ans.length === m) break;
        }
    }
    
    console.log(ans.join(' '));
}

sol();