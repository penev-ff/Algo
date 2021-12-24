#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int from, to;
    int weight;
};

using ll = long long;
using WGraph = vector<Edge>;

void bellmanFord(const WGraph &wg, int pos, const int V, vector<int> &dist)
{
    dist.assign(V + 1, INT32_MAX);
    dist[pos] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (const Edge &e : wg)
        {
            dist[e.to] = min(dist[e.to], dist[e.from] + e.weight);
        }
    }
}

int main()
{
    const int V = 5;
    const int E = 7;

    WGraph wg(E);

    for (int i = 0; i < E; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        wg[i].from = from;
        wg[i].to = to;
        wg[i].weight = weight;
    }

    vector<int> dist(V + 1);

    bellmanFord(wg, 1, V, dist);

    return 0;
}