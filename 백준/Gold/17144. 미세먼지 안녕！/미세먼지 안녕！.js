const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const [r,c,t]  = input.shift();
const R = [];
const arr = input;

let dx = [-1,1,0,0];
let dy = [0,0,-1,1];

function inrange(x,y){
	return x >=0 && x<r && y>=0 && y<c;
}

//공기청소기 위치
for(let i = 0; i<r; i++){
	for(let j = 0; j<c; j++) 
		if(arr[i][j] == -1) R.push([i,j]);
}

function diffusion(){
	const tmpArr = new Array(r).fill().map(()=>new Array(c).fill(0));
	for(let i = 0; i<r; i++){
		for(let j = 0; j<c; j++){
			if(arr[i][j] > 0){
				let cnt = 0;
				for(let k = 0; k<4; k++){
					let nx = i + dx[k];
					let ny = j + dy[k];
					if(!inrange(nx,ny) || arr[nx][ny] == -1) continue;
					cnt++;
					tmpArr[nx][ny] += Math.floor(arr[i][j] / 5);
				}
				tmpArr[i][j] += arr[i][j] - Math.floor(arr[i][j] / 5) * cnt;
			}
		}
	}
	
	for(let i = 0; i<r; i++){
		for(let j = 0; j<c; j++) {
			if(arr[i][j] != -1) arr[i][j] = tmpArr[i][j];
		}
	}
}

function rotate(x1,y1,x2,y2){
	const tmpArr = new Array(r).fill().map(()=>new Array(c).fill(0));
	//위에꺼 먼저
	for(let i = 1; i<c-1; i++) tmpArr[x1][i+1] = arr[x1][i];
	for(let i = x1; i>0; i--) tmpArr[i-1][c-1] = arr[i][c-1];
	for(let i = c-1; i>0; i--) tmpArr[0][i-1] = arr[0][i];
	for(let i = 0; i<x1; i++) tmpArr[i+1][0] = arr[i][0];
	
	//아래꺼
	for(let i = 1; i<c-1; i++) tmpArr[x2][i+1] = arr[x2][i];
	for(let i = x2; i<r-1; i++) tmpArr[i+1][c-1] = arr[i][c-1];
	for(let i = c-1; i>0; i--) tmpArr[r-1][i-1] = arr[r-1][i];
	for(let i = r-1; i>x2; i--) tmpArr[i-1][0] = arr[i][0];
	
	//복사
	for(let i = 1; i<c; i++) {
		arr[x1][i] = tmpArr[x1][i];
		arr[x2][i] = tmpArr[x2][i];
	}
	
	for(let i = 0; i<c; i++){
		arr[r-1][i] = tmpArr[r-1][i];
		arr[0][i] = tmpArr[0][i];
	}
	
	for(let i = 0; i<r; i++){
		if(arr[i][0] != -1 )arr[i][0] = tmpArr[i][0];
		arr[i][c-1] = tmpArr[i][c-1];
	}
	
}
function solution(r,c,t){
	for(let tc = 0; tc < t; tc++){
		diffusion();
		// console.log("확산후 ");
		// for(let i = 0; i<r; i++) console.log(arr[i].join(' '));
		
		rotate(R[0][0],R[0][1],R[1][0],R[1][1]);
		// console.log("\n공기청정기 후");
		// for(let i = 0; i<r; i++) console.log(arr[i].join(' '));

	}
	
	let ans = 0;
	for(let i = 0; i<r; i++){
		for(let j = 0; j<c; j++) if(arr[i][j] != -1) ans += arr[i][j];
	}
	console.log(ans);
}

solution(r,c,t);