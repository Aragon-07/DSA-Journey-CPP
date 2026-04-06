#include<bits/stdc++.h>

using namespace std;

void dfsRecursive(int currentNode, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[currentNode] = true;
    cout << currentNode << " ";

    for (int neighbor : adj[currentNode]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited);
        }
    }
}

int main() {
    int nodes = 5;
    vector<vector<int>> adj(nodes);
    vector<bool> visited(nodes, false);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    cout << "DFS Traversal: ";
    dfsRecursive(0, adj, visited);
    cout << endl;

    return 0;
}
