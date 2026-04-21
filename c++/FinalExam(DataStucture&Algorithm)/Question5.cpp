#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void dfs(int node, int target, int k, const unordered_map<int, vector<int>>& graph, vector<bool>& visited, int& pathCount) 
{
    if (node == target) 
    {
        pathCount++;
        return;
    }

    visited[node] = true;
    for (int neighbor : graph.at(node)) 
    {
        if (!visited[neighbor]) 
        {
            dfs(neighbor, target, k, graph, visited, pathCount);
        }
    }
    visited[node] = false;
}

int main() 
{
    int V, E;
    cin >> V >> E;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < E; ++i) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    int s, t, k;
    cin >> s >> t >> k;
    vector<bool> visited(V, false);
    int pathCount = 0;
    dfs(s, k, k, graph, visited, pathCount);
    visited = vector<bool>(V, false);
    dfs(k, t, k, graph, visited, pathCount);
    cout << pathCount << endl;

    return 0;
}