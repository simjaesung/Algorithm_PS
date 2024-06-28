let input = require('fs').readFileSync('/dev/stdin').toString().trim();
const mk = input;

function getMin(mk){
	let mkMin = "";
	let tmp = 0;
	for(let i = 0; i<mk.length; i++){
		if(mk[i] == 'M') tmp++;
		else{
			if(tmp > 0) {
				mkMin += '1';
				for(let k = 0; k < tmp-1; k++) mkMin += '0';
				mkMin += "5";
			}
			else mkMin += "5";
			tmp = 0;
		}

	}
	if(tmp > 0){
		mkMin += '1';
		for(let k = 0; k < tmp-1; k++) mkMin += '0';
	}
	return mkMin;
}

function getMax(mk){
	let mkMax = "";
	
	let tmp = 0;
	for(let i = 0; i<mk.length; i++){
		if(mk[i] == 'M') tmp++;
		else{
			mkMax += '5';
			for(let k = 0; k < tmp; k++) mkMax += '0';
			tmp = 0;
		}
	}
	
	if(tmp > 0) {
		for(let k = 0; k<tmp; k++) mkMax += '1';
	}
	return mkMax;
}


function solution(){
	console.log(getMax(mk));
	console.log(getMin(mk));
}
solution();