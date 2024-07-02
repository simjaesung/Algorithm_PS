let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((item) => +item);
let [n,k] = input;

function solution(){
	let ans = 0;
	for(let i = 1; i<=n; i++){
		let tmp = i;
		while(tmp > 0){
			if(tmp % 10 == k) ans++;
			tmp = Math.floor(tmp / 10);
		}
	}
	console.log(ans);
}

solution();