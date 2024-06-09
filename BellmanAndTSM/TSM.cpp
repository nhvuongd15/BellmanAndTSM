#include "TSM.h"

bool nextPermutation(int current[TSM_MAX_VERTICES], int n) {
	// Find the largest x such that current[x] < current[x + 1]
	int i = n - 1;
	while (i > 0 && current[i - 1] >= current[i]) {
		i--;
	}
	if (i <= 0) {
		return false;
	}

	// Find the largest y such that current[y] > current[x]
	int j = n - 1;
	while (current[j] <= current[i - 1]) {
		j--;
	}

	// Swap current[x] and current[y]
	// For example, if current = {1, 2, 3, 5, 4}, then after swapping current = {1, 2, 4, 5, 3}
	int temp = current[i - 1];
	current[i - 1] = current[j];
	current[j] = temp;

	// Reverse the sub-array from current[x + 1] to current[n - 1]
	// For example, if current = {1, 2, 4, 5, 3}, then after reversing current = {1, 2, 4, 3, 5}
	j = n - 1;
	while (i < j) {
		temp = current[i];
		current[i] = current[j];
		current[j] = temp;
		i++;
		j--;
	}

	return true;
}

string Traveling(int graph[TSM_MAX_VERTICES][TSM_MAX_VERTICES], int numOfVertices, char startVertex) {
	int startVertexIndex = startVertex - 'A';

	// Initialize current permutation
	int current[TSM_MAX_VERTICES];
	for (int i = 0, j = 0; i < numOfVertices; i++, j++) {
		if (i == startVertexIndex) {
			j--;
			continue;
		}
		current[j] = i;
	}

	// Initialize minimum cost
	int minCost = INT_MAX;
	string minPath;

	// Find the minimum cost and path
	do {
		int cost = 0;
		int previous = startVertexIndex;

		// Calculate the cost of the current permutation
		for (int i = 0; i < numOfVertices - 1; i++) {
			if (graph[previous][current[i]] == 0) {
				cost = INT_MAX;
				break;
			}
			cost += graph[previous][current[i]];
			previous = current[i];
		}
		if (graph[previous][startVertexIndex] == 0 || cost == INT_MAX) {
			cost = INT_MAX;
		}
		else {
			cost += graph[previous][startVertexIndex];
		}

		// Update the minimum cost and path
		if (cost < minCost) {
			minCost = cost;
			string t;
			t.push_back(startVertex);
			for (int i = 0; i < numOfVertices - 1; i++) {
				t.push_back(' ');
				t.push_back(current[i] + 'A');
			}
			t.push_back(' ');
			t.push_back(startVertex);
			minPath = t;
		}
	} while (nextPermutation(current, numOfVertices - 1));

	return minPath;
}
