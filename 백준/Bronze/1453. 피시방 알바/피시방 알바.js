const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=> +item));

const [n] = input.shift();
const arr = input.shift();
const c = new Array(105).fill(0);

const sol = () => {
    let ans = 0;
    arr?.forEach((k)=>{
        if(!c[k]) c[k] = 1;
        else ans++;
    })
    console.log(ans);
}   
sol();