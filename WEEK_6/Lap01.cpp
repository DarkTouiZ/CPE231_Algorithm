// Adisorn Parama 66070501060 
// Merge Sort (bottom-up)
#include <iostream>
#include <vector>

using namespace std;

void BottomUpMergeSort(vector<int> &vector, int n);
void Merge(vector<int> &vector, int l, int m, int r);

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    //Merge sort
    BottomUpMergeSort(arr, n);

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    return 0;
}

void Merge(vector<int> &arr, int l, int m, int r){
    int n1 = m - l + 1; // size of left subarray
    int n2 = r - m; // size of right subarray

    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temp arrays L[] and R[]
    for(int i = 0; i < n1; ++i){
        L[i] = arr[l + i];
    }
    
    // cout << "L: ";
    // for(int i = 0; i < n1; ++i){
    //     cout << L[i] << " ";
    // }
    // cout << endl;

    for(int i = 0; i < n2; ++i){
        R[i] = arr[m + 1 + i];
    }

    // cout << "R: ";
    // for(int i = 0; i < n2; ++i){
    //     cout << R[i] << " ";
    // }
    // cout << endl;

    int i = 0;
    int j = 0;
    int k = l;

    // Merge the temp arrays to sort back into arr[l -> r]
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    return;
}

void BottomUpMergeSort(vector<int> &arr, int n){
    if(n < 2) return;

    int i = 1;
    while(i < n){
        int j = 0;
        while(j < n - i){
            if(n < j + 2 * i){
                //Merge(arr, j, j + i, n);
                Merge(arr, j, j + i - 1, n - 1);
            }else{
                //Merge(arr, j, j + i, j + 2 * i);
                Merge(arr, j, j + i - 1, j + 2 * i - 1);
            }
            j += 2 * i;
        }
        i *= 2;
    }
    return;
}