const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=> +item));

const [n] = input.shift();
const arr = input;
let [s1,s2] = [100,100];

const sol = () => {
    for(let i = 0; i<n; i++){
        const [a,b] = arr[i];
        if(a > b) s2 -= a;
        else if(a < b) s1 -= b;
    }
    console.log(s1);
    console.log(s2);
}   
sol();