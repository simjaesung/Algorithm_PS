const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=>+item));
const [n] = input.shift();

const sol = () => {
    for(let i = 0; i< 2*n; i++){
        if(i % 2 === 0) continue;
        console.log(input[i].reduce((acc,cur)=>{
            return acc + cur;
        }))
    }
}

sol();