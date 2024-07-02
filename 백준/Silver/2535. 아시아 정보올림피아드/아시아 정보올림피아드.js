let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').
map((el)=> el.split(' ').map((item)=>+item));

const [n] = input.shift();
let ans = [];
let map = new Map();

function compare(a,b){
	return b[2] - a[2];
}

input.sort(compare);

function solution(){
	for(let i = 0; i<n; i++){
		let [a,b,c] = input[i];
		if(map.has(a)){
			if(map.get(a) == 2) continue;
			else map.set(a,map.get(a) + 1);
		}
		else map.set(a,1);
		
		ans.push([a,b]);
			
		if(ans.length == 3) break;
	}
	
	for(let i = 0; i<3; i++){
		console.log(ans[i].join(' '));
	}
}

solution();