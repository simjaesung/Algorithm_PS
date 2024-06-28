let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

let [chick] = input[0];
let [a,b] = input[1];

function solution(){
	let ans = Math.floor(a / 2) + b;
	ans = Math.min(ans,chick);
	console.log(ans);
	
}
solution();

