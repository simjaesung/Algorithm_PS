const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const [n,m,k] = input.shift();

const sol = () => {
    console.log(Math.min(m,k)+Math.min(n-m,n-k));
}

sol();