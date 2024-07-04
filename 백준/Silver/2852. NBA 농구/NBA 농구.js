let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' '));
const n = +input.shift();
const note = input;

let scoreA = 0, scoreB = 0;
let MA = 0, SA = 0;
let MB = 0, SB = 0;

function subTime(a,b){
	//a가 더 큰 시간
	a = a.split(':');
	b = b.split(':');
	//console.log(a,b);
	let hour = (+a[0]) - (+b[0]);
	let minu = (+a[1]) - (+b[1]);
	
	if(minu < 0){
		hour --;
		minu = 60 + minu;
	}
	return [hour,minu]
}

function getS(s){
	s = String(s);
	if(s.length == 1) s = '0'+s;
	return s;
}

function solution(){
	for(let i = 0; i<n-1; i++){
		let[t1,time1] = note[i];
		let[t2,time2] = note[i+1];
		
		if(t1 == 1) scoreA++;
		else scoreB++;
		
		let [h,m] = subTime(time2,time1);
		
		if(scoreA > scoreB){
			MA += h;
			SA += m;
			if(SA >= 60){
				MA ++;
				SA -= 60;
			}
		}
		else if(scoreB > scoreA){
			MB += h;
			SB += m;
			if(SB >= 60){
				MB ++;
				SB -= 60;
			}
		}
	}
	
	let[t,time] = note[n-1];
	if(t == 1) scoreA++;
	else scoreB++;
	let [h,m] = subTime("48:00",time);
	
	if(scoreA > scoreB){
			MA += h;
			SA += m;
			if(SA >= 60){
				MA ++;
				SA -= 60;
			}
		}
		else if(scoreB > scoreA){
			MB += h;
			SB += m;
			if(SB >= 60){
				MB ++;
				SB -= 60;
			}
		}
	
	console.log(getS(MA)+':'+getS(SA));
	console.log(getS(MB)+':'+getS(SB));
}

solution();