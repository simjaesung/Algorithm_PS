const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let n = input.shift();

function sol(arr){
	let ans = 0;
	let s = [];
	for(let i = 0; i<arr.length; i++){
		if(arr[i].length == 1){
			if(s.length == 0) continue;
			else{
				let[a,b] = s[s.length-1];
				
				if(b-1 == 0) {
					ans += a;
					s.pop();
				}
				else s[s.length-1][1]--;
			}
		}
		else{
			let[t,a,b] = arr[i];
			if(b-1 == 0) ans += a;
			else s.push([a,b-1]);
		}
	}
	
	console.log(ans);
}

sol(input);