caseNo = 1
while True:
    n, f = [int(x) for x in input().split()]

    if n == 0 and f == 0:
        break
    
    sum = 0
    for i in range(int(n)):
        sum = int(input()) + sum
    
    print('Bill #%d costs %d: each friend should pay %d\n'
        %(caseNo, sum, sum // f))

    caseNo = caseNo + 1