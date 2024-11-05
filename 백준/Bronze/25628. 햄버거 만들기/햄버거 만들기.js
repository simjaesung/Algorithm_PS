const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const [a,b] = input.shift();

const sol = () => {
    console.log(Math.floor(Math.min(a/2,b)));
}

sol();