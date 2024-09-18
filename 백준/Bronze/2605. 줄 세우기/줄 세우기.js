const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

const [n] = input.shift();
const s = input.shift();
const arr = [];

const sol = () => {
    for(let i = 0; i<n; i++) {
        if(s[i] === 0) arr.push(i+1);
        else arr.splice(i-s[i],0,i+1);
    }
    
    console.log(...arr);
}

sol();