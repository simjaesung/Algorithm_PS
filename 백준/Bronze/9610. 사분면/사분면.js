const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map(item => +item));
const [n] = input.shift();
const arr = new Array(5).fill(0);

const ans = () => {
    for(let i = 0; i<4; i++) console.log(`Q${i+1}: ${arr[i]}`);
    console.log(`AXIS: ${arr[4]}`);
}

const sol = () => {
    for(let i = 0; i<n; i++){
        const [x,y] = input[i];
        if(x === 0 || y === 0) arr[4]++;
        else if(x > 0 && y > 0) arr[0]++;
        else if(x < 0 && y > 0) arr[1]++;
        else if(x < 0 && y < 0) arr[2]++;
        else arr[3]++;
    }
    ans();
}

sol();