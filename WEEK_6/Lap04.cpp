// Adisorn Parama 66070501060
// Make a Wish

#include <iostream>
#include <vector>

using namespace std;

int findMaxSubArraySum(vector<int> arr, int l, int r);

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int mx = -2e9;
    //find the biggest continous number in the array (using brute force)
    // for(int i = 0; i < n; ++i){
    //     int sum = 0;
    //     for(int j = i; j < n; ++j){
    //         sum += arr[j];
    //         if(sum > max){
    //             max = sum;
    //         }
    //     }
    // }

    //find the biggest continous number in the array (using divide-and-conquer)
    // Call function
    // max = findMaxSubArraySum(arr, 0, n-1);

    //find the biggest continous number in the array (using Kadane's algorithm)
    mx = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {
      
        // Update maxEnding to be the maximum of maxEnding + arr[i] or arr[i]
        maxEnding = max(maxEnding + arr[i], arr[i]);
      
        // Update mx if maximum subarray sum ending at index i > mx
        mx = max(mx, maxEnding);
    }

    cout << mx ;
    
    return 0;
}


int maxCrossingSum(vector<int> arr, int l, int m, int r){
    int sum = 0;
    //find the biggest sum from the middle to the left
    int leftSum = -2e9;
    for(int i = m; i >= l; --i){
        sum += arr[i];
        if(sum > leftSum){
            leftSum = sum;
        }
    }

    sum = 0;
    //find the biggest sum from the middle to the right
    int rightSum = -2e9;
    for(int i = m+1; i <= r; ++i){
        sum += arr[i];
        if(sum > rightSum){
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int findMaxSubArraySum(vector<int> arr, int l, int r){
    if(l == r){
        return arr[l];
    }else{
        int m = (l+r)/2;
        int leftMax = findMaxSubArraySum(arr, l, m);
        int rightMax = findMaxSubArraySum(arr, m+1, r);
        int crossMax = maxCrossingSum(arr, l, m, r);
        return max(max(leftMax, rightMax), crossMax);
    }
}