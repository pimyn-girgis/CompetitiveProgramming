import random, sys

while 1:
	print("Enter your move (r)ock, (p)aper, (s)cissors or (q)uit") 
	move = input()
	if(move == 'r'):
		move = 1
	elif(move == 'p'):
		move = 2
	elif(move == 's'):
		move = 3
	elif(move == 'q'):
		sys.exit()
	vers = random.randint(1, 3)
	if(move == vers):
		print('It is a tie!')
	elif(move == vers - 1):
		print('You win!')
	else:
		print("You lose!")