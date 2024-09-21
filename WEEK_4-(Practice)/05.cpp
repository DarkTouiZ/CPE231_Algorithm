#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>
#include <string>

using namespace std;

class Graph{
    map<string, list<pair<string, int>>>
        adjList;

public:

    //the graph
    void add_Edge(string initial,string terminal, int weight){
        //undirected graph
        adjList[initial].push_back(make_pair(terminal, weight)); //add edge from initial to terminal
        adjList[terminal].push_back(make_pair(initial, weight)); //add edge from terminal to initial
    }

    void print(){
        for(auto i : adjList){
            cout << i.first << "->  ";
            for(auto j : i.second){
                cout << j.first << " : " << j.second << " -> ";
            }
            cout << endl;
        }
    }
};


int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    Graph g;
    for(int i = 0; i < edges; ++i){
        string tmpI, tmpT;
        int cost;
        char ch;
        cin >> tmpI;
        ch = getchar(); //clear buffer

        cin >> tmpT;
        ch = getchar();

        cin >> cost;
        g.add_Edge(tmpI, tmpT, cost);
    }




    g.print();
    return 0;
}
