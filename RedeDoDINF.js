// Wrong awnser
// const input = require("fs").readFileSync("/dev/stdin", "utf8");
const input = require("fs").readFileSync("./input.txt", "utf8");
const lines = input.split("\n");

let nextLine = 0;
const range = (n) => [...Array(n).keys()];

while (lines[nextLine]) {
  const numComputers = Number(lines[nextLine++]);
  const adj = [];

  const distance = (x1, x2, y1, y2) =>
    Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
  const coord = [];

  range(numComputers).forEach(() => {
    coord.push(lines[nextLine++].split(" ").map(Number));
  });

  range(numComputers).forEach((i) => {
    const row = [];
    for (let j in range(i)) {
      row.push(distance(coord[i][0], coord[j][0], coord[i][1], coord[j][1]));
    }
    adj.push(row);
  });

  const connectedNodes = [0];
  let notConnectedNodes = [...range(numComputers)];
  notConnectedNodes.shift();
  let totalLength = 0;

  while (connectedNodes.length < numComputers) {
    let smallestDistance = 999999;
    let closestNode;

    connectedNodes.forEach((node) => {
      notConnectedNodes.forEach((possibleNode) => {
        const bkpPossibleNode = possibleNode;
        if (node < possibleNode) {
          const aux = node;
          node = possibleNode;
          possibleNode = aux;
        }

        if (adj[node][possibleNode] < smallestDistance) {
          smallestDistance = adj[node][possibleNode];
          closestNode = bkpPossibleNode;
        }
      });
    });

    notConnectedNodes = notConnectedNodes.filter(
      (node) => node !== closestNode
    );
    connectedNodes.push(closestNode);
    totalLength += smallestDistance;
  }

  console.log(totalLength.toFixed(2));
}
