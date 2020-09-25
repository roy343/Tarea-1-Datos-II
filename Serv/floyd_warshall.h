//
// Created by roy on 9/23/20.
//

#ifndef SERVER_FLOYD_WARSHALL_H
#define SERVER_FLOYD_WARSHALL_H

#include <bits/stdc++.h>
using namespace std;

#define V 4

#define INF 99999

void printSolution(int dist[][V]);

    void floydWarshall (int graph[][V])
    {

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

        // Print the shortest distance matrix
        printSolution(dist);
    }

/* A utility function to print solution */
    void printSolution(int dist[][V])
    {
        cout<<"The following matrix shows the shortest distances"
              " between every pair of vertices \n";
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INF)
                    cout<<"INF"<<" ";
                else
                    cout<<dist[i][j]<<"   ";
            }
            cout<<endl;
        }
    }


#endif //SERVER_FLOYD_WARSHALL_H
