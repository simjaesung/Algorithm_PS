const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' '));
const [p,s] = input.shift().map(item => +item);
const cnt = input?.pop()?.map(item => +item) || [];
const cntTmp = new Array(4).fill(0);
const str = input?.shift()?.shift().split('');

let ans = 0;

const init = () => {
    for(let i = 0; i<s; i++) addCnt(str[i]);
}

const addCnt = (val) => {
    if(val === 'A') cntTmp[0]++;
    else if(val === 'C') cntTmp[1]++;
    else if(val === 'G') cntTmp[2]++;
    else cntTmp[3]++;
}

const minusCnt = (val) => {
    if(val === 'A') cntTmp[0]--;
    else if(val === 'C') cntTmp[1]--;
    else if(val === 'G') cntTmp[2]--;
    else cntTmp[3]--;
}

const checkCnt = () =>{
    for(let i = 0; i<4; i++){
        if(cnt[i] > cntTmp[i]) return false;
    }
    ans++;
    return true;
}

const sol = () => {
    init();
    checkCnt();
    for(let i = s; i<p; i++){
        addCnt(str[i]);
        minusCnt(str[i-s]);
        checkCnt();
    }
    console.log(ans);
}


sol();