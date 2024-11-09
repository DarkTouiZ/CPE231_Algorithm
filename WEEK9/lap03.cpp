//ADISORN PARAMA 66070501060
//LAB# GRILLED GOOSE

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    vector<int> boxSize(n);
    for (int i = 0; i < n; i++){
        cin >> boxSize[i];
    }

    vector<bool> dp(x + 1, false);
    dp[0] = true;

    for(int i = 0; i < n; i++){
        for(int j = boxSize[i]; j <= x; j++){
            if(dp[j - boxSize[i]]){
                dp[j] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= x; i++){
        if(!dp[i]){
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}