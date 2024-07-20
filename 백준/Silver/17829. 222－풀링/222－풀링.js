let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let [n] = input.shift();
let arr = input;

function getVal(r,c){
	let tmp = [arr[r][c], arr[r][c+1], arr[r+1][c], arr[r+1][c+1]];
	tmp.sort((a,b)=>a-b);
	return tmp[2];
}

function pooling(k){
	let result = [];
	for(let i = 0; i<k; i+=2){
		let rTmp = [];
		for(let j = 0; j<k; j+=2) rTmp.push(getVal(i,j));
		result.push(rTmp);
	}
	return result;
}

function sol(){
	while(n > 0){
		arr = pooling(n);
		if(arr.length == 1) return arr.shift()[0];
		n = Math.floor(n / 2);
	}
}

console.log(sol());