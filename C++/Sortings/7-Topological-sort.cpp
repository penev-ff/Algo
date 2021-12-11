#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int pos,
             vector<int> adj[],
             bool visited[],
             vector<int> &res, int &res_i)
    {
        if (visited[pos])
        {
            return;
        }

        visited[pos] = true;

        for (int u : adj[pos])
        {
            if (!visited[u])
            {
                dfs(u, adj, visited, res, res_i);
            }
        }

        res[res_i--] = pos;
    }

    // Note: ajd is DAG
    vector<int> topoSort(int V, vector<int> adj[])
    {
        bool visited[V];

        for (int v_i = 0; v_i < V; ++v_i)
        {
            visited[v_i] = false;
        }

        // Used to store values backwards
        int res_i = V - 1;
        vector<int> topoSorted(V);

        for (int v_i = 0; v_i < V; ++v_i)
        {
            if (!visited[v_i])
            {
                dfs(v_i, adj, visited, topoSorted, res_i);
            }
        }

        return topoSorted;
    }
};