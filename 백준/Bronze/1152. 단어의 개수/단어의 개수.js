const arr = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');

function soultion(arr){
	let ans = 0;
	for(let i = 0; i<arr.length; i++){
		if(arr[i] !== '')ans++;
	}
	console.log(ans);
}

soultion(arr);