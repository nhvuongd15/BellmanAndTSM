#include <iostream>
#include "Bellman.h"
#include "TSM.h"

using namespace std;

void test1() {
	int value[20], previous[20];

	for (int i = 0; i < 20; i++) {
		value[i] = -1;
		previous[i] = -1;
	}

	int graph1[20][20] = {
		{0, 0, 3, 0},
		{2, 0, 6, 0},
		{0, 0, 0, 2},
		{0, 0, 0, 0}
	};

	cout << "#1. BF TEST (Graph1) - Step 1 - Start from B\n";
	cout << "Before:\nValue = ";
	for (int i = 0; i < 4; i++) {
		cout << value[i] << " ";
	}
	cout << endl;
	cout << "Previous = ";
	for (int i = 0; i < 4; i++) {
		cout << previous[i] << " ";
	}
	cout << "\n==========RESULT==========\n";

	BF(graph1, 4, 'B', value, previous);

	cout << "After:\nValue = ";
	for (int i = 0; i < 4; i++) {
		cout << value[i] << " ";
	}
	cout << endl;
	cout << "Previous = ";
	for (int i = 0; i < 4; i++) {
		cout << previous[i] << " ";
	}
	cout << endl;

	cout << "\n#1. BF TEST (Graph1) - Step 2 - Start from B\n";
	cout << "Before:\nValue = ";
	for (int i = 0; i < 4; i++) {
		cout << value[i] << " ";
	}
	cout << endl;
	cout << "Previous = ";
	for (int i = 0; i < 4; i++) {
		cout << previous[i] << " ";
	}

	cout << "\n==========RESULT==========\n";
	BF(graph1, 4, 'B', value, previous);

	cout << "After:\nValue = ";
	for (int i = 0; i < 4; i++) {
		cout << value[i] << " ";
	}
	cout << endl;
	cout << "Previous = ";
	for (int i = 0; i < 4; i++) {
		cout << previous[i] << " ";
	}
}

void test2() {
	int value[20], previous[20];

	for (int i = 0; i < 20; i++) {
		value[i] = -1;
		previous[i] = -1;
	}

	int graph2[20][20] = {
		{0, 0, 3, 0},
		{2, 0, 6, 0},
		{0, 0, 0, 2},
		{0, 0, 0, 0}
	};

	cout << "#2. BF_Path TEST (Graph2) - Start from B, destination D (expected: B A C D)\n";
	cout << "==========RESULT==========\n";
	cout << "Path: " << BF_Path(graph2, 4, 'B', 'D') << endl;
}

void test3() {
	int graph3[20][20] = {
		{ 0, 10, 15, 20 },
		{ 10, 0, 35, 25 },
		{ 15, 35, 0, 30 },
		{ 20, 25, 30, 0 }
	};

	cout << "#3. Traveling TEST (Graph3) - Start from A (Expect cost = 80, Path = A B D C A)\n";
	cout << "==========RESULT==========\n";
	cout << "Path = " << Traveling(graph3, 4, 'A') << endl;
}

int main()
{
	test1();

	cout << "\n\n-------------------------------------\n\n";

	test2();
	
	cout << "\n\n-------------------------------------\n\n";

	test3();

	return 0;
}
