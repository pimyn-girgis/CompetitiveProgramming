from math import floor
from bisect import insort
from sys import stdin

tc = int(stdin.readline())

for i in range(0, tc):
    stdin.readline();
    x = []
    sum = 0
    for i in stdin.readline().split():
        insort(x, int(i))
        if(len(x) % 2):
            sum += x[int(len(x) / 2)]
        else:
            sum += floor((x[int(len(x) / 2)] + x[int(len(x) / 2) - 1])/2)
    print(sum)