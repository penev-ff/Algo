#include <iostream>
#include <vector>

#define INF -1

using namespace std;
using AdjList = vector<vector<pair<int, int>>>;

int main()
{
    const int V = 5;
    const int E = 6;

    // Indexing 1...n
    AdjList adj(V + 1, vector<pair<int, int>>());

    for (int e_i = 0; e_i < E; e_i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    int floyd[V + 1][V + 1];

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            floyd[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int v = 1; v <= V; v++)
    {
        for (auto &u : adj[v])
        {
            floyd[v][u.first] = u.second;
        }
    }

    // Floyd-Warshall

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int k = 1; k <= V; k++)
            {
                if (floyd[i][j] == INF || floyd[i][k] == INF)
                {
                    continue;
                }

                if (floyd[j][k] == INF ||
                    floyd[j][k] > floyd[i][j] + floyd[i][k])
                {
                    floyd[j][k] = floyd[i][j] + floyd[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << floyd[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}