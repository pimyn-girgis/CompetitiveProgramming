/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/

#include <stdio.h>

#include <algorithm>
using std::find;

#include <string>
using std::string;

#include <vector>
using std::vector;

typedef vector<vector<bool>> graph;

string dfs(const graph &g, char node, vector<bool> &visited, vector<char> &finished)
{
    if(visited[node - 'a']) return "";
    visited[node - 'a'] = true;

    string newly_visited(1, node);
 
    for(int i = 0; i < (int)g[node - 'a'].size(); ++i)
        if(g[node - 'a'][i] && !visited[i])
            newly_visited += dfs(g, i + 'a', visited, finished);
    
    finished.push_back(node);
    return newly_visited;
}

void get_transpose(graph &g) //Transpose of graph
{
    graph ret(g.size());

    for(int i = 0; i < g.size(); ++i)
    {
        ret[i].resize(g.size());
        for(int j = 0; j < g.size(); ++j)
            ret[i][j] = g[j][i];
    }

    g = ret;
}

vector<vector<char>> get_groups(graph &g, vector<char> &nodes)
{
    vector<vector<char>> groups;
    vector<bool> visited(nodes.size());
    vector<char> finished;

    for(auto u : nodes)
        dfs(g, u, visited, finished);

    get_transpose(g);

    nodes = finished;
    finished.clear();
    visited.clear();
    visited.resize(nodes.size());

    for(int i = (int)nodes.size() - 1; i >= 0; i = (int)nodes.size() - 1)
    {
        string newly_visited = dfs(g, nodes[i], visited, finished);
        groups.resize(groups.size() + 1);

        for(auto u : newly_visited)
        {
            groups.back().push_back(u);
            nodes.erase(find(nodes.begin(), nodes.end(), u));
        }
    }

    return groups;
}

void output(const vector<vector<char>> &g)
{
    for(int i = 0; i < g.size(); ++i)
        for(int j = 0; j < g[i].size(); ++j)
            printf("%c%c", g[i][j], j + 1 == g[i].size()? '\n' : ' ');
}

void example_1()
{
    vector<char> nodes = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'};
    graph g =
        {
            { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, //a
            { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }, //b
            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, //c
            { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 }, //d
            { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, //e
            { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 }, //f
            { 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 }, //g
            { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 }, //h
            { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }, //i
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1 }, //j
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }  //k
            //a, b, c, d, e, f, g, h, i, j, k
        };

    output(get_groups(g, nodes));
}

void example_2()
{
    vector<char> nodes = {'a', 'b', 'c', 'd', 'e'};

    graph g = 
    {
        { 1, 1, 0, 0, 0 }, //a
        { 0, 1, 1, 1, 0 }, //b
        { 0, 0, 1, 0, 1 }, //c
        { 1, 0, 0, 1, 0 }, //d
        { 0, 0, 0, 0, 1 }  //e
        //a, b, c, d, e  
    };

    output(get_groups(g, nodes));
}

int main()
{
    example_1();
    printf("\n");
    example_2();
    return 0;
}

/*
    dfs(node)
    if node = visited
        return
    node = visited
    newly visited = node

    for n in adj : node
        if n = not visited
            n = visited
            newly visited = newly visited + n
    
    finished = finished + node
    return newly visited
    
    for node in nodes
        dfs(node)
    
    graph = transpose(graph)

    for node in finished
    {
        newly visited = dfs(nodes)
        groups = groups + newly visited
        nodes = nodes - newly visited
    }
*/
