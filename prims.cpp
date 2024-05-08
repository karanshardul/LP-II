#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

void primMST(vector<vector<int>>& graph, int vertices) {
    vector<int> parent(vertices, -1); // Array to store MST
    vector<int> key(vertices, INT_MAX); // Key values to pick the minimum weight edge
    vector<bool> inMST(vertices, false); // To track vertices included in MST

    // Priority queue to store vertices and their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Starting with vertex 0
    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (int v = 0; v < vertices; ++v) {
            if (!inMST[v] && graph[u][v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the edges of MST
    cout << "Edges in MST:" << endl;
    for (int i = 1; i < vertices; ++i)
        cout << parent[i] << " - " << i << endl;
}

int main() {
    int vertices, edges;
    cout << "Enter the total number of vertices: ";
    cin >> vertices;

    cout << "\nEnter the total number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

    for (int i = 0; i < edges; i++) {
        int node1, node2, weight;

        cout << "\nEnter the (node1 node2 weight): ";
        cin >> node1 >> node2 >> weight;

        graph[node1 - 1][node2 - 1] = weight;
        graph[node2 - 1][node1 - 1] = weight;
    }

    // Finding and printing MST using Prim's algorithm
    primMST(graph, vertices);

    return 0;
}
