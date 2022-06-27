//turtlemaster
#include <bits/stdc++.h>
using namespace std;

int xpos = 0, ypos = 7, dir = 0, dx = 1, dy = 0;
int d_x[4] = {1, 0, -1, 0};
int d_y[4] = {0, 1, 0, -1};
bool bug = 0;
char board[8][9], instructions[70];

bool valid(int x){return 0 <= x && x < 8;}
bool valid(int x, int y){return valid(x) && valid(y);}
bool valid(){return !(board[ypos][xpos] == 'C' || board[ypos][xpos] == 'I') && valid(xpos, ypos);}
void forward(){xpos += dx; ypos += dy; if(!valid()) bug = 1;}
void updateDir(){dx = d_x[dir]; dy = d_y[dir];}
void leftRotate(){dir = (dir+3)%4; updateDir();}
void rightRotate(){dir = (dir+1)%4; updateDir();}
void laser(){if(board[ypos+dy][xpos+dx] == 'I') board[ypos+dy][xpos+dx] = '.'; else bug = 1;}
void execute(char move)
{
	if(move == 'F') forward();
	else if(move == 'L') leftRotate();
	else if(move == 'R') rightRotate();
	else laser();
}

int main()
{
	for(int i = 0; i < 8; ++i)
		scanf("%s", board[i]);
	scanf("%s", instructions);
	for(int i = 0;instructions[i]; ++i)
		execute(instructions[i]);
	printf("%s", bug || board[ypos][xpos] != 'D'? "Bug!" : "Diamond!");
	return 0;
}

