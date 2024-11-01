const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' '));

const [n] = input.shift();
const obj = {};
const arr = [];

const init = () => {
    for(let item of input){
        const [,ext] = item[0].split('.');
        if(!obj[ext]) obj[ext] = 1; 
        else obj[ext]++;
    }
}

const setArr = () => {
    for(let ext of Object.keys(obj)) arr.push(ext);
    arr.sort();
}

const sol = () => {
    init();
    setArr();
    for(let ext of arr){
        console.log(`${ext} ${obj[ext]}`);
    }
}

sol();