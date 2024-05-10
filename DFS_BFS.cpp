#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void dfs(int adj_mat[10][10], int n, int node, int visited[10]) {
    cout << "DFS" << endl;
    stack<int> stk;
    stk.push(node);
    visited[node] = 1;

    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();
        cout << curr << "-->";

        for (int j = n - 1; j >= 0; j--) {
            if (adj_mat[curr][j] == 1 && visited[j] != 1) {
                stk.push(j);
                visited[j] = 1;
            }
        }
    }
    cout << "NULL" << endl;
}

void bfs(int adj_mat[10][10], int n, int node, int visited[10]) {
    cout << "BFS" << endl;
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << "-->";

        for (int j = 0; j < n; j++) {
            if (adj_mat[curr][j] == 1 && visited[j] != 1) {
                q.push(j);
                visited[j] = 1;
            }
        }
    }
    cout << "NULL" << endl;
}

void inorder(int adj_mat[10][10], int n, int node, int visited[10]) {
    if (visited[node] == 1) return;

    visited[node] = 1;
    for (int j = 0; j < n; j++) {
        if (adj_mat[node][j] == 1 && visited[j] != 1) {
            inorder(adj_mat, n, j, visited);
        }
    }
    cout << node << "-->";
}

int main() {
    int n;
    int adj_mat[10][10] = {0}, visited[10] = {0};

    cout << "Enter the total number of nodes in the graph: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Do you want to add the edge between " << i << " and " << j << "? (Y or N): ";
            char s; cin >> s;
            if (s == 'y' || s == 'Y') {
                adj_mat[i][j] = adj_mat[j][i] = 1;
            }
        }
    }

    int ch;
    do {
        cout << "\n\n";
        cout << "1. DFS" << endl;
        cout << "2. BFS" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                for (int i = 0; i < n; i++) visited[i] = 0;
                cout << "DFS on the given graph is: ";
                dfs(adj_mat, n, 0, visited);
                break;
            case 2:
                for (int i = 0; i < n; i++) visited[i] = 0;
                cout << "BFS on the given graph is: ";
                bfs(adj_mat, n, 0, visited);
                break;
            case 3:
                for (int i = 0; i < n; i++) visited[i] = 0;
                cout << "Inorder Traversal of the given graph is: ";
                inorder(adj_mat, n, 0, visited);
                cout << "NULL" << endl;
                break;
            case 0:
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    } while (ch != 0);

    cout << "Program Finished" << endl;

    return 0;
}
