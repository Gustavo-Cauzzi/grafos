// 1774
const input = require("fs").readFileSync("/dev/stdin", "utf8");
const lines = input.split("\n");

let nextLine = 0;

const [routers, numConnections] = lines[nextLine++].split(" ").map(Number);

let connections = [];
let smallestConnection;

// Similar ao range do python
for (let i in [...Array(numConnections).keys()]) {
  const [n1, n2, l] = lines[nextLine++].split(" ").map(Number);
  const connection = { n1, n2, l };
  if (!smallestConnection || l < smallestConnection.l) {
    smallestConnection = connection;
  }
  connections.push(connection);
}

const nodesConnected = [smallestConnection.n1, smallestConnection.n2];
let totalLength = smallestConnection.l;

while (nodesConnected.length < routers) {
  let closestNode;
  nodesConnected.forEach((node) => {
    const possibleConnections = connections.filter(
      (con) => con.n1 === node || con.n2 === node
    );

    possibleConnections.forEach((possibleConnection) => {
      if (
        !(
          nodesConnected.find(
            (nodeConnected) => nodeConnected === possibleConnection.n1
          ) &&
          nodesConnected.find(
            (nodeConnected) => nodeConnected === possibleConnection.n2
          )
        ) &&
        (!closestNode || possibleConnection.l < closestNode.l)
      ) {
        closestNode = possibleConnection;
      }
    });
  });

  const newNode = nodesConnected.find(
    (connectedNode) => connectedNode === closestNode.n1
  )
    ? closestNode.n2
    : closestNode.n1;
  nodesConnected.push(newNode);
  totalLength += closestNode.l;
}

console.log(totalLength);
