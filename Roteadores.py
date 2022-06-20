# 1774
routers, num_connections = list(map(int, input().split(" ")))

connections = []

# Vai ser a primeira para começar o sistema
smallest_con = None

for i in range(num_connections):
    n1, n2, l = list(map(int, input().split(" ")))
    con = {'n1': n1, 'n2': n2, 'l': l}
    if not smallest_con or l < smallest_con['l']:
        smallest_con = con
    connections.append(con)

nodes_connected = [smallest_con['n1'], smallest_con['n2']]
total_length = smallest_con['l']

while len(nodes_connected) < routers:
    closest_node = None
    for node in nodes_connected:
        possible_connections = list(filter(
            lambda con: con['n1'] == node 
                     or con['n2'] == node, 
            connections 
        ))

        for p_con in possible_connections:
            # Se ambos os nodos da possível conexão não estão já conctados e sua distância é a menor encontrada até então
            if not (p_con['n1'] in nodes_connected and p_con['n2'] in nodes_connected) and (not closest_node or p_con['l'] < closest_node['l']):
                closest_node = p_con

    new_node = closest_node['n1'] if closest_node['n1'] not in nodes_connected else closest_node['n2']
    nodes_connected.append(new_node)
    total_length += closest_node['l']

print(total_length)