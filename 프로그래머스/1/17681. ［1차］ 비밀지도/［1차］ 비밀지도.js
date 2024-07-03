function decode(s,n){
    let k = s.toString(2);
    k = k.split('');
    if(k.length < n){
        let c = n - k.length;
        while(c--) k.unshift('0');
    }
    return k;
}


function solution(n, arr1, arr2) {
    var answer = [];
    let map1 = new Array(n).fill().map(()=>new Array(n).fill(0));
    let map2 = new Array(n).fill().map(()=>new Array(n).fill(0));
    
    for(let i = 0; i<n; i++){
        let m1 = decode(arr1[i],n);
        let m2 = decode(arr2[i],n);
        for(let k = 0; k<n; k++){
            if(m1[k] == '1') map1[i][k] = 1;
            if(m2[k] == '1') map2[i][k] = 1;
        }
    }
    
    for(let i = 0; i<n; i++){
        let tmp = "";
        for(let j = 0; j<n; j++){
            if(map1[i][j] + map2[i][j] == 0) tmp += ' ';
            else tmp += "#";
        }
        answer.push(tmp);
    }
    
    return answer;
}