let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

const [n] = input.shift(); //사람 수

let max_val = -1, per_val = 0;
let winner;
let c = new Array(5).fill(0);

function go(arr,k,cards){ //카드,사용한개수,합
	if(k == 3){
		per_val = Math.max(per_val,cards % 10);
		return;
	}
	for(let i = 0; i<5; i++){
		if(c[i]) continue;
		c[i] = 1;
		cards += arr[i];
		go(arr,k+1,cards);
		
		c[i] = 0;
		cards -= arr[i];
	}
}

function solution(){
	for(let i = 0; i<n; i++){
		per_val = 0;
		for(let k = 0; k<5; k++) c[k] = 0;
		go(input[i],0,0);
		
		if(per_val >= max_val){
			max_val = per_val;
			winner = i+1;
		}
	}
	
	console.log(winner);
}
solution();