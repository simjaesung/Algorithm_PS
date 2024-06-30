function isNum(s){
    let number = '0123456789';
    return number.includes(s);
}

function select(file){
    let fileSelect = [];
    
    for(let i = 0; i<file.length; i++){
        if(isNum(file[i])){
            fileSelect.push(file.slice(0,i));
            file = file.slice(i);
            break;
        }
    }
    
    for(let i = 0; i<file.length; i++){
        if(!isNum(file[i])){
            fileSelect.push(file.slice(0,i));
            file = file.slice(i);
            break;
        }
    }
    fileSelect.push(file);
    return fileSelect;
}

let map = new Map();

function compare(a, b) {
    if(a[0].toLowerCase() !== b[0].toLowerCase()){
        return a[0].localeCompare(b[0]);
    }
    else if(+a[1] !== +b[1]){
        return (+a[1]) - (+b[1]);
    }
    else {
        return map.get(a.join('')) - map.get(b.join(''));
    }
}


function solution(files) {
    var answer = [];
    let tmp = [];
    files.forEach((e,i)=>{
        tmp.push(select(e));
        map.set(e,i);
    })
    
    tmp.sort(compare);
    
    tmp.forEach((e,i)=>{
        answer.push(e.join(''));
    })
    return answer;
    
}