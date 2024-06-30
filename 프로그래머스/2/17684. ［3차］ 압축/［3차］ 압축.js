let map = new Map();
let arr = Array(26).fill().map((v, i) => String.fromCharCode(i + 65));
let key = 27;

arr.forEach((e,i)=>{
    map.set(e,i+1);
})

function solution(msg) {
    var answer = [];
    let a = 0;
    for(let i = 0; i < msg.length; i++){
        let tmp = msg.slice(a,i+1);
        if(map.has(tmp)) continue;
        else{
            answer.push(map.get(msg.slice(a,i)));
            map.set(tmp,key);
            key++;
            a = i;
        }
    }
    answer.push(map.get(msg.slice(a,msg.length)));
    
    return answer;
}