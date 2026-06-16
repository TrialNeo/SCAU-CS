#include <iostream>
#include <vector>
using namespace std;


void traversal(const vector<vector<bool>> &graph) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    int x = 0, y = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        graph[x - 1][y - 1] = true;
    }
    traversal(graph);
}
