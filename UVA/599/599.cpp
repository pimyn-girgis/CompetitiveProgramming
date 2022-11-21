/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
* Problem : 00599 UVA
* Link    : https://onlinejudge.org/external/5/p599.pdf
**************************************************************
* Approach: 
**************************************************************
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

void get_connected(char node, int &done, int graph[])
{
    for(int i = 0; i < 26; ++i)
        if(!(done & (1L << i)) && graph[node] & (1L << i))
        {
            done |= (1L << i);
            if(i != node)
                get_connected(i, done, graph);
        }
}

int main()
{
    int tc;
    scanf("%d\n", &tc);

    while(tc--)
    {
        int graph[26];
        memset(graph, 0, sizeof(graph));

        char edge[1000];
        while(scanf("%s\n", edge), edge[0] != '*')
        {
            const int A = edge[1] - 'A';
            const int B = edge[3] - 'A';

            graph[A] |= (1L << B);
            graph[B] |= (1L << A);
        }

        int acorn = 0;
        int tree = 0;
        int done = 0;

        char node;
        while(scanf("%c", &node), node != '\n')
            if(node != ',' && !graph[node - 'A'])
                ++acorn;
        
        for(int i = 0; i < 26; ++i)
        {
            if(!graph[i]) continue;

            if(!(done & (1L << i)))
                ++tree;

            done |= (1L << i);
            get_connected(i, done, graph);
        }

        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }

    return 0;
}
