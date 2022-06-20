const adj = [
    [0, 1, 0, 1],
    [1, 0, 1, 0],
    [0, 1, 0, 1],
    [1, 0, 1, 0],
];
const adj2 = [
    [1, 1, 1, 1],
    [1, 1, 1, 1],
    [1, 1, 1, 1],
    [1, 1, 1, 1],
];

const completo = (adj) => {
    for (let row of adj) {
        for (let con of row) {
            if (con === 0) return false;
        }
    }
    return true;
};
