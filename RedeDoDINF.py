# 2522
from sys import stdin, stdout

def distance(x1, x2, y1, y2):
    return ((x2-x1)**2 + (y2-y1)**2)**0.5

while True:
    try:
        num_computers = int(stdin.readline())

        adj = []

        coord = []

        for i in range(num_computers):
            coord.append([int(x) for x in stdin.readline().split(" ")])

        # É calculado apenas a diagonal inferior da matriz para poupar processamento   
        for i in range(len(coord)):
            row = []
            for j in range(i):
                row.append(distance(coord[i][0], coord[j][0], coord[i][1], coord[j][1]))
            adj.append(row)

        connected_nodes = [0]
        not_connected_nodes = list(range(1, num_computers))
        total_length = 0

        while len(connected_nodes) < num_computers:
            smallest_distance = 999999
            closest_node = None

            for node in connected_nodes:
                for i in not_connected_nodes:
                    n = i
                    if node < i:
                        i,node = node,i

                    if adj[node][i] < smallest_distance:
                        smallest_distance = adj[node][i]
                        closest_node = n
                        
            not_connected_nodes.remove(closest_node)
            connected_nodes.append(closest_node)
            total_length += smallest_distance

        stdout.write('{:.2f}\n'.format(round(total_length, 2)))
    except EOFError:
        exit()