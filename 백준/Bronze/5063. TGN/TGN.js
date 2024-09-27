const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

const [n] = input.shift();
const arr = input;

const sol = () => {
    arr.forEach((item)=>{
        let [r,e,c] = item;
        if(r < e - c) console.log("advertise");
        else if(r > e - c) console.log("do not advertise");
        else console.log("does not matter");
    })
}

sol();