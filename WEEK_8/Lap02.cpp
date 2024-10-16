// ADISORN PARAMA 66070501060
// Hash Table

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int findIndex(string str, int Z){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum += (int)str[i] - 65 + 1;
    }
    //cout << sum % Z << endl;
    return sum % Z;
}

int main()
{ 

    int Z, n;
    cin >> Z >> n;
    vector<string> Hash(Z, "NULL");
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        int hashIndex = findIndex(temp, Z);
        if(Hash[hashIndex] == "NULL"){
            Hash[hashIndex] = temp;
        }else{
            for(int j = 1; j < Z; j++){
                int newIndex = (hashIndex + j) % Z;
                if(Hash[newIndex] == "NULL"){
                    Hash[newIndex] = temp;
                    break;
                }
            }
        }
    }

    for(auto it : Hash){
        cout << it << " ";
    }

    return 0;
}