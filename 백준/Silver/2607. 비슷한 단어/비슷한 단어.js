let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let n = +(input.shift());
const s = input.shift();

//같은 구성인지
function check1(s1, s2){
	let tmp1 = s1;
	let tmp2 = s2;

	for(let i = 0; i<s1.length; i++) tmp2 = tmp2.replace(s1[i],'');
	for(let i = 0; i<s2.length; i++) tmp1 = tmp1.replace(s2[i],'');
	
	if(tmp1.length == 0 && tmp2.length == 0) return true;
	else if(tmp1.length == 1 && tmp2.length == 1) return true;
	else if(tmp1.length == 1 && tmp2.length == 0) return true;
	else if(tmp1.length == 0 && tmp2.length == 1) return true;
	else return false;
}

function solution(){
	let ans = 0;
	for(let i = 0; i<n-1; i++){
		let s1,s2;
		
		if(s.length >= input[i].length) {
			s1 = s; s2 = input[i];
		}
		else{
			s1 =  input[i]; s2 = s;
		}
		if(check1(s1,s2)) ans++; 
	}
	console.log(ans);
}

solution();