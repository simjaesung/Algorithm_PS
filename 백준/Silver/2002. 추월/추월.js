const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
var map = new Map();

function solution(arr){
    let ans = 0;
    let n = +arr[0]; //정수처리꼭
    
    for(let i = 1; i<=n; i++) map.set(arr[i],i);
    
    for(let j = n+1; j<=2*n; j++){
        let s = map.get(arr[j]); //먼저나온 차량이 들어간 순서
        for(let k = j+1; k<=2*n; k++){
            let cmp = map.get(arr[k]); //뒤에 나오는 차량 들어간 순서
            if(s > cmp) {
                ans++;
                break;
            }
        }
     }
    console.log(ans);
}   

solution(input);