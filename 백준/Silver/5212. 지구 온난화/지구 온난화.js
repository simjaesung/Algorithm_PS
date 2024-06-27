let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [r,c] = input.shift().split(' ').map((item)=>+item);
const land = input.map((el)=>el.split(''));
let arr = new Array(r).fill().map(()=>new Array(c).fill(0));

function inrange(x,y){
	return x>=0 && x < r && y >=0 && y < c;
}

let dx = [-1,1,0,0];
let dy = [0,0,1,-1];

let stx = r,sty = c;
let edx = 0,edy = 0;

function check(){
	for(let i = 0; i<r; i++){
		for(let j = 0; j<c; j++){
			if(land[i][j] == 'X'){
				let cnt = 0;
				for(let k = 0; k<4; k++){
					let nx = i + dx[k];
					let ny = j + dy[k];
					if(!inrange(nx,ny) || land[nx][ny] == '.') cnt++;
				}
				
				if(cnt < 3) arr[i][j] = 1; 
			}
		}
	}
}

function findLand(){
	for(let i = 0; i<r; i++){
		for(let j = 0; j<c; j++){
			if(arr[i][j]){
				stx = Math.min(stx,i);
				sty = Math.min(sty,j);
				edx = Math.max(edx,i);
				edy = Math.max(edy,j);
			}
		}
	}
}

function printLand(){
	for(let i = stx; i <= edx; i++){
		let tmp = "";
		for(let j = sty; j<= edy; j++){
			if(arr[i][j]) tmp+='X';
			else tmp+='.';
		}
		console.log(tmp);
	}
}

function solution(){
	check();
	findLand();
	printLand();
}
solution();

