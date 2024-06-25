let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const n = +input.shift();

let Roma = [1,5,10,50];
let ans = 0;
let check = new Array(1005).fill(0);

function go(s,k,idx){
	if(k == n){
		if(!check[s]){
			ans++;
			check[s] = 1;
		}
		return;
	}	
	for(let i = idx; i<4; i++){
		go(s+Roma[i],k+1,i);
	}
}

function solution(){
	go(0,0,0)
	console.log(ans);
}

solution();