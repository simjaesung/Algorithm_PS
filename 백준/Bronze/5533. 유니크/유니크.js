let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let [n] = input.shift();
let arr = input;
const score = new Array(n).fill(0);
let tmp = new Array(105).fill(0);

function ans(){
	for(let i = 0; i<n; i++) console.log(score[i]);
}

function sol(){
	for(let i = 0; i<3; i++){
		for(let k = 0; k < n; k++) tmp[arr[k][i]]++;
		
		for(let s = 0; s < n; s++) {
			if(tmp[arr[s][i]] == 1) score[s] += arr[s][i];
		}
		
		tmp = new Array(105).fill(0);
	}
	
	ans();
}

sol();