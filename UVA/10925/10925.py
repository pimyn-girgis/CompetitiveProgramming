caseNo = 1
while True:
    n, f = [int(x) for x in input().split()]

    if not(n or f):
        break
    
    sum = 0
    for i in range(n):
        sum = int(input()) + sum
    
    print('Bill #%d costs %d: each friend should pay %d\n'
        %(caseNo, sum, sum // f))

    caseNo += 1