const readline = require("readline");
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});
let input = [];
rl.on("line", function (line) {
	input.push(line.toString());
}).on("close", function () {
	input.shift();
	input = input.map((el) => el.split(" ").map((el) => Number(el)));

	for (let i = 0; i < input.length; i++) {
		console.log(`Case ${i + 1}: ${input[i][0] + input[i][1]}`);
	}
	process.exit();
});