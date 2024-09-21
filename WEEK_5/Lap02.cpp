#include <iostream>
#include <vector>

using namespace std;

void flip(vector<int> &pancake, int k)
{
    for(int i = 0; i < k / 2; i++)
    {
        swap(pancake[i], pancake[k - i - 1]);
    }
}

void pancakeSort(vector<int> &pancake)
{
    int n = pancake.size();
    for(int i = n; i > 1; i--)
    {
        int maxIndex = 0;
        for(int j = 0; j < i; j++)
        {
            if(pancake[j] > pancake[maxIndex])
            {
                maxIndex = j;
            }
        }
        if(maxIndex == i - 1)
        {
            continue;
        }
        if(maxIndex != 0)
        {
            flip(pancake, maxIndex + 1);
        }
        flip(pancake, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> pancake(n);
    for(int i = 0; i < n; i++)
    {
        cin >> pancake[i];
    }
    
    pancakeSort(pancake);
    for(int i = 0; i < n; i++)
    {
        cout << pancake[i] << " ";
    }
    return 0;
}