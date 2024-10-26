const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' '));

const [n] = input.shift();
const [arr] = input.shift();
let [a,b] = [0,0];
const sol = () => {
    for(let i = 0; i<n; i++){
        if(arr[i] === 'A') a++;
        else b++;
    }
    
    if(a > b) console.log('A');
    else if(a < b) console.log('B');
    else console.log('Tie')
}   
sol();