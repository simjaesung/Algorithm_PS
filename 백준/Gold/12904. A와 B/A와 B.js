const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let [s,t] = input;

const isB = (str) => {
    str = str.slice(0, str.length - 1);
    return str.split('').reverse().join('');
}

const isA = (str) => {
    return str.slice(0, str.length - 1);
}

const sol = () => {
    while(t.length > s.length){
        if(t[t.length-1] === 'A') t = isA(t);
        else t = isB(t);
    }
    (s === t)? console.log(1) : console.log(0);
}

sol();