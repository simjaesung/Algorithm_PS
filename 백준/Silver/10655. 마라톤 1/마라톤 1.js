let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let [n] = input.shift();
let arr = input;
let tmp1 = new Array(n).fill(0);
let tmp2 = new Array(n).fill(0);

function check1(){
	for(let i = 1; i<n; i++){
		tmp1[i] = Math.abs(arr[i][0] - arr[i-1][0])+ Math.abs(arr[i][1] - arr[i-1][1]);
	}
}

function check2(){
	for(let i = 2; i<n; i++){
		tmp2[i] = Math.abs(arr[i][0] - arr[i-2][0])+ Math.abs(arr[i][1] - arr[i-2][1]);
	}
}

function check3(){
	let k = 0;
	for(let i = 1; i<n-1; i++){
		k = Math.max(tmp1[i] + tmp1[i+1] - tmp2[i+1],k);
	}
	return k;
}

function sol(){
	check1();
	check2();
	let ans = tmp1.reduce((prev,cur)=>prev+cur);
	console.log(ans - check3());
}

sol();