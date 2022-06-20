# 1135
# Esclarecimento: anthils = formigueiros

# def calcNivel(v):   
#     if nivel[parent[v]] != -1:
#         nivel[v] = nivel[parent[v]] + 1
#     else:
#         nivel[v] = calcNivel(nivel[v])
#     return nivel[v]

def calcDistance(i, f):
    distance = 0
    while i != f:
        if nivel[i] > nivel[f]:
            distance += d_parent[i]
            i = parent[i]
        elif nivel[i] < nivel[f]:
            distance += d_parent[f]
            f = parent[f]
        else:
            distance = distance + d_parent[i] + d_parent[f]
            i = parent[i]
            f = parent[f]
    return distance

while True:
    anthils = int(input())

    if anthils == 0:
        exit()

    parent = [-1 for _ in range(anthils)]
    d_parent = [-1 for _ in range(anthils)]

    nivel = [0, *[-1 for _ in range(anthils - 1)]]
    parent[0] = 0

    for anthil in range(1, anthils):
        parentAnthil, distance = list(map(int, input(" ").split(" ")))
        parent[anthil] = parentAnthil
        d_parent[anthil] = distance
        # calcNivel(anthil)
        nivel[anthil] = nivel[parentAnthil] + 1

    numQueries = int(input())

    for query in range(numQueries):
        v1, v2 = list(map(int, input().split(" ")))
        print(calcDistance(v1, v2), end=' ')
    