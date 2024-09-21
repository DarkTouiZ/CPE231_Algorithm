#include <iostream>
#include <vector>

using namespace std;

void quickSelect(vector<int> &list, int left, int right, int s)
{
    if(left >= right)
    {
        return;
    }

    int pivot = list[right];
    int i = left;
    for(int j = left; j < right; j++)
    {
        if(list[j] < pivot)
        {
            swap(list[i], list[j]);
            i++;
        }
    }
    swap(list[i], list[right]);

    if(i + 1 == s)
    {
        return;
    }
    else if(i + 1 < s)
    {
        quickSelect(list, i + 1, right, s);
    }
    else
    {
        quickSelect(list, left, i - 1, s);
    }
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> list(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> list[i];
    }

    // quick select
    int s;
    cin >> s;

    int left = 0, right = n - 1;
    quickSelect(list, left, right, s);
    cout << list[s - 1] << endl;
    return 0;
}
