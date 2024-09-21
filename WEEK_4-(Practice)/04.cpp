#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<float, float>> atten;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        pair<float, float> p = make_pair(a, b);
        atten.push_back(p);
    }
    int ansPos = 0;
    float minP = 2e9;
    for(int i = 0; i < n; i++){
        float p = 0;
        for(int j = 0; j < n; j++){
            if(j == i){
                continue;
            }
            float a1 = atten[i].first,
                  a2 = atten[j].first,
                  b1 = atten[i].second,
                  b2 = atten[j].second;
            p += (((abs(a1 - a2)) / (abs(a1) + abs(a2))) + (abs(b1 - b2) / (abs(b1) + abs(b2))));
        }
        cout << "p: " <<  p << "\n";
        if(minP >= p){
            minP = p;
            ansPos = i;
        }
    }
    cout << atten[ansPos].first << " " << atten[ansPos].second;
}
