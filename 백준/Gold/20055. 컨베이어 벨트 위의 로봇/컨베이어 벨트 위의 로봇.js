let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item) => +item));
const [n,k] = input.shift();
let belt = input[0];
let robot = new Array(n).fill(0);

function solution(){
	let ans = 0;
	let wrong = 0;
	while(1){
		ans++;
		//1.벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
		let tmpBelt = belt.pop();
		belt = [tmpBelt,...belt];
		
		robot.pop();
		robot = [0,...robot];
		if(robot[n-1] == 1) robot[n-1] = 0;
		
		//2.가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 
		for(let r = n-2; r>=0; r--){
			if(robot[r] == 1 && robot[r+1] == 0 && belt[r+1] > 0){
				robot[r+1] = 1;
				robot[r] = 0;
				belt[r+1]--;
				if(belt[r+1] == 0) wrong++;
				
				if(r+1 == n-1) robot[r+1] = 0;
			}
		}
		//3.올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
		if(belt[0] > 0 && robot[0] == 0){
			robot[0] = 1;
			belt[0]--;
			if(belt[0] == 0) wrong++;
		}
		
		if(wrong >= k) break;
	}
	console.log(ans);
}
solution();