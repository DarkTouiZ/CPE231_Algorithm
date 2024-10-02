// Adisorn Parama 66070501060
// Heap Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int a, int b)
{
    return a > b;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    //MinHeapSort
    for(int i = n / 2 - 1; i >= 0; --i){
        int k = i;
        int v = arr[k];
        bool heap = false;
        //heapify 
        while(!heap && 2 * k + 1 < n){
            int j = 2 * k + 1; // why 2 * k + 1? because we need to find the left child of the node
            if(j < n - 1){ // if there is a right child
                if(arr[j] > arr[j + 1]){ // if right child is smaller than left child
                    j += 1;
                }
            }

            if(v <= arr[j]){ // if the parent is smaller than the child
                heap = true;
            }
            else{
                arr[k] = arr[j]; // swap the parent and the child
                k = j; // move to the child
            }
        }
        arr[k] = v; // put the parent to the right place
    }

    //print MinHeapSort
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    //print sorted array
    sort(arr.begin(), arr.end(), compare);
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
}