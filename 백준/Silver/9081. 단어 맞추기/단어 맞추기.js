const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
let n = +(input.shift());
const c = new Array(100).fill(0);
let check = 0;

function next_per(n,s){
	let j = n-1;
	while(j>0 && s[j-1] >= s[j]) j--;
	
	let i = n-1;
	while(s[i] <= s[j-1]) i--;
	
	[s[i],s[j-1]] = [s[j-1],s[i]];
	i = n-1;
	while(i > j){
		[s[i],s[j]] = [s[j],s[i]];
		i--; j++;
	}
	console.log(s.join(''));
}

function solution(n,arr){
	for(let i = 0; i<n; i++){
		const arrCopy = [...arr[i]].sort().reverse();
		if(arrCopy.join('') === arr[i]) console.log(arr[i]);
		else next_per(arr[i].length,[...arr[i]]);
	}
}

solution(n,input);