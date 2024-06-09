#ifndef BELLMAN_H
#define BELLMAN_H

#include <iostream>
#include <string>

using namespace std;

const int BELLMAN_MAX_VERTICES = 20;

void BF(int graph[BELLMAN_MAX_VERTICES][BELLMAN_MAX_VERTICES], int numOfVertices, char startVertex, int value[BELLMAN_MAX_VERTICES], int previous[BELLMAN_MAX_VERTICES]);

string BF_Path(int graph[BELLMAN_MAX_VERTICES][BELLMAN_MAX_VERTICES], int numOfVertices, char startVertex, char goalVertex);

#endif // !BELLMAN_H