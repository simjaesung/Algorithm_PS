let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let [n] = input.shift();
let arr = input.shift();

function solution(){
	let max_score = 0;
	let min_score = 1000;
	
	for(let i = 0; i<n; i++){
		max_score = Math.max(arr[i],max_score);
		min_score = Math.min(arr[i],min_score);
	}
	console.log(max_score - min_score);
}

solution();