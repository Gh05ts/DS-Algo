#include <vector>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Graph {
    vector<vector<int>> adjList;
    public:
    Graph(int nVert, vector<pair<int, int>>& edges);
    void BFS(Graph& g, int sour, vector<bool>& visited);
    void BFSiter(Graph& g, int sour, vector<bool>& visited); 
};

Graph::Graph(int nVert, vector<pair<int, int>>& edges) {
    adjList.resize(nVert);
    for(auto i: edges) {
        adjList[i.first].push_back(i.second);
        // adjList[i.second].push_back(i.first);
    }
}
void Graph::BFS(Graph& g, int sour, vector<bool>& visited) {


}

void Graph::BFSiter(Graph& g, int source, vector<bool>& visited) {
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while(!q.empty()) {
        int front = q.front(); q.pop();
        cout << front << " ";

        for(auto i: adjList[front]) if(!visited[i]) {
            visited[i] = true;
            q.push(i);
        }
    }
}

int main() {
    vector<pair<int, int>> edges = { {0, 1}, {0, 2}, {0, 4}, {1, 6}, {2, 1}, {2, 5}, {4, 6}, {4, 7}, {5, 1}, {5, 3}, {5, 7}, {6, 4}, {7, 5} };
    int V = 8;
    Graph g(V, edges);
    vector<bool> visited(V);
    g.BFSiter(g, 0, visited);
    return 0;
}