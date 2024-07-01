let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

let [n] = input.shift();
let arr = new Array(105).fill().map(()=>new Array(105).fill(0));

function setDool(a,b){
	for(let i = a; i< a + 10; i++){
		for(let j = b; j< b + 10; j++) arr[i][j] = 1;
	}
}


function cntDool(){
	let ans = 0;
	for(let i = 0; i<100; i++){
		for(let j = 0; j<100; j++) 
			if(arr[i][j] == 1) {
				if(i == 0 || arr[i-1][j] == 0) ans++;
				if(j == 0 || arr[i][j-1] == 0) ans++;
				if(i == 99 || arr[i+1][j] == 0) ans++;
				if(j == 99 || arr[i][j+1] == 0) ans++;
			}
	}
	return ans;
}


function solution(){
	for(let i = 0; i<n; i++){
		let [a,b] = input[i];
		setDool(a,b);
	}
	console.log(cntDool());
}

solution();