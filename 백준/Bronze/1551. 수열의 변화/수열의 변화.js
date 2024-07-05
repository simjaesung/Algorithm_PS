let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let [n,k] = input.shift().split(' ').map((i)=>+i);
let arr = input.shift().split(',').map((i)=>+i);
let s = n;


function solution(){
	while(k--){
		let tmp = [];
		for(let i = 0; i<s-1; i++) tmp.push(arr[i+1] - arr[i]);
		
		for(let i = 0; i<s-1; i++) arr[i] = tmp[i];
		s--;
	}
	
	
	let ans = "";
	for(let i = 0; i<s; i++) ans += arr[i] + ',';
	ans = ans.substr(0,ans.length-1);
	console.log(ans);
}

solution();