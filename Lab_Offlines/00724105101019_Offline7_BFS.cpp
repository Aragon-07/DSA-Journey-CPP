#include<bits/stdc++.h>

using namespace std;

void bfs(int startNode, vector<vector<int>>& adj, int totalNodes) {
    vector<bool> visited(totalNodes, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes = 5;
    vector<vector<int>> adj(nodes);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    bfs(0, adj, nodes);

    return 0;
}
