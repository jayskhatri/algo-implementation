#include<iostream>
using namespace std;
void DFS(int);
int G[20][20], visited[20], n;
bool flag = false;

main() {
        int i, j;
        cout << "Enter number of vertices : ";
        cin >> n;
        cout << "Enter adjecency matrix of the graph \n";

        for (i = 0; i < n; i++) {
                cout << "For " << i << " : ";
                for (j = 0; j < n; j++)
                        cin >> G[i][j];
        }
        for (i = 0; i < n; i++)
                visited[i] = 0;

        DFS(0);
        if (flag)
                cout << "\nCycle is present in the graph.";
        else
                cout << "\nCycle is not present in the graph.";
}

void DFS(int i) {
        int j;
        if (visited[i] == 1) {
                flag = true;
                return;
        }
        visited[i] = 1;

        for (j = 0; j < n; j++)
                if (G[i][j] == 1)
                        DFS(j);
}

