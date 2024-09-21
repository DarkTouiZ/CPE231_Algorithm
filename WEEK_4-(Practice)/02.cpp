#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int calRough(const vector<int> area);
vector<bool> convertToBinary(int nBits, int n);
int minRough = 2e9;

int main(){
    int n;
    cin >> n;
    vector<int> area;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        area.push_back(tmp);
    }

    int l, m ,r;
    cin >> l >> m >> r;
    vector<int> sec;
    for(int i = l; i <= m; i++){
        sec.push_back(i);
    }
    for(int i = m - 1; i >= r; i--){
        sec.push_back(i);
    }

    //find solution
    for(int i = 0; i < pow(2, n - sec.size() + 1); ++i){
        vector<bool> bits = convertToBinary(n, i);
        vector<int> tmp = area;
        for(int j = 0; j < n - sec.size(); ++j){
            if(bits[j])
                for(int k = 0; k < sec.size(); ++k){
                    tmp[j+k] += sec[k];
                }
                int rough = calRough(tmp);
                if(rough < minRough)
                    minRough = rough;
            else{
                continue;
            }
        }
    }


    cout << minRough;
    return 0;
}

int calRough(const vector<int> area){
    int Rough = 0;
    for(int i = 0; i < area.size()-1; ++i){
        Rough += abs(area[i] - area[i+1]);
    }
    return Rough;
}

vector<bool> convertToBinary(int nBits,int n){
    vector<bool> bits(nBits, 0);
    int i = nBits - 1;
    while(n && i >= 0){
        bits[i] = n % 2;
        n /= 2;
        i--;
    }
    return bits;
}
