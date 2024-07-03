let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=> el.split(' ').map((item)=>+item));
const [n,m]  = input.shift();
let arr = input;
let visit = new Array(n).fill().map(()=>new Array(n).fill(0));

let bx = -1, by = -1;
let cnt = 2;
let dx = [-1,1,0,0];
let dy = [0,0,-1,1];
function inrange(x,y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

function reset(){
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++) visit[i][j] = 0;	
	}
}

function rainbow_reset(){
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++) {
			if(arr[i][j] == 0) visit[i][j] = 0;
		}	
	}
}

function findGroup(x,y,color){
	let size = 0;
	let rainbow = 0;
	let q = [];
	q.push([x,y]);
	visit[x][y] = 1;
	while(q.length > 0){
		let [cx,cy] = q.shift();
		if(arr[cx][cy] == 0) rainbow++;
		size++;
		for(let i = 0; i<4; i++){
			let nx = cx + dx[i];
			let ny = cy + dy[i];
			if(!inrange(nx,ny)) continue;
			if(arr[nx][ny] == -1 || arr[nx][ny] == 'x') continue;
			if(arr[nx][ny] != 0 && arr[nx][ny] != color) continue;
			if(visit[nx][ny]) continue;
			visit[nx][ny] = 1;
			q.push([nx,ny]);
		}
	}
	return [size,rainbow];
}

function delGroup(x,y,color){
	let q = [];
	q.push([x,y]);
	visit[x][y] = 1;
	
	while(q.length > 0){
		let [cx,cy] = q.shift();
		arr[cx][cy] = 'x';
		for(let i = 0; i<4; i++){
			let nx = cx + dx[i];
			let ny = cy + dy[i];
			if(!inrange(nx,ny)) continue;
			if(arr[nx][ny] == -1 || arr[nx][ny] == 'x') continue;
			if(visit[nx][ny]) continue;
			if(arr[nx][ny] != 0 && arr[nx][ny] != color) continue;
			visit[nx][ny] = 1;
			q.push([nx,ny]);
		}
	}
}

function grav(){
	for(let j = 0; j<n; j++){
		let tmp = [];
		for(let i = 0; i<n; i++){
			if(arr[i][j] != -1){
				if(arr[i][j] == 'x') tmp.push(arr[i][j]);
				else tmp.unshift(arr[i][j]);
			}
			else{
				let tmp_i = i-1;
				while(tmp.length > 0){
					arr[tmp_i][j] = tmp.shift();
					tmp_i--;
				}
			}
		}
		let tmp_i = n-1;
		while(tmp.length > 0){
			arr[tmp_i][j] = tmp.shift();
			tmp_i--;
		}
	}
}

function rot(){
	let tmp_arr = new Array(n).fill().map(()=>new Array(n).fill(0));
	
	for(let j = n-1; j >=0; j--){
		for(let i = 0; i < n; i++){
			tmp_arr[n-1-j][i] = arr[i][j];
		}
	}
	
	for(let i = 0; i < n; i++){
		for(let j = 0; j<n; j++){
			arr[i][j] = tmp_arr[i][j];
		}
	}
}

function solution(){
	let ans = 0;
	while(1){
		//console.log(arr);
		bx = -1; 
		by = -1;
		cnt = 1;
		r_cnt = 0;
		
		reset();//방분기록 초기화
		
		for(let i = 0; i<n; i++){
			for(let j = 0; j<n; j++){
				if(arr[i][j] == 0 || arr[i][j] == -1 || arr[i][j] == 'x') continue;
				
				if(!visit[i][j]) {
					let [tmp_cnt,rainbow] = findGroup(i,j,arr[i][j]);
					rainbow_reset();
					
					if(tmp_cnt == 1) continue;
					
					if(tmp_cnt > cnt){
						bx = i; by = j;
						
						cnt = tmp_cnt;
						r_cnt = rainbow;
					}
					else if(tmp_cnt == cnt){
						if(rainbow >= r_cnt){
							bx = i; by = j;
							r_cnt = rainbow;
						}
					}
				}
			}
		}
		
		if(bx == -1 && by == -1) break;
		ans += cnt ** 2;
		reset();//방분기록 초기화
		delGroup(bx,by,arr[bx][by]);
		grav();
		rot();
		grav();
	}
	console.log(ans);
}


solution();