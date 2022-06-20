// 1539
const input = require("fs").readFileSync("/dev/stdin", "utf8");
// const input = require("fs").readFilSeSync("./input.txt", "utf8");
const lines = input.split("\n");
let nextLine = 0;

const getDistance = (x1, x2, y1, y2) =>
    Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
const range = (n) => [...Array(n).keys()];

while (true) {
    const antennas = Number(lines[nextLine++]);

    if (!antennas) break;

    const coordinates = [];
    const connections = [];
    const adj = [];

    range(antennas).forEach(() => {
        const [x, y, r] = lines[nextLine++].split(" ").map(Number);
        coordinates.push({ x, y, r });
    });

    const numConnections = Number(lines[nextLine++]);

    range(numConnections).forEach(() => {
        const [a, b] = lines[nextLine++].split(" ").map(Number);
        connections.push({ a, b });
    });

    coordinates.forEach((coord1, i) => {
        const row = coordinates.map((coord2, j) => {
            if (i === j) return 0;

            const distance = getDistance(
                coord1.x,
                coord2.x,
                coord1.y,
                coord2.y
            );

            return distance > coord1.r ? Infinity : distance;
        });
        adj.push(row);
    });

    range(antennas).forEach((k) => {
        range(antennas).forEach((i) => {
            range(antennas).forEach((j) => {
                adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
            });
        });
    });

    connections.forEach(({ a, b }) => {
        const distance = adj[a - 1][b - 1];
        console.log(distance === Infinity ? -1 : Math.trunc(distance));
    });
}
