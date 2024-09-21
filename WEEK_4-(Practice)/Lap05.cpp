#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjMatrix(vertices + 1, vector<int>(vertices + 1, 0)); // adjacency matrix asign with 0 all element
    map<string, int> country; // map for unique country name
    country["THA"] = 0; // initial country is "THA"

    for(int i = 0; i < edges; ++i){
        string initial, terminal;
        int cost;
        cin >> initial >> terminal >> cost;

        // if name of initial country not found
        if(country.find(initial) == country.end()){
            country[initial] = country.size(); // add to map and assign index of country with size of map (index start from 1 for match with permutation)
        }
        // if name of terminal country not found
        if(country.find(terminal) == country.end()){
            country[terminal] = country.size(); // add to map
        }

        int u = country[initial];
        int v = country[terminal];
        adjMatrix[u][v] = cost;
        adjMatrix[v][u] = cost;
    }
    vector<int> ptr, tmpResult(vertices + 2, 0), finalResult(vertices + 2, 0); // +2 for initial and terminal is "THA" country;
    for(int i = 1; i < vertices + 1; ++i){
        ptr.push_back(i); // form ptr for permutation
    }

    int maxCost = 0;
    do{
        int sumCost = 0, i = 1;
        for(int out : ptr){
            tmpResult[i] = out; // assign value of ptr to tmpResult without "THA" country
            i++;
        }
        for(i = 0; i < vertices + 1; ++i){
            int u = tmpResult[i]; // initial country index in permutation 
            int v = tmpResult[i + 1]; // terminal country index in permutation {THA, DEN, SWE, NOR, FIN, THA} > {0, 1, 2, 3, 4, 0} > 0->1, 1->2, 2->3, 3->4, 4->0
            if(adjMatrix[u][v] == 0){ // if not found cost of path
                break;
            }
            sumCost += adjMatrix[u][v];
        }

        if(sumCost > maxCost){
            maxCost = sumCost;
            finalResult = tmpResult;
        }
    } while(next_permutation(ptr.begin(), ptr.end()));

    for(auto out : finalResult){
        for(auto &it : country){
            if(it.second == out){
                cout << it.first << " ";
            }
        }
    }

    cout << endl << maxCost;

    return 0;
}