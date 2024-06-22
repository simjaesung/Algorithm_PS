const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((item)=> +item);
let n = input;

function solution(){
	let ans = 0;
	for(let i = 1; i*i<=n; i++) ans++;
	console.log(ans);
}

solution();