#include <iostream>
#include "list"
#include<vector>
using namespace std;

class Graph{
    int V;     // total num of vertex
    list<int> *l;   // l = 0*12345
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u =0; u<V ; u++){ // 0,1,2,3,4
            list<int> neighbor = l[u];
            cout << u << " : ";
            for(int v : neighbor){
               cout << v << " ";
            }
            cout << endl;

        }
    }
};


int main() {
    int V = 5;
Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);

    graph.print();


    return 0;
}
