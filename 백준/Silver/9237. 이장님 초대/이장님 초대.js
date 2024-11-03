const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

const [n] = input.shift();
const arr = input.shift();
arr.sort((a,b) => b - a);

const sol = () => {
    let ans = 0;
    for(let i = 0; i<n; i++) 
        ans = Math.max(ans, i + 1 + arr[i]);
    
    console.log(ans+1);
}

sol();