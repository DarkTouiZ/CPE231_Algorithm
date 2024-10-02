// Adisorn Parama 66070501060
// Heap Sort

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    vector<int> sortedList(n);
    //MaxHeapBottomUp
    for(int i = n/2 - 1; i >= 1; --i){
        int k = i;
        int v = arr[i];
        bool heap = false;
        while (!heap && 2*k <= n){
            int j = 2*k;
            if(j < n){
                if(arr[j] < arr[j+1])
                    j = j + 1;
            }

            if(v >= arr[j]){
                heap = true;
            }else{
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }

    //print result
    for(auto it : arr)
        cout << it << " "
    cout << endl;

    
    return 0;
}