#ifndef FLOYD_WARSHALL_H
#define FLOYD_WARSHALL_H

#include <bits/stdc++.h>
#define V 4
#define INF 99


class floyd_warshall
{
public:
    floyd_warshall();
    void printSolution(int dist[][V]);
    void floydWarshall (int graph[][V]);
};

#endif // FLOYD_WARSHALL_H
