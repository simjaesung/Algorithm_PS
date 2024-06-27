let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const [n] = input.shift();
const arr = input;
let check = new Array(n+1).fill(0);
let ans = 1;
let same = 0;

function solution(){
	for(let i = 0; i<n; i++){
		for(let l = 0; l<n+1; l++) check[l] = 0;
		let cnt = 0; //같은 반이었던 서로 다른 학생 수
		for(let sem = 0; sem<5; sem++){
			let a = arr[i][sem];
			for(let j = 0; j<n; j++){
				if(i == j) continue;
				if(arr[i][sem] == arr[j][sem] && !check[j]){
					check[j] = 1;
					cnt++;
				}
			}
		}
		if(cnt > same){
			same = cnt;
			ans = i+1;
		}
	}
	
	console.log(ans);
}
solution();

