#include <bits/stdc++.h>
using namespace std;

int ivalue, t, val, marks;
char expression[5];

void update()
{
		 if (!expression[1] && val == ivalue){++marks;}
	else if	(expression[0] == '+' && val == ivalue + 1){++ivalue, ++marks;}
	else if (expression[0] == '-' && val == ivalue - 1){--ivalue, ++marks;}
	else if (expression[2] == '+' && val == ivalue){++ivalue, ++marks;}
	else if (expression[2] == '-' && val == ivalue){--ivalue, ++marks;}
	else if (expression[0] != 'i') {ivalue = val;}
	else if (expression[2] == '+') {ivalue = val + 1;}
	else if (expression[2] == '-') {ivalue = val - 1;}
	else ivalue = val;
}
int main()
{
	while (scanf("%i %d", &ivalue, &t) && ivalue && t)
	{
		marks = 0;
		while (t--)
		{
			memset(expression, 0, sizeof(expression));
			scanf("%s %d", expression, &val);
			update();
		}
		printf("%d\n", marks);
	}
	return 0;
}