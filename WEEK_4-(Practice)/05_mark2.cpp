#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

void printKey (map<string,int> &Map,int key)
{
    bool a = true;

    for (auto &it : Map)
    {
        if (it.second == key)
        {
            cout << it.first << " ";
            a = false;
        }
    }
    if (a)
    {
        cout << "-1"; // in case of not found key
    }
}

int main()
{
    int n,p,maxCost = 0;
    cin >> n >> p;
    vector< vector< int>> costCountry (n+1, vector< int>(n+1,0));
    //make map for unique country name
    map<string,int> country; // key = country name, value = index of country, index start from 1 for match with permutation
    country["THA"] = 0;

    // input data
    string initial, terminal;
    int cost,u,v;
    for (int i=0; i<p; i++)
    {
        int index = country.size();
        cin >> initial >> terminal >> cost;
        if(country.find(initial) == country.end()) // if name of initial contry not found
            country[initial] = index; // add to map
        if(country.find(terminal) == country.end()) // if name of terminal contry not found
            country[terminal] = index; // add to map
        u = country[initial];
        v = country[terminal];
        costCountry[u][v] = cost;
        costCountry[v][u] = cost;
    }
    
    vector<int> ptr,tmpResult(n+2,0),finalResult(n+2,0); // +2 for initial and terminal is "THA" country
    for (int i=1; i<n+1; i++)
    {
        ptr.push_back(i); // form ptr for permutation 
    }
    do
    {
        int sumCost = 0,i = 1;
        for (int out : ptr)
        {
            tmpResult[i] = out;
            i++;
        }
        for (i=0; i<n+1; i++)
        {
            u = tmpResult[i];
            v = tmpResult[i+1];
            if (costCountry[u][v] == 0)
                break;
            sumCost += costCountry[u][v];
        }

        if (sumCost > maxCost)
        {
            maxCost = sumCost;
            finalResult = tmpResult;
        }

    } while (next_permutation( ptr.begin(), ptr.end()));
    for (auto out : finalResult)
    {
        printKey(country,out);
    }
    cout << endl << maxCost;

    return 0;
}