let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((item) => +item);

function solution(){
	console.log(input[0] * input[1] + input[2] * input[3]);
}
solution();