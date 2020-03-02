#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

class Graph {
    int numVertices;
    list<pii>* adj;

    public:
        Graph(int v) {
            numVertices = v;
            adj = new list<pii>[v];
        }

        void addEdges(int u, int v, int w) {
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<int> dijk(int src) {
            priority_queue <pii, vector<pii>, greater<pii>> pq;
            vector<int> dist(numVertices, INT_MAX);

            pq.push(make_pair(0, src));
            dist[src] = 0;

            while(!pq.empty()) {
                int u = pq.top().second;
                pq.pop();

                for(auto i = adj[u].begin(); i != adj[u].end(); i++) {
                    int v = i->first;
                    int w = i->second;

                    if(dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            } return dist;
        }
};

int main() {
    Graph g(9);

    vector<int> ans(9, -1);

    g.addEdges(0, 1, 4); 
    g.addEdges(0, 7, 8); 
    g.addEdges(1, 2, 8); 
    g.addEdges(1, 7, 11); 
    g.addEdges(2, 3, 7); 
    g.addEdges(2, 8, 2); 
    g.addEdges(2, 5, 4); 
    g.addEdges(3, 4, 9); 
    g.addEdges(3, 5, 14); 
    g.addEdges(4, 5, 10); 
    g.addEdges(5, 6, 2); 
    g.addEdges(6, 7, 1); 
    g.addEdges(6, 8, 6);
    g.addEdges(7, 8, 7); 
    ans = g.dijk(7);

    cout << "Vertex" << "   " << "Distance from src" << endl; 
    for(int i = 0; i < ans.size(); i++) {
        cout << i << "              " << ans[i] << endl;
    }

    return 0;
}