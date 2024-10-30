const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map(item => +item));
const [n] = input.shift();
const arr = new Array(1005).fill().map(()=>new Array(1005).fill(0));

const paint = (paper,cnt) => {
    let [a,b,c,d] = paper;
    for(let i = b; i<b+d; i++){
        for(let j = a; j<a+c; j++) 
            arr[i][j] = cnt;
    }
}

const answer = (paper,cnt) =>{
    let [a,b,c,d] = paper;
    let ans = 0;
     for(let i = b; i<b+d; i++){
        for(let j = a; j<a+c; j++) 
            if(arr[i][j] === cnt) ans++;
    }
    console.log(ans);
}

const sol = () => {
    for(let i = 0; i<n; i++){
        paint(input[i],i+1);
    }
    
    for(let i = 0; i<n; i++){
        answer(input[i],i+1);
    }
}   

sol();