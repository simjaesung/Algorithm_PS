const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let arr = new Array(105).fill().map(()=> new Array(105).fill(0));
let n = input.shift();

for(let i = 0; i<n; i++){
	let [a,b] = input[i];
	for(let j = a; j<a+10; j++){
		for(let k = b; k<b+10; k++) arr[j][k] = 1;
	}
}

function sol(arr){
	let ans = 0;
	for(let i = 0; i<105; i++){
		for(let j = 0; j<105; j++) {
			if(arr[i][j]) ans++;
		}
	}
	console.log(ans);
}

sol(arr);