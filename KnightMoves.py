while True:
    try:
        p1, p2 = input().split(" ")

        if p1 == p2:
            print('To get from ' + str(p1) + ' to ' + str(p2) + ' takes 0 knight moves.')
            exit()

        colunas_map = {
            'a': 0,
            'b': 1,
            'c': 2,
            'd': 3,
            'e': 4,
            'f': 5,
            'g': 6,
            'h': 7
        }

        directions = [
            [1, 2],
            [1, -2],
            [-1, 2],
            [-1, -2],
            [2, 1],
            [2, -1],
            [-2, 1],
            [-2, -1],
        ]

        # initial
        initial_x, initial_y = list(p1)
        initial_x = int(colunas_map[initial_x])
        initial_y = int(initial_y) - 1

        # target
        target_x, target_y = list(p2)
        target_x = int(colunas_map[target_x])
        target_y = int(target_y) - 1

        visited = []
        next_level = []

        def bfs():
            to_visit = [[[initial_x, initial_y]]]
            curr_level = 0

            while to_visit:
                level = to_visit.pop()
                next_level = []
                curr_level += 1

                for test_position in level:
                    x, y = test_position
                    for direction in directions:
                        add_x, add_y = direction
                        
                        new_x = x + add_x
                        new_y = y + add_y

                        if new_x < 0 or new_x > 7 or new_y < 0 or new_y > 7:
                            continue

                        if f'{new_x}-{new_y}' not in visited:
                            if [target_x, target_y] == [new_x, new_y]:
                                return curr_level
                            else:
                                visited.append(f'{new_x}-{new_y}')
                                next_level.append([new_x, new_y])
                                
                to_visit.append(next_level)
            return -1

        print('To get from ' + str(p1) + ' to ' + str(p2) + ' takes ' + str(bfs()) + ' knight moves.')
    except EOFError:
        exit()