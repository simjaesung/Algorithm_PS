const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
let n = input.shift();

class Stack {
	constructor() {
		this._arr = [];
	}
	push(item) {
		this._arr.push(item);
	}
	pop() {
		return this._arr.pop();
	}
	top() {
		return this._arr[this._arr.length - 1];
	}
	size() {
		return this._arr.length;
	}
	isEmpty(){
		return this.size() == 0;
	}
}
const s = new Stack();

function sol(arr){
	let ans = 0;
	for(let i = 0; i<arr.length; i++){
		if(arr[i].length == 1){
			if(s.isEmpty()) continue;
			else{
				let[a,b] = s.top();
				s.pop();
				if(b-1 == 0) ans += a;
				else s.push([a,b-1])
			}
		}
		else{
			let[t,a,b] = arr[i];
			if(b-1 == 0) ans += a;
			else s.push([a,b-1]);
		}
	}
	
	console.log(ans);
}

sol(input);