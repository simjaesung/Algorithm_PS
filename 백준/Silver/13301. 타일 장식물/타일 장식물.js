let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((item)=>+item);
let arr = [1,1];
let n = input[0];

function solution(){
	for(let i = 2; i<80; i++){
		arr.push(arr[i-1] + arr[i-2]);
	}
	if(n == 1) console.log(4);
	else console.log(arr[n-1] * 4 + arr[n-2] * 2 );
}

solution();