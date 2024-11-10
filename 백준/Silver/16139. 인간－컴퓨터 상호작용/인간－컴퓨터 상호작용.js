let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n');
const S = input[0];
const n = +input[1];
const obj = new Array(S.length).fill({});

const init = () => {
	obj[0][S[0]] = 1;
	for(let i = 1; i<S.length; i++) {
		let tmp = {...obj[i-1]};
		if(tmp[S[i]]) tmp[S[i]]++;
		else tmp[S[i]] = 1;
		obj[i] = tmp;
	}
}

const sol = () => {
	init();
	for(let i = 2; i<2+n; i++){
		const [a,l,s] = input[i].split(' ');
		const [tmp1,tmp2] = [obj[l], obj[s]];
		if(tmp1[a]) {
			if(S[l] === a) console.log(tmp2[a] - tmp1[a] + 1);
			else console.log(tmp2[a] - tmp1[a]);
		} else{
			if(tmp2[a]) console.log(tmp2[a]);
			else console.log(0);
		}
	}
}

sol();