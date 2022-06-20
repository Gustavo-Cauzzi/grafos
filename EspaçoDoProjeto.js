//2683

// const input = require("fs").readFileSync("/dev/stdin", "utf8");
const input = require("fs").readFileSync("./input.txt", "utf8");
const lines = input.split("\n");

let nextLine = 0;
const range = (n) => [...Array(n).keys()];

const numGaleries = Number(lines[nextLine++]);

const connections = [];
let smallestCostCon, biggestCostCon;

let numberOfNodes = 0;

range(numGaleries).forEach((g) => {
  const [x, y, cost] = lines[nextLine++].split(" ").map(Number);
  const con = {
    x,
    y,
    cost,
  };

  const maxNode = Math.max(x, y);
  if (maxNode > numberOfNodes) numberOfNodes = maxNode;

  if (!smallestCostCon || cost < smallestCostCon) smallestCostCon = con;
  else if (!biggestCostCon || cost > biggestCostCon) biggestCostCon = con;
  connections.push(con);
});

const calculate = (connection, searchSmallest) => {
  const nodesConnected = [connection.x, connection.y];
  let totalCost = connection.cost;

  while (nodesConnected.length < numberOfNodes) {
    let possibleNode;
    nodesConnected.forEach((node) => {
      const possibleConnections = connections.filter(
        (con) => con.x === node || con.y === node
      );

      possibleConnections.forEach((possibleConnection) => {
        if (
          !(
            nodesConnected.find(
              (nodeConnected) => nodeConnected === possibleConnection.x
            ) &&
            nodesConnected.find(
              (nodeConnected) => nodeConnected === possibleConnection.y
            )
          ) &&
          (!possibleNode ||
            (!searchSmallest
              ? possibleConnection.cost < possibleNode.cost
              : possibleConnection.cost > possibleNode.cost))
        ) {
          possibleNode = possibleConnection;
        }
      });
    });

    const newNode = nodesConnected.find(
      (connectedNode) => connectedNode === possibleNode.x
    )
      ? possibleNode.y
      : possibleNode.x;
    nodesConnected.push(newNode);
    totalCost += possibleNode.cost;
  }

  return totalCost;
};

console.log(calculate(smallestCostCon, true));
console.log(calculate(biggestCostCon, false));
