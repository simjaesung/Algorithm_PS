const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map(item => +item));

const [n] = input.shift();

const sol = () => {
    for(let i = 0; i<n; i++){
        let[v,e] = input[i];
        console.log(2 - (v-e));
    }
}   
sol();