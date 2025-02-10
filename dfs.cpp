#include git<iostream>
#include "list"
#include<vector>
#include "queue"
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

    void bfs(){  // travel unvisited member then TC = (V + E)  vertexes + edges
        queue<int> q;
        vector<int> visited(V, false); // V= 7 & firstly every index initialize with false
        q.push(0);  // first push the source node in he q which is 0
        visited[0] = true; // and mark it as a true in the vector

        while(q.size() > 0){
            int u = q.front();   // source vertex or curr vertex
            q.pop();            // after adding in the q pop it immoderately
            cout << u << " ";     // then print it into the output

            //now we want to travel the curr vertex neighbours

            list<int> neighbour = l[u];
            for(int v : neighbour){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }

        }
        cout << endl;

    }

    void dfs(int u , vector<bool>&visited){  // Time complexity : O(V + E)

        visited[u] =true;
        cout << u << " ";

        list<int> neighbour = l[u];
        for(int v : neighbour){
           if(visited[v] != true){
               dfs(v , visited);   // v= neighbour
           }
        }
    };
};


int main() {
    int V = 7;
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    vector<bool> visited(7 , false);
    graph.dfs(0 , visited);


    return 0;
}
