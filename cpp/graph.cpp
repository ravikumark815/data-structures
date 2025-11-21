/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph {
    private:
        int nVertices;
        int nEdges;
        vector <vector <int>> graph;
    
    public:
        Graph(int vertices);
        ~Graph();
        void addEdge(int src, int dst);
        void print();
        void dfs(int startVertex);
        void bfs(int startVertex);
};

Graph::Graph(int vertices) {
    nVertices = vertices;
    graph.resize(nVertices, vector<int>(nVertices, 0));
    cout << "--- Graph created ---\n";
    return;
}

Graph::~Graph() {
    cout << "--- Graph deleted ---\n";
    return;
}

void Graph::addEdge(int src, int dst) {
    if ((src >= nVertices) || (dst >= nVertices)) {
        cout << "Invalid vertex provided \n";
        return;
    }
    graph[src][dst] = 1;
    cout << "Edge " << src << "--" << dst << " added" << endl;
    return;
}

void Graph::print() {
    cout << "Graph:\n";
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void Graph::dfs(int startVertex) {
    stack<int> s;
    vector<bool> visited(nVertices, false);
    cout << "DFS: ";

    s.push(startVertex);
    visited[startVertex] = true;
    while(!s.empty()) {
        int i = s.top();
        s.pop();
        cout << i << " ";
        for (int j = 0; j < nVertices; j++) {
            if ((graph[i][j] == 1) && (!visited[j])){
                s.push(j);
                visited[j] = true;
            }
        }
    }
    cout << endl;
    return;
}

void Graph::bfs(int startVertex) {
    queue<int> q;
    vector<bool> visited(nVertices, false);
    cout << "BFS: ";

    q.push(startVertex);
    visited[startVertex] = true;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        cout << i << " ";
        for (int j = 0; j < nVertices; j++) {
            if (graph[i][j] && (!visited[j])) {
                q.push(j);
                visited[j] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.print();
    g.dfs(0);
    g.bfs(0);

    return 0;
}