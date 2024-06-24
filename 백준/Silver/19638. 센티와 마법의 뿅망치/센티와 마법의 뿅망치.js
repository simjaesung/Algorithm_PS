const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));
const [n,h,t] = input.shift();

class MaxHeap {
    constructor() {
        this.heap = [null];
    }
    push(value) {
        // 아래에서 위로
        this.heap.push(value);
        let currentIndex = this.heap.length - 1;
        let parentIndex = Math.floor(currentIndex / 2);
        while (parentIndex !== 0 && this.heap[parentIndex] < value) {
            const temp = this.heap[parentIndex];
            this.heap[parentIndex] = this.heap[currentIndex];
            this.heap[currentIndex] = temp;
            currentIndex = parentIndex;
            parentIndex = Math.floor(currentIndex / 2);
        }
    }
    pop() {
        if (this.heap.length === 2) return this.heap.pop(); // 루트 정점만 남은 경우
        // 위에서 아래로
        let returnValue = this.heap[1];
        this.heap[1] = this.heap.pop();
        let currentIndex = 1;
        let leftIndex = 2;
        let rightIndex = 3;
        while (
            this.heap[currentIndex] < this.heap[leftIndex] ||
            this.heap[currentIndex] < this.heap[rightIndex]
        ) {
            const temp = this.heap[currentIndex];
            if (this.heap[leftIndex] < this.heap[rightIndex]) {
                this.heap[currentIndex] = this.heap[rightIndex]
                this.heap[rightIndex] = temp;
                currentIndex = rightIndex;
            } else {
                this.heap[currentIndex] = this.heap[leftIndex]
                this.heap[leftIndex] = temp;
                currentIndex = leftIndex;
            }
            leftIndex = currentIndex * 2;
            rightIndex = leftIndex + 1;
        }
        return returnValue;
    }
    return() {
        return this.heap;
    }
}

let pq = new MaxHeap();

function solution(arr){
	for(let i = 0; i<n; i++) pq.push(...arr[i]);
	
	for(let i = 0; i<t; i++){
		let top = pq.pop();
		
		if(top < h){ //가장큰거인이 작은경우
			console.log("YES");
			console.log(i);
			return;
		}
		
		if(top == 1){ //키가 1인 경우
			pq.push(top);
			continue;
		}
		
		top = Math.floor(top / 2);
		pq.push(top);
	}
	
	let top = pq.pop();
	
	if(top < h){
		console.log("YES");
		console.log(t);
	}
	else{
		console.log("NO");
		console.log(top);
	}
}

solution(input);