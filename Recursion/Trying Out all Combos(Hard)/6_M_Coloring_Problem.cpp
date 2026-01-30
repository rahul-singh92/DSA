#include <iostream>
using namespace std;

bool isSafe(int node, vector<int>& color, bool graph[101][101], int n, int col)
{
    for(int k = 0; k < n; k++)
    {
        if(k != node && graph[k][node] == 1 && color[k] == col) return false;
    }
    return true;
}

bool solve(int node, vector<int>& color, int m, int N, bool graph[101][101])
{
    //If all nodes are assigned color then return 0
    if(node == N) return true;

    //Try different color of the nodes
    for(int i = 1; i <= m; i++)
    {
        if(isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            //Recursively check for the next node
            if(solve(node + 1, color, m, N, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    vector<int> color(N,0);

    //Start solving from node 0
    if(solve(0, color, m, N, graph)) return true;
    return false;
}

int main()
{
    int N = 4; //Maximum number of nodes
    int m = 3; //Maximum number of colors

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    // Create a sample graph with edges (0,1), (1,2), (2,3), (3,0), (0,2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;

    // Output if the graph can be colored with at most m colors
    cout << graphColoring(graph, m, N);

    return 0;
}