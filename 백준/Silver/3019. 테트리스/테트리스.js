// Run by Node.js
const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let C = +input[0].split(' ')[0]; // 열
let k = +input[0].split(' ')[1]; // 블록번호
const arr = input[1].split(' ').map((item) => +item);

function soultion(c,block,arr){
	let ans = 0;
	if(block == 1){
		ans += c; //세로
		
		for(let i = 0; i<c-3; i++){
			if(arr[i] == arr[i+1] && arr[i] == arr[i+2] && arr[i] == arr[i+3]) ans++;
		}
	}
	else if(block == 2){
		for(let i = 0; i<c-1; i++){
			if(arr[i] == arr[i+1]) ans++;
		}
	}
	else if(block == 3){
		for(let i = 0; i<c-1; i++){
			if(arr[i] == arr[i+1]+1) ans++;
		}
		for(let i = 0; i<c-2; i++){
			if(arr[i] == arr[i+1] && arr[i] == arr[i+2] - 1) ans++;
		}
	}
	else if(block == 4){
		for(let i = 0; i<c-1; i++){
			if(arr[i]+1 == arr[i+1]) ans++;
		}
		for(let i = 0; i<c-2; i++){
			if(arr[i]-1 == arr[i+1] && arr[i]-1 == arr[i+2]) ans++;
		}
	}
	else if(block == 5){
		for(let i = 0; i<c-2; i++){
			if(arr[i] == arr[i+1] && arr[i] == arr[i+2]) ans++;
			else if(arr[i] == arr[i+1]+1 && arr[i] == arr[i+2]) ans++;
		}
		
		for(let i = 0; i<c-1; i++){
			if(arr[i] == arr[i+1]+1) ans++;
			else if(arr[i]+1 == arr[i+1]) ans++;
		}
	}
	else if(block == 6){
		for(let i = 0; i<c-2; i++){
			if(arr[i] == arr[i+1] && arr[i] == arr[i+2]) ans++;
			else if(arr[i]+1 == arr[i+1] && arr[i]+1 == arr[i+2])ans++;
		}
		for(let i = 0; i<c-1; i++){
			if(arr[i] == arr[i+1]) ans++;
			else if(arr[i] == arr[i+1]+2) ans++;
		}
	}
	else if(block == 7){
		for(let i = 0; i<c-2; i++){
			if(arr[i] == arr[i+1] && arr[i] == arr[i+2]) ans++;
			else if(arr[i] == arr[i+1] && arr[i] == arr[i+2]+1)ans++;
		}
		for(let i = 0; i<c-1; i++){
			if(arr[i] == arr[i+1]) ans++;
			else if(arr[i]+2 == arr[i+1]) ans++;
		}
	}
	
	console.log(ans);
}

soultion(C,k,arr);