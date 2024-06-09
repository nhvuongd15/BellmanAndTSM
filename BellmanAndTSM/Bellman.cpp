#include "Bellman.h"

void BF(int graph[BELLMAN_MAX_VERTICES][BELLMAN_MAX_VERTICES], int numOfVertices, char startVertex, int value[BELLMAN_MAX_VERTICES], int previous[BELLMAN_MAX_VERTICES]) {
    int startVertexIndex = startVertex - 'A';

    // Count the number of uninitialized vertices
    int numOfUninitVertices = 0;

    for (int i = 0; i < numOfVertices; i++) {
        if (value[i] == -1) {
            numOfUninitVertices++;
        }
    }

    // CASE: Uninitialized
    if (numOfUninitVertices == numOfVertices) {
        // Initialize the start vertex
        value[startVertexIndex] = 0;
        previous[startVertexIndex] = -1;

        for (int u = 0; u < numOfVertices; u++) {
            // If there is an edge from startVertex to u
            if (u != startVertexIndex && graph[startVertexIndex][u] != 0) {
                value[u] = graph[startVertexIndex][u];
                previous[u] = startVertexIndex;
            }
        }
        return;
    }

    // CASE: Initialized, run Bellman-Ford algorithm

    // Copy the value array to distance array, distance array is a temporary array to store the new distance values
    int distance[BELLMAN_MAX_VERTICES];
    for (int i = 0; i < numOfVertices; i++) {
        distance[i] = value[i];
    }

    for (int u = 0; u < numOfVertices; u++) {
        for (int v = 0; v < numOfVertices; v++) {
            // If there is an edge from u to v and u is reachable from startVertex
            if (graph[u][v] != 0 && value[u] != -1) {
                // If the distance from startVertex to v THROUGH u is SHORTER than the current distance from startVertex to v
                // Update the distance from startVertex to v, and the previous vertex of v
                if (distance[v] == -1 || value[u] + graph[u][v] < distance[v]) {
                    distance[v] = value[u] + graph[u][v];
                    previous[v] = u;
                }
            }
        }
    }

    // Copy the distance array back to the value array
    for (int i = 0; i < numOfVertices; i++) {
        value[i] = distance[i];
    }
}

string BF_Path(int graph[BELLMAN_MAX_VERTICES][BELLMAN_MAX_VERTICES], int numOfVertices, char startVertex, char goalVertex) {
    int value[BELLMAN_MAX_VERTICES], previous[BELLMAN_MAX_VERTICES];
    int startVertexIndex = startVertex - 'A', goalVertexIndex = goalVertex - 'A';

    // Initialize the value and previous arrays
    for (int i = 0; i < numOfVertices; i++) {
        value[i] = -1;
		previous[i] = -1;
    }

    // Run the Bellman-Ford algorithm
    for (int i = 0; i < numOfVertices; i++) {
        BF(graph, numOfVertices, startVertex, value, previous);
    }

    if (value[goalVertexIndex] == -1) {
        return "";
    }

    string path;
    
    // Reconstruct the path from startVertex to goalVertex
    int currentVertex = goalVertexIndex;
    while (currentVertex != startVertexIndex) {
		path = ' ' + string(1, currentVertex + 'A') + path;
		currentVertex = previous[currentVertex];
	}
    path = startVertex + path;

    return path;
}
