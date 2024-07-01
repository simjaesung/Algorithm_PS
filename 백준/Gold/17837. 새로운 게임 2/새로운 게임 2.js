let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

let [n,k] = input.shift();
//let mal_arr = new Array(n+1).fill().map(()=>new Array(n+1).fill([]));
let mal_arr = new Array(n).fill().map(() => new Array(n).fill(''));

let arr = [];
let mal;

let dx = [0,0,-1,1];
let dy = [1,-1,0,0];

function inrange(x,y){
	return x >= 0 && x < n && y >= 0 && y <n;
}

function setGame(){
	for(let i = 0; i<n; i++) arr.push(input.shift());
	
	mal = input;

	for(let i = 0; i<k; i++){ //말판 세팅
		let [r,c,d] = mal[i];
		mal[i] = [r-1,c-1,d-1];
		mal_arr[r-1][c-1] += String(i);
	}
}

function next_mal(k,nx,ny){
	k = k.split('').map((item)=>+item);
	k.forEach((e,i)=>{
		mal[e][0] = nx;
		mal[e][1] = ny;
	})
}

function isWhite(i,cx,cy,nx,ny){
	let idx = mal_arr[cx][cy].indexOf(String(i));
	let k = mal_arr[cx][cy].slice(idx);
	mal_arr[nx][ny] += mal_arr[cx][cy].slice(idx);
	mal_arr[cx][cy] = mal_arr[cx][cy].slice(0,idx);
	next_mal(k,nx,ny);
}


function isRed(i,cx,cy,nx,ny){
	let idx = mal_arr[cx][cy].indexOf(String(i));
	let k = mal_arr[cx][cy].slice(idx);
	mal_arr[nx][ny] += k.split('').reverse().join('');
	mal_arr[cx][cy] = mal_arr[cx][cy].slice(0,idx);
	next_mal(k,nx,ny);
}

function isBlue(i,cx,cy,d){

	if(d == 0) d = 1;
	else if(d == 1) d = 0;
	else if(d == 2) d = 3;
	else if(d == 3) d = 2;
	
	mal[i][2] = d;
	
	let nx = cx + dx[d];
	let ny = cy + dy[d];
	if(!inrange(nx,ny) || arr[nx][ny] == 2) return;
	else if(arr[nx][ny] == 1) isRed(i,cx,cy,nx,ny);
	else if (arr[nx][ny] == 0) isWhite(i,cx,cy,nx,ny);
}

function check(){
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++) 
			if(mal_arr[i][j].length >= 4) return true;
	}
	return false;
}


function solution(){
	setGame();
	let turn = 1;
	while(turn <= 1000){
		//console.log(mal_arr);
		for(let i = 0; i<k; i++){
			let [cx,cy,d] = mal[i];
			let nx = cx + dx[d];
			let ny = cy + dy[d];
			
			if(!inrange(nx,ny) || arr[nx][ny] == 2) isBlue(i,cx,cy,d);
			else if(arr[nx][ny] == 1) isRed(i,cx,cy,nx,ny);
			else isWhite(i,cx,cy,nx,ny);
			
			if(check()) return turn;
		}
		turn++;
	}
	return -1;
}

// →, ←, ↑, ↓

console.log(solution());