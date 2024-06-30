let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map((el)=>el.split(' ').map((item)=>+item));

class Deque {
  constructor() {
    this.buf = [,];
    this.front = 0;
    this.back = 0;
  }
  length() {
    const len = this.back - this.front;
    return len < 0 ? len + this.buf.length : len;
  }
  isEmpty() {
    return this.front === this.back;
  }
  double() {
    const length = this.buf.length << 1;
    if (this.back < this.front) {
      const buf = this.buf.slice(this.front);
      for (let i = 0; i < this.back; ++i)
        buf.push(this.buf[i]);
      this.buf = buf;
    }
    this.buf.length = length;
    this.front = 0;
    this.back = (length >> 1) - 1;
  }
  push(v) {
    let back = this.back + 1;
    if (back === this.buf.length)
      back = 0;
    if (back === this.front)
      this.double();
    this.buf[this.back++] = v;
    if (this.back === this.buf.length)
      this.back = 0;
  }
  pop() {
    if (--this.back < 0)
      this.back += this.buf.length;
    return this.buf[this.back];
  }
  shift() {
    const v = this.buf[this.front++];
    if (this.front === this.buf.length)
      this.front = 0;
    return v;
  }
  unshift(v) {
    let front = this.front - 1;
    if (front < 0)
      front += this.buf.length;
    if (front === this.back)
      this.double();
    if (--this.front < 0)
      this.front += this.buf.length;
    this.buf[this.front] = v;
  }
}

const [n,m] = input.shift();
let dodo_dec = new Deque(n);
let su_dec = new Deque(n);

let dodo_ground = [];
let su_ground = [];

let dg_cnt = 0; //도도그라운드 카드개수
let sg_cnt = 0; //수연그라운드 카드개수
let turn = 1; //1이면 도도 0이면 수연

function set_dec(){
	input.forEach((e,i) =>{
		let [a,b] = e;
		dodo_dec.push(a);
		su_dec.push(b);
	})
}

function dodo_turn(){
	dodo_ground.push(dodo_dec.pop());
	dg_cnt++;
}

function su_turn(){
	su_ground.push(su_dec.pop());
	sg_cnt++;
}

function check_ring(){
	if(dg_cnt > 0 && dodo_ground[dg_cnt - 1] == 5) return 1;
	else if(sg_cnt > 0 && su_ground[sg_cnt - 1] == 5) return 1;
	else if(dg_cnt > 0 && sg_cnt > 0){
		if(dodo_ground[dg_cnt - 1] + su_ground[sg_cnt - 1] == 5) return 2;
	}
	return 0; //아직 승부가 안남
}

function dodo_win(){
	for(let i = 0; i<sg_cnt; i++){
		dodo_dec.unshift(su_ground[i]);
	}
	for(let i = 0; i<dg_cnt; i++){
		dodo_dec.unshift(dodo_ground[i]);
	}
	su_ground = [];
	dodo_ground = [];
	dg_cnt = 0;
	sg_cnt = 0;
}

function su_win(){
	for(let i = 0; i<dg_cnt; i++){
		su_dec.unshift(dodo_ground[i]);
	}
	for(let i = 0; i<sg_cnt; i++){
		su_dec.unshift(su_ground[i]);
	}
	su_ground = [];
	dodo_ground = [];
	dg_cnt = 0;
	sg_cnt = 0;
}

function solution(){
	set_dec();
	
	for(let i = 0; i<m; i++){
		//console.log(dodo_dec.length(),su_dec.length());
		if(turn == 1){
			//도도턴
			dodo_turn();
			turn = 0;
		}
		else{
			su_turn();
			turn = 1;
		}
		
		if(dodo_dec.length() == 0){
			console.log("su");
			return;
		}
		
		if(su_dec.length() == 0){
			console.log("do");
			return;
		}
		
		let check_turn = check_ring();
		if(check_turn == 1) dodo_win();
		else if(check_turn == 2) su_win();
	}
	
	if(dodo_dec.length() > su_dec.length()) console.log("do");
	else if(su_dec.length() > dodo_dec.length()) console.log("su");
	else console.log("dosu");
}
solution();