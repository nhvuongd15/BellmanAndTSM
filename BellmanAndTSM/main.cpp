#include <iostream>
#include "Bellman.h"
#include "TSM.h"

using namespace std;

// 12 vertex, all edges have possitive weight
int graph[20][20] = {
			{0, 3, 2, 7, 0, 4, 7, 3, 11, 5, 6, 8},
			{3, 0, 4, 8, 5, 6, 9, 10, 7, 8, 9, 11},
			{2, 4, 0, 6, 3, 5 , 1, 0, 9, 3, 10, 5},
			{7, 8, 5, 0, 2, 7, 1, 0, 3, 4, 8, 2},
			{10, 5, 1, 3, 0, 3, 7, 5, 9, 10, 2, 5},
			{4, 1, 7, 4, 1, 0, 2, 6, 5, 1, 7, 9},
			{7, 3, 8, 5, 3, 1, 0, 1, 3, 10, 3, 2},
			{3, 10, 0, 6, 4, 2, 1, 0, 9, 5, 3, 1},
			{11, 7, 2, 7, 4, 6, 4, 1, 0, 8, 4, 3},
			{5, 8, 11, 2, 6, 0, 3, 5, 1, 0, 10, 5},
			{6, 9, 12, 9, 1, 5, 7, 2, 9, 3, 0, 3},
			{8, 11, 13, 1, 8, 1, 2, 6, 5, 2, 3, 0}
};

int main()
{
	/*int value[20], previous[20];
	for (int i = 0; i < 20; i++) {
		value[i] = -1;
		previous[i] = -1;
	}

	BF(graph, 8, 'D', value, previous);

	for (int i = 0; i < 8; i++) {
		cout << value[i] << " ";
	}*/


	// cout << BF_Path(graph, 4, 'B', 'D') << endl;*/

	// int graph[20][20] = { {0, 10, 0, 5}, {0, 0, 1, 2}, {5, 0, 0, 0}, {5, 3, 9, 0} };

	cout << Traveling(graph, 12, 'D') << endl;

	return 0;
}
