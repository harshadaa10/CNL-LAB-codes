#include <iostream>
using namespace std;

#define INF 999

int main()
{
    int n;

    cout << "Enter number of routers: ";
    cin >> n;

    int cost[10][10];
    int dist[10][10];
    int next[10][10];

    // Input cost matrix
    cout << "\nEnter Cost Matrix (999 for no connection):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            dist[i][j] = cost[i][j];

            if (cost[i][j] != INF && i != j)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Display initial cost matrix
    cout << "\nInitial Cost Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }

    // Initial routing tables
    cout << "\nInitial Routing Tables:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nRouter " << char('A' + i) << endl;

        cout << "Destination\tCost\tNext Hop\n";

        for (int j = 0; j < n; j++)
        {
            cout << char('A' + j) << "\t\t";

            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";

            if (next[i][j] == -1)
                cout << "-";
            else
                cout << char('A' + next[i][j]);

            cout << endl;
        }
    }

    // Distance Vector Algorithm
    bool change = true;

    while (change)
    {
        change = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (cost[i][k] != INF && dist[k][j] != INF)
                    {
                        int newCost = cost[i][k] + dist[k][j];

                        if (newCost < dist[i][j])
                        {
                            dist[i][j] = newCost;
                            next[i][j] = k;
                            change = true;
                        }
                    }
                }
            }
        }
    }

    // Final routing tables
    cout << "\nFinal Routing Tables:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nRouter " << char('A' + i) << endl;

        cout << "Destination\tCost\tNext Hop\n";

        for (int j = 0; j < n; j++)
        {
            cout << char('A' + j) << "\t\t";

            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";

            if (next[i][j] == -1)
                cout << "-";
            else
                cout << char('A' + next[i][j]);

            cout << endl;
        }
    }

    // Find shortest path
    char source, destination;

    cout << "\nEnter Source Router: ";
    cin >> source;

    cout << "Enter Destination Router: ";
    cin >> destination;

    int s = source - 'A';
    int d = destination - 'A';

    cout << "\nShortest Path: ";

    int current = s;

    cout << char('A' + current);

    while (current != d)
    {
        current = next[current][d];
        cout << " -> " << char('A' + current);
    }

    cout << "\nMinimum Cost: " << dist[s][d] << endl;

    return 0;
}