#include <iostream>
using namespace std;

#define INF 999

int main()
{
    int n;
    int cost[10][10];

    cout << "Enter number of routers: ";
    cin >> n;

    cout << "\nEnter cost matrix (-1 for no connection):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == -1)
                cost[i][j] = INF;
        }
    }

    for (int src = 0; src < n; src++)
    {
        int dist[10], visited[10] = {0}, parent[10];

        for (int i = 0; i < n; i++)
        {
            dist[i] = cost[src][i];
            parent[i] = (cost[src][i] != INF && i != src) ? src : -1;
        }

        dist[src] = 0;

        for (int count = 0; count < n - 1; count++)
        {
            int minDist = INF, u = -1;

            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && dist[i] < minDist)
                {
                    minDist = dist[i];
                    u = i;
                }
            }

            if (u == -1)
                break;

            visited[u] = 1;

            for (int v = 0; v < n; v++)
            {
                if (!visited[v] && cost[u][v] != INF)
                {
                    if (dist[u] + cost[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + cost[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        cout << "\nLink State Routing Table - Router "
             << src + 1 << ":\n";

        cout << "Destination\tCost\tNext Hop\n";

        for (int dest = 0; dest < n; dest++)
        {
            cout << dest + 1 << "\t\t";

            if (dist[dest] == INF)
            {
                cout << "INF\t-\n";
            }
            else
            {
                int next = dest;

                if (dest != src)
                {
                    while (parent[next] != src && parent[next] != -1)
                        next = parent[next];
                }

                cout << dist[dest] << "\t"
                     << (dest == src ? src + 1 : next + 1)
                     << endl;
            }
        }
    }

    return 0;
}