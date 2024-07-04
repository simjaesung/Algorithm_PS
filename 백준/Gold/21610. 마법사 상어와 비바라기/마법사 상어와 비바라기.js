let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

const [n,m] = input.shift();
let arr = [];
for(let i = 0; i < n; i++) arr.push(input.shift());
let cloud_loc = new Array(n).fill().map(()=>new Array(n).fill(0));

function inrange(x,y){
	return x >= 0 && x < n && y >=0 && y < n;
}

let dx = [0,-1,-1,-1,0,1,1,1];
let dy = [-1,-1,0,1,1,1,0,-1];

function getloc(x,y){
	if(x >= n) x = x % n;
	else if(x < 0) {
		while(x < 0) x += n;
	}
	if(y >= n) y = y % n;
	else if(y < 0) {
		while(y < 0) y += n;
	}
	return [x,y];
}

let cloud = [getloc(n-1,0),getloc(n-1,1),getloc(n-2,0),getloc(n-2,1)];

function setCloud(){
	for(let i = 0; i<cloud.length; i++){
		let [x,y] = cloud[i];
		cloud_loc[x][y] = 1;
	}
}

function resetCloud(){
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++) cloud_loc[i][j] = 0;
	}
}

//움직이고 비까지 내려줌
function moveCloud(d,s){
	let mx = dx[d-1] * s;
	let my = dy[d-1] * s;
	
	for(let i = 0; i<cloud.length; i++){
		let [x,y] = cloud[i];
		let nx = x + mx;
		let ny = y + my;
		[nx,ny] = getloc(nx,ny);
		cloud[i] = [nx,ny];
		arr[nx][ny]++; //비내림
	}
	resetCloud();
	setCloud();
}

function waterCopy(){
	for(let i = 0; i<cloud.length; i++){
		let cnt = 0;
		let [x,y] = cloud[i];
		for(let j = 2; j<=8; j+=2){
			let nx = x + dx[j-1];
			let ny = y + dy[j-1];
			if(!inrange(nx,ny)) continue;
			if(arr[nx][ny] > 0) cnt++;
		}
		arr[x][y] += cnt;
	}
}

function newCloud(){
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++) {
			if(arr[i][j] >= 2 && !cloud_loc[i][j]){
				cloud.push([i,j]);
				arr[i][j] -= 2;
			}
		}
	}
}

function answer(){
	let ans = 0;
	for(let i = 0; i<n; i++){
		for(let j = 0; j<n; j++) {
			ans += arr[i][j];
		}
	}
	return ans;
}

function solution(){
	for(let i = 0; i<m; i++){
		let[d,s] = input[i];
		moveCloud(d,s);
		waterCopy();
		cloud = [];
		newCloud();
	}
	console.log(answer());
}

solution();