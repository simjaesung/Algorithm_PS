let check = new Array(505).fill(0);

function solution(N, stages) {
    var answer = [];
    var tmp = [];
    
    for(let i = 0; i<stages.length; i++) check[stages[i]]++;
    
    let remain = stages.length;
    
    for(let i = 1; i<=N; i++){
        if(check[i] == 0) tmp.push([0,i]);
        else{
            tmp.push([check[i] / remain,i]);
            remain -= check[i];
        }
    }
   
    tmp.sort((a,b) => b[0] - a[0] || a[1] - b[1]);
    //return tmp;
    for(let i = 0; i<N; i++) answer.push(tmp[i][1]);
    
   
    return answer;
}