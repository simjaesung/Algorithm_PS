const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

const n = input.shift()[0];
const arr = input;
let ans = 0;
let dx = [0,1,0,-1];
let dy = [-1,0,1,0];

function inrange(x,y){
	return x >=0 && x <n && y >=0 && y < n;
}

let P = [0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05];
let sandX = [[-1,1,-1,1,-2,2,-1,1,0],
						 [-1,-1,0,0,0,0,1,1,2],
						 [-1,1,-1,1,-2,2,-1,1,0],
						[1,1,0,0,0,0,-1,-1,-2]];

let sandY = [[1,1,0,0,0,0,-1,-1,-2],
						[-1,1,-1,1,-2,2,-1,1,0],
						[-1,-1,0,0,0,0,1,1,2],
						[-1,1,-1,1,-2,2,-1,1,0]];

let alX = [0,1,0,-1];
let alY = [-1,0,1,0];

function sep(x,y,dr,sand){
	let tmp = 0;
	for(let u = 0; u<9; u++){
		let nx = x + sandX[dr][u];
		let ny = y + sandY[dr][u];
		if(!inrange(nx,ny)) ans += Math.floor(sand * P[u]);
		else arr[nx][ny] += Math.floor(sand * P[u]);
		tmp += Math.floor(sand * P[u]);
	}
	if(inrange(x + alX[dr], y + alY[dr])) arr[x + alX[dr]][y + alY[dr]] += sand - tmp;
	else ans += sand - tmp;
	
	arr[x][y] = 0;
}


function solution(n){
	let i = Math.floor(n/2),j = Math.floor(n/2);
	let k = 1;
	let dr = 0; //방향
	
	let cnt = 1,tmp = 0,twice = 0;
	
	while(k <= n*n){
		if(arr[i+dx[dr]][j+dy[dr]] > 0) 
			sep(i+dx[dr],j+dy[dr],dr,arr[i+dx[dr]][j+dy[dr]]);
		
		k++; tmp++;
		i += dx[dr]; 
		j += dy[dr];
		
		if(cnt == tmp){
			tmp = 0;
			twice ++;
			if(twice == 2) {
				twice = 0;
				cnt++;
			}
			dr = (dr + 1) % 4;
		}
	}
	
	console.log(ans);
}

solution(n);