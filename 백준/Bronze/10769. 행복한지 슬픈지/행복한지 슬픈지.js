let input = require('fs').readFileSync(0, 'utf-8').toString().trim();
const sp = input.split('');

function sol(){
	let happy = 0;
	let sad = 0;
	
	for(let i = 0; i<sp.length-2; i++){
		if(sp[i] === ':'){
			let mood = sp[i] + sp[i+1] + sp[i+2];
			if(mood === ":-)") happy++;
			else if(mood === ":-(") sad++;
		}
	}
	if(!happy && !sad) console.log("none");
	else if(happy === sad) console.log("unsure");
	else if(happy > sad) console.log("happy");
	else console.log("sad");
}

sol();