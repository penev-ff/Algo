// No negative values are allowed for Dijkstra!
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define INF 1e9

using ll = long long;
using pii = pair<int, int>;
using Adj = vector<vector<pii>>;

void printPath(int from, int to, const vector<int> &parents)
{
    stack<int> pathReversed;

    for (int v = to; v != from; v = parents[v])
    {
        pathReversed.push(v);
    }

    pathReversed.push(from);

    while (!pathReversed.empty())
    {
        cout << pathReversed.top() << ' ';
        pathReversed.pop();
    }
}

// Note.
// Another optimisation of this algorithm is
// to break the while loop when the target vertex
// is the priority queue's node to process.
// This means that the shortest path to this node is
// found and we do not need to traverse all other nodes.
void dijkstra(Adj &adj, const int START, vector<int> &dist, vector<int> &parents)
{
    priority_queue<pii, vector<pii>, greater<pii>> prQ;

    prQ.push({0, START}); // Pairs order is lexicographic, so we set distance first

    while (!prQ.empty())
    {
        int v = prQ.top().second;
        int distV = prQ.top().first;
        prQ.pop();

        // Optimisation
        // If shortest path is already found,
        // do not traverse v's neighbours
        if (distV == dist[v])
        {
            // Traverse neighbours
            for (pii &edge : adj[v])
            {
                int u = edge.first;
                int weight = edge.second;

                // Relax
                if (dist[v] + weight < dist[u])
                {
                    dist[u] = dist[v] + weight;
                    parents[u] = v;

                    prQ.push({dist[u], u});
                }
            }
        }
    }
}

int main()
{
    const int V = 3;
    const int E = 3;

    Adj adj(V, vector<pii>());

    for (int e = 0; e < E; e++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    const int START = 0;

    vector<int> dist(V, INF);
    dist[START] = 0;

    vector<int> parents(V, INF);

    dijkstra(adj, START, dist, parents);

    // Print shortest distances
    for_each(dist.begin(), dist.end(), [](int dist)
             { cout << dist << ' '; });

    printPath(START, V - 1, parents);

    return 0;
}
