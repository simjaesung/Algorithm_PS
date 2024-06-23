const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [n,m] = input.shift().split(' ');
input.map((el)=>el.split(''));
const arr = new Array(55).fill().map(()=>new Array(55).fill(0));
let ans = 0;

for(let i = 0; i<n; i++){
	for(let j = 0; j<m; j++){
		if(input[i][j] === '|') arr[i][j] = 1;
	}
}

//- 검사(0)
function checkRow(arr){
	for(let i = 0; i<n; i++){
		let tmp = 0;
		for(let j = 0; j<m; j++){
			if(arr[i][j] === 0) tmp = 1;
			else{
				ans += tmp;
				tmp = 0;
			}
		}
		ans += tmp;
	}
}

function checkCol(arr){
	for(let j = 0; j<m; j++){
		let tmp = 0;
		for(let i = 0; i<n; i++){
			if(arr[i][j] === 1) tmp = 1;
			else{
				ans += tmp;
				tmp = 0;
			}
		}
		ans += tmp;
	}
}

function solution(arr){
	checkCol(arr);
	checkRow(arr);
	console.log(ans);
}

solution(arr);