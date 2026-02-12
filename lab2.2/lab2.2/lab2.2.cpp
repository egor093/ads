#include <iostream>
#include <queue>
#include <stack>

using namespace std;
int CheckArr[10];
bool adjacencyMatrix[10][10] =
{
	{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
	{0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
};

vector<vector<int>> graph = {
			{1, 4},
			{6, 7},
			{7},
			{5, 8},
			{0, 5},
			{3, 4, 8},
			{1, 7},
			{1, 2, 6},
			{3, 5, 9},
			{8}
};

    int listOfRibsFrom[11] = { 1, 1, 2, 2, 3, 4, 4, 5, 6, 7, 9 };
	int listOfRibsTo[11] = { 2, 5, 7, 8, 8, 6, 9, 6, 9, 8, 10 };

void dfs(int v) {
	printf("%d ", v + 1);
	CheckArr[v] = true;
	for (int i = 0; i < 10; i++)
		if (adjacencyMatrix[v][i] == 1 && CheckArr[i] != 1)
			dfs(i);
}

void main() {
	setlocale(LC_ALL, "ru");


	cout << "Поиск в ширину: ";

	bool used[10];
	for (int i = 0; i < 10; i++)
		used[i] = false;

	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		used[u] = true;

		printf("%d ", u + 1);

		for (int i = 0; i < 10; i++) {
			if (!used[i] && adjacencyMatrix[u][i] == true) {
				q.push(i);
				used[i] = true;
			}
		}
	}
	cout << "\nПоиск в глубину: ";
	for (int i = 0; i < 10; i++)
	{
		CheckArr[i] = 0;
	}
	dfs(0);
}