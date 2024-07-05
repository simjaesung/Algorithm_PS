let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const n = +input.shift();

function solution(){
	for(let i = 0; i<n; i++){
		let move = input[i];
		let d = 0; //방향
		let up = 0, left = 0, down = 0, right = 0;
		let a = 0, b = 0; //가로 세로
		
		let maxa = 0, mina = 0;
		let maxb = 0, minb = 0;
		for(let k = 0; k < move.length; k++){
			if(move[k] == 'F'){
				if(d == 0) a ++;
				else if(d == 1) b++;
				else if(d == 2) a--;
				else b--;
			}
			else if(move[k] == 'B'){
				if(d == 0) a--;
				else if(d == 1) b--;
				else if(d == 2) a++;
				else b++;
			}
			else if(move[k] == 'L') d  = (d + 1) % 4;
			else if(move[k] == 'R'){
				d--;
				if(d < 0) d += 4;
			}
			
			if(a > 0) maxa = Math.max(a,maxa);
			else if(a < 0) mina = Math.min(mina,a);
			
			if(b > 0) maxb = Math.max(b,maxb);
			else if(b < 0) minb = Math.min(minb,b);
		}
		
		console.log((maxa - mina) * (maxb - minb));
	}
}

solution();