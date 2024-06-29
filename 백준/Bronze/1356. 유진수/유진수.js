let str = require('fs').readFileSync('/dev/stdin').toString().trim();

function getMult(k){
	let mult = 1;
	k = k.split('');
	k.forEach((e,i)=>{
		mult *= +e;
	})
	return mult;
}

function solution(){
	for(let i = 0; i<str.length-1; i++){
		let a = str.substr(0,i+1);
		let b = str.substr(i+1);
		
		if(getMult(a) == getMult(b)){
			console.log("YES");
			return;
		}
	}
	console.log("NO");
}

solution();