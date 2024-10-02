// Adisorn Parama 66070501060
// Presorted Uniqueness

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int HoarePartition(vector<int> &arr, int l, int r){
        int pivot = arr[l];
        int i = l;
        int j = r + 1;
        while(i < j){
            do{
                i++;
            }while(arr[i] < pivot);
            do{
                j--;
            }while(arr[j] > pivot);
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[j]);
        swap(arr[l], arr[j]);
        return j;
    }

    void QuickSort(vector<int> &arr, int l, int r){
        if(l < r){
            int s = HoarePartition(arr, l, r);
            QuickSort(arr, l, s - 1);
            QuickSort(arr, s + 1, r);
        }
        return;
    }


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<int> result;
    //sort array
    QuickSort(arr, 0, n-1);
    //check if the number is unique
    for(int i = 0; i < n; ++i){
        if(arr[i] != arr[i+1]){
            result.push_back(arr[i]);
        }
    }

    //print the result
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    return 0;
}