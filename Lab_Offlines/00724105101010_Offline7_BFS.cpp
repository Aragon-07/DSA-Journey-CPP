#include <bits/stdc++.h>

using namespace std;

void bfs(int startNode, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int nodes = 10;
    vector<vector<int>> adj(nodes);

    adj[0] = {1, 2};
    adj[1] = {0, 2, 3, 4};
    adj[2] = {0, 1};
    adj[3] = {1, 5};
    adj[4] = {1};
    adj[5] = {3, 6, 7, 8};
    adj[6] = {5};
    adj[7] = {5, 8};
    adj[8] = {5, 7, 9};
    adj[9] = {8};

    bfs(0, adj);
    return 0;
}