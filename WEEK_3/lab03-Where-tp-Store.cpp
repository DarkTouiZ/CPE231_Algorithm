#include <iostream>
#include <string>

using namespace std;
int solution = 0;
int findAllEachPalin(string name, int i, int j);

int main(){
    string name;
    cin >> name;

    solution = findAllEachPalin(name, 0, name.length()-1);
    cout << solution << endl;
    return 0;
}

int findAllEachPalin(string name, int i, int j){
    // base case
    if(j - i == 1){
        return 1;
    }
    if(i >= j){
        return 0;
    }

    // recursive case
    if(name[i] == name[j]){
        return 1 + findAllEachPalin(name, i+1, j) + findAllEachPalin(name, i, j-1);
    }else{
        return findAllEachPalin(name, i+1, j) + findAllEachPalin(name, i, j-1) - findAllEachPalin(name, i+1, j-1);
    }
}