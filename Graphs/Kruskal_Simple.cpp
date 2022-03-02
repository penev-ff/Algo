#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

struct Edge
{
    int u, v;
    int weight;

    // For std::sort()
    bool operator<(const Edge &rhs) const
    {
        return weight < rhs.weight;
    }

    bool operator==(const Edge &rhs) const
    {
        return weight == rhs.weight;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    // Graph representation using edges
    vector<Edge> edges(E);

    // To keep track if two vertices are in the same component
    vector<int> components(V);
    for (int i = 0; i < V; ++i)
    {
        components[i] = i;
    }

    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        edges[i] = {u, v, weight};
    }

    sort(edges.begin(), edges.end());

    vector<Edge> mst;
    ll sum = 0;

    for (Edge e : edges)
    {
        if (components[e.u] != components[e.v])
        {
            sum += e.weight;
            mst.push_back(e);

            // Update components

            int oldComp = components[e.u];
            int newComp = components[e.v];

            for (int i = 0; i < V; i++)
            {
                if (components[i] == oldComp)
                {
                    components[i] = newComp;
                }
            }
        }
    }

    cout << sum << '\n';

    return 0;
}