const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const [r,c,k] = input.shift();

let arr = new Array(100).fill().map(()=>new Array(100).fill(0));
let Tarr = new Array(100).fill().map(()=>new Array(100).fill(0));

for(let i = 0; i<3; i++){
	for(let j = 0; j<3; j++) arr[i][j] = input[i][j];
}

let row = 3, col = 3; //초기 세로 가로

function R(){
	let tmpCol = 0; //col 갱신
	//console.log("R");
	for(let i = 0; i<row; i++){
		let cntArr = []; //개수 세는
		let tmpArr = []; //복사할 값 넣는
		
		for(let j = 0; j<col; j++){
			let val = arr[i][j];
			
			if(val == 0) continue;
			
			let check = -1;
			
			for(let m = 0; m < cntArr.length; m++){
				if(cntArr[m][0] == val) check = m;
			}
			
			if(check == -1) cntArr.push([val,1]);
			else cntArr[check][1]++;
		}
		
		cntArr.sort((a,b)=> a[1] - b[1] || a[0] - b[0]);
		//개수를 기준으로 정렬, 같으면 수가 커지는 순
		//console.log(cntArr);
		
		for(let l = 0; l<cntArr.length; l++) {
			tmpArr.push(cntArr[l][0]);
			tmpArr.push(cntArr[l][1]);
		}
		
		//console.log(tmpArr);
		let len = tmpArr.length;
		if(len > 100) len = 100; 
		tmpCol = Math.max(len,tmpCol);
		for(let l = 0; l<len; l++) Tarr[i][l] = tmpArr[l];
	}
	col = tmpCol;
}

function C(){
	//console.log("C");
	let tmpRow = 0;
	for(let i = 0; i<col; i++){
		let cntArr = [];
		let tmpArr = []; //복사할 값 넣는
		for(let j = 0; j<row; j++){
			let val = arr[j][i];
			
			if(val == 0) continue;
			
			let check = -1;
			
			for(let m = 0; m < cntArr.length; m++){
				if(cntArr[m][0] == val) check = m;
			}
			
			if(check == -1) cntArr.push([val,1]);
			else cntArr[check][1]++;
		}
		
		cntArr.sort((a,b)=> a[1] - b[1] || a[0] - b[0]);
		//console.log(cntArr);
		
		for(let l = 0; l<cntArr.length; l++) {
			tmpArr.push(cntArr[l][0]);
			tmpArr.push(cntArr[l][1]);
		}
		
		//console.log(tmpArr);
		let len = tmpArr.length;
		if(len > 100) len = 100; 
		
		
		tmpRow = Math.max(tmpRow,len);
		for(let l = 0; l<len; l++) Tarr[l][i] = tmpArr[l];
	}
	row = tmpRow;
}

function CopyArr(){
	for(let s = 0; s<100; s++){
		for(let u = 0; u<100; u++) arr[s][u] = Tarr[s][u];
	}
}

function Print(){
	console.log("####");
	for(let i = 0; i<row; i++){
		let str = "";
		for(let j= 0; j<col; j++) str+=arr[i][j]+' ';
		console.log(str);
	}
	console.log("####")
}

function solution(){
	for(let i = 0; i<=100; i++){
		
		for(let s = 0; s<100; s++){
			for(let u = 0; u<100; u++) Tarr[s][u] = 0;
		}
		//console.log(row, col);
		if(arr[r-1][c-1] == k){
			console.log(i);
			return;
		}
		
		if(row >= col) R();
		else C();
		
		CopyArr();
		//console.log(row, col);
		//Print();
	}
	console.log(-1);
}

solution();