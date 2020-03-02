#include <iostream>
#include <list>

using namespace std;

class Graphy {
    int numVertices;
    list<int>* adjList;

    public:
    Graphy(int v);
    void addEdge(int src, int des);
};

Graphy::Graphy(int vertices) {
    numVertices = vertices;
    adjList = new list<int>[vertices];
}

void Graphy::addEdge(int src, int des) {
    adjList[src].push_front(des);
}

int main() {
    Graphy g(3);
    g.addEdge(2, 4);
    g.addEdge(6, 1);
    g.addEdge(7, 0);
    g.addEdge(5, 2);

    return 0;
}