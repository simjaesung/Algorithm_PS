const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' '));

const [n] = input.shift();
const checkDance = {};
const ans = 0;

const sol = () => {
    input.forEach((item) => {
      let [a,b] = item;
      if(a === "ChongChong" || b === "ChongChong")
          checkDance["ChongChong"] = 1;
    });
    
    input.forEach((item) => {
        let [a,b] = item;
        if(checkDance[a]) checkDance[b] = 1;
        if(checkDance[b]) checkDance[a] = 1;
    });
   
    console.log(Object.keys(checkDance).length);
}

sol();