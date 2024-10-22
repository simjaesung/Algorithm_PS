const input = require('fs').readFileSync('/dev/stdin').toString().trim();
const n = +input;

const sol = () => {
    for(let i = 0; i<n; i++){
        let tmp;
        if(i % 2 === 0) tmp = ''
        else tmp = ' '
        for(let j = 0; j<n; j++) {
            tmp += "* ";
        }
        console.log(tmp);
    }
}

sol();