const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=> el.split(' ').map((item)=>+item));
const [n,m] = input.shift();
let arr = new Array(n).fill().map(() => new Array(m).fill(0));

for(let i = 0; i<n; i++){
	for(let j = 0; j<m; j++){
		arr[i][j] = input[i][j] + input[i+n][j];
	}
}

let answer = "";

for(let i = 0; i <n; i++) {
	for (let j = 0; j < m; j++) answer += arr[i][j] + " ";
	answer += "\n";
}
console.log(answer.trim());
