const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
let T = +input[0];
let students = [];

for(let i = 1; i<input.length; i++){
    const arr = input[i].split(' ').map((item) => +item);
    students.push(arr);
}

solution(T,students);

function solution(c, arr){
    for(let i = 0; i<c; i++){
        console.log("Class",i+1);
        let cnt = arr[i][0];
        arr[i].shift();
        
        arr[i].sort((a,b) => b-a);
        let maxGap = 0;
        
        for(let j = 0; j<cnt-1; j++){
            if(arr[i][j] - arr[i][j+1] > maxGap){
                maxGap = arr[i][j] - arr[i][j+1];
            }
        }
        console.log("Max "+ arr[i][0] +", Min "+arr[i][cnt-1]+", Largest gap "+maxGap);
    }
}   