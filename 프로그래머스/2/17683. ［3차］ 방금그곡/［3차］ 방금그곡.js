function rmPlat(s){
    s = s.replaceAll("C#","c");
    s = s.replaceAll("D#","d");
    s = s.replaceAll("F#","f");
    s = s.replaceAll("G#","g");
    s = s.replaceAll("A#","a");
    s = s.replaceAll("B#","b");
    return s;
}

function k(info){
    info = info.split(',');
    let tmp = [];
    info[3] = rmPlat(info[3]);
    let len = info[3].length;
    
    let hour = ( (+info[1].slice(0,2)) - (+info[0].slice(0,2))) * 60;
    let min = (+info[1].slice(3)) - (+info[0].slice(3));
    let time = hour + min;
    
    let sound = "";
    
    let a = Math.floor(time / len);
    let b = time % len;
    
    sound += info[3].repeat(a);
    for(let i = 0; i<b; i++) sound += info[3][i];
    
    tmp.push(time, info[2], sound);
    
    return tmp;
}

function compare(a,b){
    if(a[0] != b[0]) return b[0] - a[0];
}

function solution(m, musicinfos) {
    m = rmPlat(m);
    var answer = '(None)';
    
    let music = [];
    
    musicinfos.forEach((e,i)=>{
        music.push(k(e));
    })
    
    music.sort(compare);
    
    music.forEach((e,i)=>{
        if(e[2].includes(m)) {
            if(answer === '(None)') answer = e[1];
        }
    })
    
    return answer;
}