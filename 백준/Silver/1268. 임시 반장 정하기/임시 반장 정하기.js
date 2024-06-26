let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item) => +item));
const [n] = input.shift();
const arr = input;
let same = new Array(n+1).fill().map(()=>new Array(0).fill([]));
function solution(){
	for(let j = 0; j < 5; j++){
		for(let i = 0; i < n; i++){
			let h = arr[i][j];//반
			for(let k = i+1; k < n; k++){
				if(arr[k][j] == h) {
					same[i+1].push(k+1);
					same[k+1].push(i+1);
				}
			}
		}
	}
	
	let max_cnt = 0;
	let ans = 1;
	for(let i = 1; i<=n; i++){
		let comp = new Set(same[i]);
		if(comp.size > max_cnt){
			max_cnt = comp.size;
			ans = i;
		}
	}
	console.log(ans);
}
solution();