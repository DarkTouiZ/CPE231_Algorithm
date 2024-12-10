// ADISORN PARAMA 66070501060
//
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int dp[1000001][1000001];

void solve(vector<pair<int, int>> data, int n, int maxWeight)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            //if within weight and first row
            if (j >= data[i].first)
            {
                dp[i][j] = max(dp[i][j], data[i].second);
            }
            //if not first row
            if (i > 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                //if within weight
                if (j >= data[i].first)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - data[i].first] + data[i].second);
                }
            }
        }
    }
    cout << dp[n - 1][maxWeight] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; i++)
    {
        cin >> data[i].first >> data[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 1000001; j++)
        {
            dp[i][j] = 0;
        }
    }

    int maxWeight;
    cin >> maxWeight;
    
    solve(data, n, maxWeight);
    return 0;
}