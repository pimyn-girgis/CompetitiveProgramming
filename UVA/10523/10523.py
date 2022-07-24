from sys import stdin
for line in stdin:
	n, a = [int(x) for x in line.split()]

	sum = 0
	for i in range(n):
		sum += (i+1) * (a**(i+1))
	print(sum)