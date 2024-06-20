// Run by Node.js
const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let n = +input[0];
let arr = [];
var map = new Map();
for(let i = 1; i<=n; i++) arr.push(input[i]);

function soultion(k,arr){
	for(let i = 0; i<n; i++){
		let tmp = arr[i].split(' ');
		let check = 0;
		//우선 첫문자
		for(let j = 0; j<tmp.length; j++){
			if(map.has(tmp[j][0].toLowerCase()) == false){
				map.set(tmp[j][0].toLowerCase(),1);
				check = 1;
				
				tmp[j] = tmp[j].replace(tmp[j][0],"["+tmp[j][0]+"]");
				arr[i] = tmp[j];
				break;
			}
		}
		if(check) {
			arr[i] = tmp.join(' ');
			continue;
		}
		
		for(let j = 0; j<tmp.length; j++){
			let check2 = 0;
			for(let k = 0; k<tmp[j].length; k++){
				if(map.has(tmp[j][k].toLowerCase()) == false){
					map.set(tmp[j][k].toLowerCase(),1);
					check2 = 1;
					tmp[j] = tmp[j].replace(tmp[j][k],"["+tmp[j][k]+"]");
					arr[i] = tmp.join(' ');
					break;
					}
			}
			if(check2) break;
		}
		
	}
	for(let m = 0; m<k; m++)console.log(arr[m])
}

soultion(n,arr);