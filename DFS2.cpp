#include <vector>
#include <iostream>
#include <stack>
#include <utility>

// #define deb(x) cout << #x << " " << x << endl;
// #define fo(i, n) for(i = 0; i < n; i++)
// #define fo(i, k, n) for(i = k; i < n; i++) 
// template<typename... T>
// void write(T&... args) { ((cout << args << " "), ...) }

using namespace std;

class Graph{
    vector<vector<int>> adjList;
    public:
    Graph(int nVer, vector<pair<int, int>>& edges);
    void DFS(Graph& g, int source, vector<bool>& visited);
    void DFSiter(Graph& g, int source, vector<bool>& visited);
};

Graph::Graph(int nVer, vector<pair<int, int>>& edges) {
    adjList.resize(nVer);
    for(auto i: edges) {
        adjList[i.first].push_back(i.second);
        adjList[i.second].push_back(i.first);
    }
}

void Graph::DFS(Graph& g, int source, vector<bool>& visited) {
    visited[source] = true;
    cout << source << " ";
    for(auto i: g.adjList[source]) if(!visited[i]) DFS(g, i, visited);
}

void Graph::DFSiter(Graph& g, int source, vector<bool>& visited) {
    stack<int> st;
    st.push(source);

    while(!st.empty()) {
        int top = st.top(); st.pop();

        if(visited[top]) continue;

        visited[top] = true;
        cout << top << " ";

        for(auto i: g.adjList[top]) if(!visited[i]) st.push(i); // reverse visit order
        // for(auto i = g.adjList.rbegin(); i != g.adjList.rend(); i++) if(!visited[*i]) st.push(*i)
    }
}


int main() {
    vector<pair<int, int>> edges = { {0, 1}, {0, 2}, {0, 4}, {1, 6}, {2, 1}, {2, 5}, {4, 6}, {4, 7}, {5, 1}, {5, 3}, {5, 7}, {6, 4}, {7, 5} };
    Graph g(8, edges);
    vector<bool> visited(8);
    g.DFS(g, 0, visited);
    return 0;
}

// { {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {} };