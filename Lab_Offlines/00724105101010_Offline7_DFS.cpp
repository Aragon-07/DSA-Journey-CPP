#include <bits/stdc++.h>

using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
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

    vector<bool> visited(nodes, false);
    dfs(0, adj, visited);
    cout << endl;

    return 0;
}