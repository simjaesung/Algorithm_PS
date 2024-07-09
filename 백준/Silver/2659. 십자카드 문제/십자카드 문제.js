let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map((item)=>+item);
let val = input.join('');

let arr = new Array(10005).fill(0);

//시계수 조건이 되는지
function isClock(k){
	while(k > 0){
		if(k % 10 == 0) return false;
		k = Math.floor(k/10);
	}
	return true;
}

function minClock(k){
	let minval = String(k);
	let tmp = String(k).split('').map((item)=>+item);
	
	for(let i = 0; i<4; i++){
		tmp.push(tmp.shift());
		let l = tmp.join('');
		minval = Math.min(minval,l);
	}
	
	return minval;
}

function solution(){
	let ans = 0;
	val = minClock(val);
	for(let i = 1111; i<=9999; i++){
		if(!isClock(i)) continue;
		
		let clock = minClock(i);
		if(arr[clock]) continue;
		//console.log(clock);
		arr[clock] = 1;
		ans++;
		if(clock == val) break;
	}
	console.log(ans);
}
solution();