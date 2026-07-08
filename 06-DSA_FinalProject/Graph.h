#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

    void dfsHelper(int vertex, vector<bool> &visited, vector<int> &out) const;

public:
    Graph(int vertices);

    void addEdge(int u, int v, bool bidirectional = true);
    int getNumVertices() const;
    void display() const;

    vector<int> bfs(int startVertex) const;
    vector<int> dfs(int startVertex) const;
};

#endif // GRAPH_H
