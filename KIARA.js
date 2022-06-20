// const input = require('fs').readFileSync('/dev/stdin', 'utf8');
const input = require("fs").readFileSync("./input.txt", "utf8");
const lines = input.split("\n");
let nextLine = 0;

const numWords = lines[nextLine++];

const initialLetters = new Set();
const words = [];

const areSetsEqual = (a, b) => [...a].every((value) => b.has(value));

for (let i = 0; i < numWords; i++) {
    const word = lines[nextLine++].slice(0, -1);
    words.push(new Set([...word]));
    initialLetters.add(word[0]);
}

let exit = false;
for (let word of words) {
    if (areSetsEqual(word, initialLetters)) {
        console.log("Y");
        exit = true;
        break;
    }
}

if (!exit) console.log("N");
