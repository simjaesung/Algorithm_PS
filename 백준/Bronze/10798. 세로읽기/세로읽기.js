const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let arr = new Array(5).fill().map(()=> new Array(15).fill(-1));

for(let i = 0; i<input.length; i++){
	let len = input[i].length;
	for(let j = 0; j<len; j++) arr[i][j] = input[i][j];
}

function sol(arr){
	let ans = "";
	for(let j = 0; j<15; j++){
		for(let i = 0; i<5; i++) {
			if(arr[i][j] != -1) ans += arr[i][j]
		}
	}
	console.log(ans.trim());
}

sol(arr);