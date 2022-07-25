while True:
    sum = 0
    x, y = [v for v in input().split()]
    if not(x or y):
        break
    x = int(x[::-1])
    y = int(y[::-1])