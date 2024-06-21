const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=> el.split(' ').map((item)=>+item));
let arr = new Array(9).fill().map(()=> new Array(9).fill(0));
let maxVal = 0;
for(let i = 0; i<9; i++){
	for(let j = 0; j<9; j++){
		arr[i][j] = input[i][j];
		maxVal = Math.max(arr[i][j],maxVal);
	}
}

function sol(arr,val){
	for(let i = 0; i<9; i++){
		for(let j = 0; j<9; j++){
			if(arr[i][j] == val){
				console.log(val);
				console.log(i+1,j+1);
			}
		}
	}
}

sol(arr,maxVal);