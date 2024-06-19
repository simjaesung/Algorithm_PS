var today = new Date();
solution(today);
function solution(now){
    console.log(now.getFullYear());
    console.log("0" + String(now.getMonth() + 1));
    console.log(now.getDate());
}   