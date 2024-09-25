    // Adisorn Parama   66070501060
    #include <iostream>
    #include <vector>

    using namespace std;

    void QuickSort(vector<int> &arr, int l , int r);
    int HoarePartition(vector<int> &arr, int l, int r);

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

        //Quick sort
        QuickSort(arr, 0, n - 1);

        for(int i = 0; i < n; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;

        return 0;
    }

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
