const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=>+item));
const [n] = input.shift()
const [A,B]= input;

A?.sort((a,b) => a-b);
B?.sort((a,b) => b-a);

const sol = () => {
    let ans = 0;
    for(let i = 0; i<n; i++) ans += A[i] * B[i];
    
    console.log(ans); 
}

sol();