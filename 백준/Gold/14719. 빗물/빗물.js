const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=>+item));

const [h,w] = input.shift();
const arr = input.shift();
let ans = 0;

const getH = (idx) => {
    let [leftH,rightH] = [0,0];
    
    for(let i = 0; i<idx; i++) 
        leftH = Math.max(leftH,arr[i]);
    
    for(let i = idx + 1; i < w; i++) 
        rightH = Math.max(rightH,arr[i]);
    
    if(arr[idx] < leftH && arr[idx] < rightH) 
        return Math.min(leftH,rightH);
    
    return false;
}

const sol = () => {
    for(let i = 0; i<w; i++){
        const tmp = getH(i);
        if(tmp) ans += (tmp - arr[i]);
    }
    console.log(ans);
}

sol();