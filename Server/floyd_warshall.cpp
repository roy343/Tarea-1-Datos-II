#include "floyd_warshall.h"

floyd_warshall::floyd_warshall()
{
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0}
                    };


    void printSolution(int dist[][V]);


    void floydWarshall ();

        int dist[V][V], i, j, k;

        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = graph[i][j];
        for (k = 0; k < V; k++)
        {
            for (i = 0; i < V; i++)
            {
                for (j = 0; j < V; j++)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }


        printSolution(dist);
    }


    void printSolution(int dist[][V])
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INF)
                    cout<<"INF"<<"     ";
                else
                    cout<<dist[i][j]<<"     ";
            }
            cout<<endl;
        }
    }


}
