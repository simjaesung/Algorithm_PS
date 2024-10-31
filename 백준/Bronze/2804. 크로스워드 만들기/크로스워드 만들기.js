const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');
const [a,b] = input;
const [n,m] = [a.length, b.length];
const arr = new Array(m).fill().map(()=>new Array(n).fill('.'));

const findIdx = (a,b) =>{
    for(let i = 0; i<n; i++){
        for(let j = 0; j<m; j++){
            if(a[i] === b[j]) return [i,j];
        }
    }
}

const row = (x) =>{
    for(let i = 0; i<n; i++) arr[x][i] = a[i];
}

const col = (y) =>{
    for(let i = 0; i<m; i++) arr[i][y] = b[i];
}

const sol = () => {
    const [x,y] = findIdx(a,b);
    row(y);
    col(x);
    for(let i = 0; i<m; i++) console.log(arr[i].join(''));
}   

sol();