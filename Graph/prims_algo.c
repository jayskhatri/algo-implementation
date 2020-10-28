#include <bits/stdc++.h>

using namespace std;
#define V 8

bool isValidEdge(int u, int v, vector < bool > inMST) {
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}

void primMST(int cost[][V]) {
    vector < bool > inMST(V, false);
    inMST[0] = true;
    int edge_count = 0, mincost = 0;
    while (edge_count < V - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (cost[i][j] < min) {
                    if (isValidEdge(i, j, inMST)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("Edge %d:(%d, %d) cost: %d \n",
                edge_count++, a, b, min);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    printf("\n Minimum cost= %d \n", mincost);
}

int main() {
    printf("\t PRIMS ALGORITHM\n");
     printf("\t MINIMUM SPANNING TREE\n\n");
    int cost[][V] = { { INT_MAX,INT_MAX,2,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX },
                        { 6,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX },
                        { 3,8,INT_MAX,INT_MAX,5,INT_MAX,INT_MAX,INT_MAX },
                        { INT_MAX,9,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX },
                        { INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,INT_MAX },
                        { INT_MAX,INT_MAX,INT_MAX,7,INT_MAX,INT_MAX,INT_MAX,INT_MAX },
                        { INT_MAX,INT_MAX,9,INT_MAX,4,INT_MAX,INT_MAX,3 },
                        { INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,6,INT_MAX } };


    primMST(cost);
    return 0;
}
