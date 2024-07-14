let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let [n,m] = input.shift();
let arr = new Array(105).fill().map(()=>new Array(105).fill(0));

function cnt(){
	let ans = 0;
	for(let i = 1; i<=100; i++){
		for(let j = 1; j<=100; j++){
			if(arr[i][j] > m) ans++;
		}
	}
	return ans;
}

function solution(){
	for(let i = 0; i<n; i++){
		let [x1,y1,x2,y2] = input[i];
		for(let j = x1; j<=x2; j++){
			for(let k = y1; k <= y2; k++) arr[j][k]++;
		}
	}
	console.log(cnt());
}

solution();