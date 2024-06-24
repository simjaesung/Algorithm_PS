let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

let [n] = input.shift();
let like = new Array(405).fill().map(()=>new Array(4).fill(0));
let turn = [];

function inrange(x,y){
	return x>=0 && x<n && y>=0 && y<n;
}

let dx = [-1,0,0,1];
let dy = [0,1,-1,0];

for(let i = 0; i<n**2; i++){
	let val = input[i][0]; turn.push(val);
	for(let j = 1; j<=4; j++) like[val][j-1] = input[i][j];
}

let arr = new Array(n).fill().map(()=>new Array(n).fill(0));

function cntLike(x){
	let MaxLike = 0;
	let tmpArr = [];
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++){
			if(arr[i][j] == 0){
				let cnt = 0; //좋아하는 사람의 수
				let empty = 0; //주변 빈칸
				for(let k = 0; k<4; k++){
					let nx = i + dx[k];
					let ny = j + dy[k];
					if(!inrange(nx,ny)) continue;
					
					if(arr[nx][ny] == 0){
						empty++;
						continue;
					}
					
					if(like[x].includes(arr[nx][ny])) cnt++;
				}
				if(cnt > MaxLike){
					tmpArr = [];
					tmpArr.push([empty,i,j]);
					MaxLike = cnt;
				}
				else if(cnt == MaxLike) tmpArr.push([empty,i,j]);
			}
		}
	}
	
	tmpArr.sort((a,b)=> b[0] - a[0] || a[1] - b[1] || a[2] - b[2]);
	
	return tmpArr[0];
}

function solution(){
	for(let i = 0; i<n**2; i++){
		let [l,r,c] = cntLike(turn[i]);
		arr[r][c] = turn[i];
	}
	
	let ans = 0;
	
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++){
			let cnt = 0;
			for(let k = 0; k<4; k++){
				let nx = i + dx[k];
				let ny = j + dy[k];
				if(!inrange(nx,ny)) continue;
				if(like[arr[i][j]].includes(arr[nx][ny])) cnt++;
			}
			if(cnt == 0) continue;
			ans += 10 ** (cnt-1);
		}
	}
	console.log(ans);
}

solution();