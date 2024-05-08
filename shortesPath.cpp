#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_NODES = 100;

// Function to find the shortest path from the source node to all other nodes
void dijkstra(vector<vector<int>>& graph, int source, vector<int>& distances) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    // Initialize distances from the source node
    for (int i = 0; i < numNodes; i++)
        distances[i] = INT_MAX;
    distances[source] = 0;

    // Create a priority queue to get the node with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;

        // Update distances of neighbors
        for (int v = 0; v < numNodes; v++) {
            if (!visited[v] && graph[u][v] != 0 && distances[u] != INT_MAX &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int numNodes, numEdges, source;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;

    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int u, v, weight;
        cout << "Enter the edge (node1 node2 weight): ";
        cin >> u >> v >> weight;
        graph[u - 1][v - 1] = weight;
        graph[v - 1][u - 1] = weight;
    }

    cout << "Enter the source node: ";
    cin >> source;
    source--;  // Adjust for 0-based indexing

    vector<int> distances(numNodes, INT_MAX);

    dijkstra(graph, source, distances);

    cout << "Shortest distances from node " << source + 1 << ":" << endl;
    for (int i = 0; i < distances.size(); i++)
        cout << "Node " << i + 1 << ": " << distances[i] << endl;

    return 0;
}
