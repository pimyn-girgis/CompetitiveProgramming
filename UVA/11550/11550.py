tc = int(input())

for _ in range(tc):
    matrix = []
    edges = {}
    vert, edge = [int(i) for i in input().split()]

    for _ in range(vert):
        matrix.append(list(map(int, input().split())))

    yes = True
    for i in range(edge):
        if not yes:
            break
        first = second = 0
        for j in range(vert):
            if not matrix[j][i]:
                continue

            if first and second:
                yes = False
            elif first:
                second = j + 1
            else:
                first = j + 1

        if (first in edges and edges[first] == second) or not second:
            yes = False
            break
        else:
            edges[first] = second

    print('Yes' if yes else 'No')
