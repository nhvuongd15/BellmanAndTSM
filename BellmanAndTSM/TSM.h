#ifndef TSM_H
#define TSM_H

#include <iostream>
#include <string>
#include <climits>

using namespace std;

const int TSM_MAX_VERTICES = 20;

string Traveling(int graph[TSM_MAX_VERTICES][TSM_MAX_VERTICES], int numOfVertices, char startVertex);

#endif // !TSM_H