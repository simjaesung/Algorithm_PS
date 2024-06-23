const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

let L = input.shift();
let N = input.shift();
const arr = input;
const cake = new Array(1005).fill(0);

function solution(){
	let [a1,a2] = [0,0]; //예측 사람, 개수
	let [b1,b2] = [0,0]; //실제로 많이 받은 사람, 개수
	
	for(let i = 0; i<N; i++){
		let [s,e] = arr[i];
		
		if(e-s+1 > a1){
			a1 = e-s+1;
			a2 = i+1;
		}
		
		let tmp = 0;
		for(let j = s; j<=e; j++){
			if(cake[j] == 0){
				cake[j] = i+1;
				tmp++;
			}
		}
		
		if(tmp > b1){
			b1 = tmp;
			b2 = i+1;
		}
	}
	console.log(a2);
	console.log(b2);
}

solution();