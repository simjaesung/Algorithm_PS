let input = require('fs').readFileSync(0, 'utf-8').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

let [n] = input.shift();
const arr = [1,2,3];

const findIdx = (k) => {
	for(let i = 0; i < 3; i++){
		if(arr[i] === k) return i;
	}
}

const swap = (a,b) =>{
	let tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

const sol = () => {
	for(let i = 0; i<n; i++){
		let [a,b] = input[i];
		swap(findIdx(a),findIdx(b));
	}
	console.log(arr[0]);
}

sol();