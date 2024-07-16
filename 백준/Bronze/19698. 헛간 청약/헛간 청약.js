let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split(' ');
let [n,w,h,l] = input;
w = parseInt(w/l)
h = parseInt(h/l)
let sum = w * h
if(n >= sum) console.log(sum);
else console.log(n);