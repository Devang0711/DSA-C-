#include "Graph.h"
#include <iostream>
#include <queue>
using namespace std;

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v, bool bidirectional) {
    if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) return;
    adjList[u].push_back(v);
    if (bidirectional) adjList[v].push_back(u);
}

int Graph::getNumVertices() const { return numVertices; }

void Graph::display() const {
    for (int i = 0; i < numVertices; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) cout << neighbor << " ";
        cout << "\n";
    }
}

// ---------- Breadth First Search ----------
// Explores level by level using a queue; good for shortest path in unweighted graphs.
vector<int> Graph::bfs(int startVertex) const {
    vector<int> out;
    if (startVertex < 0 || startVertex >= numVertices) return out;

    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        out.push_back(curr);

        for (int neighbor : adjList[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return out;
}

// ---------- Depth First Search ----------
// Explores as far as possible along each branch before backtracking (recursive).
void Graph::dfsHelper(int vertex, vector<bool> &visited, vector<int> &out) const {
    visited[vertex] = true;
    out.push_back(vertex);

    for (int neighbor : adjList[vertex]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, visited, out);
        }
    }
}

vector<int> Graph::dfs(int startVertex) const {
    vector<int> out;
    if (startVertex < 0 || startVertex >= numVertices) return out;

    vector<bool> visited(numVertices, false);
    dfsHelper(startVertex, visited, out);
    return out;
}
