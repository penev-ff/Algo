#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

using AdjList = vector<vector<int>>;

void readGraph(AdjList &adj, const int V, const int E)
{
    for (int e_i = 0; e_i < E; e_i++)
    {
        int from, to;

        cin >> from >> to;

        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}

void printPath(vector<int> &predecessors,
               const int START, const int DEST)
{
    stack<int> reversedPath;

    for (int v_i = DEST; v_i != START; v_i = predecessors[v_i])
    {
        reversedPath.push(v_i);
    }

    reversedPath.push(START);

    while (!reversedPath.empty())
    {
        cout << reversedPath.top() << ' ';
        reversedPath.pop();
    }

    cout << endl;
}

void bfs(AdjList &adj,
         const int V, const int E,
         const int START, const int DEST)
{
    vector<int> dest(V, INT32_MAX);
    dest[START] = 0;

    vector<int> predecessors(V, -1);

    queue<int> wave;
    wave.push(START);

    while (!wave.empty())
    {
        int v = wave.front();
        wave.pop();

        for (int u : adj[v])
        {
            if (dest[v] + 1 < dest[u])
            {
                dest[u] = dest[v] + 1;
                predecessors[u] = v;

                wave.push(u);
            }
        }
    }

    printPath(predecessors, START, DEST);
}

int main()
{
    int V, E;
    cin >> V >> E;

    AdjList adj(V, vector<int>());

    readGraph(adj, V, E);

    int start, dest;
    cin >> start >> dest;

    bfs(adj, V, E, start, dest);

    return 0;
}