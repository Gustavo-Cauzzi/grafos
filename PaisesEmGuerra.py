import math
# Problema 1148

def dijkstra(adj, N, nodeIni, nodeFim):
    d = [math.inf for i in range(N)]
    d[nodeIni - 1] = 0
    Q = [i for i in range(N)]
    
    while len(Q) > 0:
        # print('Q:', Q)
        # print('d:', d)
        smallestDistance = math.inf
        for node in Q:
            if d[node] < smallestDistance:
                smallestDistance = d[node]
                nodeSmallestDistance = node

        # print('smallestDistance: ', smallestDistance)
        # print('nodeSmallestDistance: ', nodeSmallestDistance)
        if smallestDistance == math.inf:
            return smallestDistance

        if nodeSmallestDistance == nodeFim - 1:
            return smallestDistance
        
        for index, adjacentNodeDistance in enumerate(adj[nodeSmallestDistance]):
            if adjacentNodeDistance == -1:
                continue
            elif d[index] > d[nodeSmallestDistance] + adjacentNodeDistance:
                # print(f'=-=-=- index = {index} | adjacentNodeDistance = {adjacentNodeDistance}')
                d[index] = d[nodeSmallestDistance] + adjacentNodeDistance
        
        Q.remove(nodeSmallestDistance)
    
    return math.inf

while True:
    N, E = map(int, list(input().split(" ")))

    if N == 0 and E == 0:
        exit()

    acordos = []

    for i in range(E):
        acordo = list(map(int, list(input().split(" "))))
        X, Y, H = acordo
        acordos.append({"x": acordo[0], "y": acordo[1], "h": acordo[2]})

    for acordo in acordos:
        acordo_contrario = next(
            filter(
                lambda a: a['x'] == acordo['y'] 
                and a['y'] == acordo['x'] 
                and a['h'] != 0 
                and acordo['h'] != 0, 
                acordos
            ), None
        )
        
        # São no mesmo país
        if acordo_contrario:
            acordo_contrario['h'] = 0
            acordo['h'] = 0

    n_consultas = int(input())
    consultas = []


    adj = [[-1 for _ in range (N)] for _ in range (N)]
    for acordo in acordos:
        adj[acordo['x'] - 1][acordo['y'] - 1] = acordo['h']

    for c in range(n_consultas):
        x, y = (list(map(int, list(input().split(" ")))))
        distance = dijkstra(adj, N, x, y)
        print(distance if distance != math.inf else 'Nao e possivel entregar a carta')

    print("")