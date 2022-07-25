#https://open.kattis.com/problems/wizardofodds

n, k = [int(v) for v in input().split()]
if n <= 2 ** k:
	print('Your wish is granted!')
else:
	print('You will become a flying monkey!')