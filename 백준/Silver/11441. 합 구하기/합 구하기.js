const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map(item => +item));
const [n] = input.shift();
const arr = input.shift();
const [m] = input.shift();
const sumArr = [];

const init = () => {
    sumArr.push(0);
    for(let i = 0; i<n; i++){
        sumArr.push(sumArr[i] + arr[i]);
    }
}

const sol = () => {
    init();
    for(let i = 0; i<m; i++){
        const[a,b] = input[i];
        console.log(sumArr[b] - sumArr[a-1]);
    }
}   

sol();