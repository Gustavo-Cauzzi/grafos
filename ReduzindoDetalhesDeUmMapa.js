//2404
const input = require("fs").readFileSync("./input.txt", "utf8");
// const input = require("fs").readFileSync("/dev/stdin", "utf8");
const lines = input.split("\n");
let nextLine = 0;

const range = (n) => [...Array(n).keys()];

const [cities, numRoads] = lines[nextLine++].split(" ").map(Number);

const rawConnections = [];
const graph = [];

range(numRoads).forEach(() =>
  rawConnections.push(lines[nextLine++].split(" ").map(Number))
);

range(cities)
  .map((city) => city + 1)
  .forEach((city) => {
    const node = {
      val: city,
      connections: [],
    };

    node.connections = rawConnections
      .filter((con) => con[0] === city || con[1] === city)
      .map((con) => {
        const connectedNode = con[0] === city ? con[1] : con[0];
        return {
          val: connectedNode,
          length: con[2],
        };
      });

    graph.push(node);
  });

const nodesConnected = [1];
let totalLength = 0;

while (nodesConnected.length < cities) {
  const closestNode = nodesConnected
    .map((node) => graph.find((n) => n.val === node))
    .flat()
    .map((systemNodes) => systemNodes.connections)
    .flat()
    .filter((node) => !nodesConnected.includes(node.val))
    .reduce((acc, curr) =>
      !acc || curr.length < acc.length ? (acc = curr) : acc
    );

  nodesConnected.push(closestNode.val);
  totalLength += closestNode.length;
}

console.log(totalLength);
