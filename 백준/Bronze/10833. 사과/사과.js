let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>(+item)));

const [n] = input.shift();

function sol(){
	let ans = 0;
	for(let i = 0; i<n; i++){
		let [a,b] = input[i];
		ans += b % a;
	}
	console.log(ans);
}

sol();