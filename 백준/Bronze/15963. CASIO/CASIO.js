// Run by Node.js
const input = require('fs').readFileSync('/dev/stdin').toString().split(' ');
let n = +input[0];
let m = +input[1];

function soultion(a,b){
	if(a == b) console.log(1);
	else console.log(0);
}

soultion(n,m);