let map = new Map();

function solution(record) {
    var answer = [];
    
    for(let i = 0; i<record.length; i++){
        let tmp = record[i].split(' ');
        if(tmp[0] == "Enter") {
            if(map.has(tmp[1])) map.delete(tmp[1]);
            map.set(tmp[1],tmp[2]);
        }
        else if(tmp[0] == "Change"){
            map.delete(tmp[1]);
            map.set(tmp[1],tmp[2]);
        }
    }
    
    for(let i = 0; i<record.length; i++){
        let val = "";
        let tmp = record[i].split(' ');
        if(tmp[0] == "Enter") {
            val += map.get(tmp[1]) + "님이 들어왔습니다.";
            
        }
        else if(tmp[0] == "Leave"){
            val += map.get(tmp[1]) + "님이 나갔습니다.";
        }
        if(val) answer.push(val)
    }
    return answer;
}