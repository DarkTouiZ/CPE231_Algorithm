#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    //input number of trees jarn wee want decorate in the show
    int num;
    cin >> num;

    //spacial case 
    if(num == 0){
        cout << 0 << endl;
        return 0;
    }else if (num == 1)
    {
        cout << 0 << endl;
        return 0;
    }else if (num < 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    //end of spacial case
    
    //input the height of pot and tree
    vector<int> pot(num);
    for(int i = 0; i < num; i++){
        cin >> pot[i];
    }
    
    vector<int> tree(num);
    for(int i = 0; i < num; i++){
        cin >> tree[i];
    }

    // sort the pot and tree
    sort(pot.begin(), pot.end());
    sort(tree.begin(), tree.end(), cmp);

    // calculate the total height
    vector<int> total(num);
    for(int i = 0; i < num; i++){
        total[i] = pot[i] + tree[i];
    }
    
    // sort the total height to make the minimum difference of height
    sort(total.begin(), total.end());

    // calculate the total difference of height
    int total_diff = 0;
    for(int i = 0; i < num - 1; i++){
        total_diff += abs(total[i] - total[i + 1]);
    }
    
    cout << total_diff << endl;
    return 0;
}