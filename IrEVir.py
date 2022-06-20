while True:
    intercecoes, ruas = list(map(int, input().split(" ")))

    if not intercecoes and not ruas:
        exit()

    adj = [[-1 for _ in range(intercecoes)] for _ in range(intercecoes)]
    inv_adj = [[-1 for _ in range(intercecoes)] for _ in range(intercecoes)]

    for rua in range(ruas):
        r1, r2, p = list(map(int, input().split(" ")))
        r1 = r1 - 1
        r2 = r2 - 1
        adj[r1][r2] = 1
        inv_adj[r2][r1] = 1
        if p == 2:
            adj[r2][r1] = 1
            inv_adj[r1][r2] = 1
    

    pos_ordem = [-1 for _ in range(intercecoes)]
    pos_ordem_count = 1
    not_visited = list(range(intercecoes))

    def bfs_pos_ordem(i):
        not_visited.remove(i)
        global pos_ordem_count
        for conexao, con in enumerate(adj[i]):
            if con == 1 and conexao in not_visited:
                bfs_pos_ordem(conexao)
                pos_ordem[conexao] = pos_ordem_count
                pos_ordem_count = pos_ordem_count + 1

    for vertice in range(intercecoes):
        if vertice in not_visited:
            bfs_pos_ordem(vertice)
            if pos_ordem[vertice] == -1:
                pos_ordem[vertice] = pos_ordem_count
                pos_ordem_count = pos_ordem_count + 1


    not_visited = list(range(intercecoes))
    def bfs(i):
        not_visited.remove(i)
        for conexao, con in enumerate(inv_adj[i]):
            if con == 1 and conexao in not_visited:
                bfs(conexao)
    
    bfs(pos_ordem.index(intercecoes))

    if len(not_visited) == 0:
        print(1)
    else:
        print(0)


