// ADISORN PARAMA 66070501060
// LAB1: Zigzag subsequence
#include <bits/stdc++.h>

using namespace std;
//dp[i][0] = max length of zigzag subsequence ending at i with last element greater than previous element
//dp[i][1] = max length of zigzag subsequence ending at i with last element smaller than previous element
int main()
{
    int n;
    cin >> n;

    vector<int> ziczac(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ziczac[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, 1));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ziczac[i] > ziczac[j])
            {
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            else if (ziczac[i] < ziczac[j])
            {
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << dp[i][0] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << dp[i][1] << " ";
    }
    cout << endl;

    return 0;
}