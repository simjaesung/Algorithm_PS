const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const tmp_arr = new Array(70).fill().map(()=>new Array(70).fill(0)); //임시배열
const visit = new Array(70).fill().map(()=>new Array(70).fill(false));
const [n,q] = input.shift();
const magic = input.pop(); //시전단계배열
const arr = input;
let ans1 = 0;
let ans2 = 0;

const dx = [1,-1,0,0];
const dy = [0,0,1,-1];
function inrange(x,y){
	return x>=0 && x <2**n && y>=0 && y<2**n;
}

//회전 알고리즘
function rotate(y,x,t){
	t = 2**t;
	for(let i = 0; i<t; i++){
		for(let j = 0; j<t; j++){
			tmp_arr[y+j][x+t-i-1] = arr[y+i][x+j];
		}
	}
}

function melt(){
	const tmp_arr2 = new Array(70).fill().map(()=>new Array(70).fill(0));
	for(let i = 0; i<2**n; i++){
		for(let j = 0; j<2**n; j++){
			let cnt = 0;
			for(let k = 0; k<4; k++){
				let nx = i + dx[k];
				let ny = j + dy[k];
				if(!inrange(nx,ny)) continue;
				if(arr[nx][ny] > 0) cnt++;
			}
			if(cnt < 3 && arr[i][j] > 0) tmp_arr2[i][j] = arr[i][j]-1;
			else tmp_arr2[i][j] = arr[i][j];
		}
	}
	
	for(let i = 0; i<2**n; i++){
		for(let j = 0; j<2**n; j++) arr[i][j] = tmp_arr2[i][j];
	}
}

function bfs(x,y){
	let tmp = 0; // 최대값 갱신용
	const q = [];
	q.push([x,y]);
	visit[x][y] = 1;
	let idx = 0;
	while(idx < q.length){
		let[cx,cy] = q[idx++];
		tmp ++;
		for(let k = 0; k<4; k++){
			let nx = cx + dx[k];
			let ny = cy + dy[k];
			if(!inrange(nx,ny) || visit[nx][ny] || arr[nx][ny] == 0) continue;
			visit[nx][ny] = true;
			q.push([nx,ny]);
		}
	}
	ans2 = Math.max(ans2,tmp);
}

function solution(n,q,magic){
	for(let s = 0; s<q; s++){
		let t = magic[s];
		
		for(let i = 0; i<2**n; i+=2**t){
			for(let j = 0; j<2**n; j+=2**t) rotate(j,i,t);	
		}
		
		for(let i = 0; i<2**n; i++){
			for(let j = 0; j<2**n; j++) arr[i][j] = tmp_arr[i][j];
		}
		melt();
	}
	
	for(let i = 0; i<2**n; i++){
		for(let j = 0; j<2**n; j++){
			ans1 += arr[i][j];
			if(!visit[i][j] && arr[i][j] != 0) bfs(i,j);
		}
	}
	console.log(ans1);
	console.log(ans2);
}

solution(n,q,magic);