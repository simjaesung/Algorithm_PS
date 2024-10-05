const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((item)=>item);
const [n,k] = [+input[0], +input[1]];
const check1 = [];
const check2 = {};
for(let i = 0; i < n; i++) check1.push(0);
let ans = 0;

const go = (s, depth) =>{
    if(depth === k && !check2[s]) {
        ans++;
        check2[s] = 1;
        return;
    }
    
    for(let i = 2; i < n+2; i++){
        if(check1[i-2]) continue;
        check1[i-2] = 1;
        go(s + input[i], depth + 1);
        check1[i-2] = 0;
    }
}

const sol = () => {
    go(0,0);
    console.log(ans);
}

sol();