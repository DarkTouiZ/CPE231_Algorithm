#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<vector<float>> price(n, vector<float>(n, 0));

    vector<int> index; // for make permutation of column index
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> price[i][j];
        }
        index.push_back(i);
    }
    
    float mxSum = 0;
    do{
        float sum = 0;
        int i = 0;
        for(auto it : index){ // it is column index with permutation
            sum += price[i][it]; // sum of price of the purchase
            i++;
        } 
        if(sum > mxSum){
            mxSum = sum;
        }
    }while(next_permutation(index.begin(), index.end())); // generate all possible permutation of column index
    cout << mxSum;
    return 0;
}