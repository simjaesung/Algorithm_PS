const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const n = +input.shift();
var map = new Map();

function solution(arr){
	for(let i = 0; i<n; i++) map.set(arr[i],1);
	
	for(let i = 0; i<n; i++){
		let tmpStr = arr[i].split('');
		tmpStr.reverse();
		tmpStr = tmpStr.join('');
		
		if(map.has(tmpStr)){
			let w = Math.floor(arr[i].length / 2);
			console.log(arr[i].length, arr[i][w]);
			return;
		}
	}
}

solution(input);