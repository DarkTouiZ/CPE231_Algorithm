#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n, minDis = 2e9;
    cin >> n;
    vector<int> pos(n, 0);
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        pos[i] = tmp;
        if(i != 0){
            if(minDis > pos[i] - pos[i-1]){
                minDis = pos[i] - pos[i-1];
            }
        }
    }
    vector<int> newPos;
    for(int i = 0; i < n; ++i){
        if(i == 0)
            newPos.push_back(pos[i]);
        else
            newPos.push_back(newPos[i-1] + minDis);
    }

    for(int i = 0; i < n; ++i){
        cout << pos[i] - newPos[i] << " ";
    }
    return 0;
}
