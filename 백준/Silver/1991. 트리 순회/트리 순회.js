const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((line)=>line.split(' '));

const [n] = input.shift();
const tree = {};
let answer = '';

const init = () =>{
    input?.forEach((item)=>{
        const [node, left, right] = item;
        tree[node] = [];
        tree[node].push(left);
        tree[node].push(right);
    })
}

const preorder = (node) => {
    if(node === '.') return;
    answer += node;
    preorder(tree[node][0]);
    preorder(tree[node][1]);
}

const inorder = (node) => {
    if(node === '.') return;
    inorder(tree[node][0]);
    answer += node;
    inorder(tree[node][1]);
}

const postorder = (node) => {
    if(node === '.') return;
    postorder(tree[node][0]);
    postorder(tree[node][1]);
    answer += node;
}


const sol = () => {
    init();
    preorder('A');
    answer += '\n';
    inorder('A');
    answer += '\n';
    postorder('A')
    console.log(answer);
}

sol();