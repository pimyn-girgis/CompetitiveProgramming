n = int(input())
while n:

	x, y = input().split()
	sum = int(x[::-1]) + int(y[::-1])
	print(int(str(sum)[::-1]))

	n -= 1