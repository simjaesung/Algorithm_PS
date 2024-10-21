const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' ').map((item)=>+item));
const [n] = input.shift();
input?.sort((a,b) => a[0] - b[0]);
const arr = new Array(1005).fill().map(()=>new Array(1005).fill(0));

const initArr = (idx) => {
    const [l,h] = input[idx];
    for(let i = 0; i<h; i++) arr[l][i] = 1;
}

const checkLeft = (idx) =>{
    const [l1,h1] = input[idx];
    let [tmpL,tmpH] = [0,0];
    
    for(let i = idx-1; i>0; i--){
        const [l2,h2] = input[i];
        if(h2 >= h1 && h2 > tmpH) tmpL = l2;
    }
    if(tmpL){
        for(let i = tmpL; i<l1; i++){
            for(let j = 0; j<h1; j++) 
                arr[i][j] = 1;
        }
    }
}

const checkRight = (idx) =>{
    const [l1,h1] = input[idx];
    let [tmpL,tmpH] = [0,0];
    
    for(let i = idx; i<n; i++){
        const [l2,h2] = input[i];
        if(h2 >= h1 && h2 > tmpH) tmpL = l2;
    }
    
    if(tmpL){
        for(let i = l1; i<tmpL; i++){
            for(let j = 0; j<h1; j++) 
                arr[i][j] = 1;
        }
    }
    
}

const sol = () => {
    for(let i = 0; i<n; i++){
        initArr(i);
        checkLeft(i);
        checkRight(i);
    }
    
    let ans = 0;
    
    for(let i = 0; i<1005; i++){
        for(let j = 0; j<1005; j++){
            if(arr[i][j] === 1) ans++;
            
        }
    }
    console.log(ans);
}

sol();