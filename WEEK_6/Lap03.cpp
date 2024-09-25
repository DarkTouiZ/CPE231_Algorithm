// Adisorn Parama 66070501060
// 2D Closest Pair (using divide-and-conquer)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;
double minDistance = 2e9;

void ClosestPair(vector<pair<double, double>> point, int n);

int main()
{
    int n;
    cin >> n;
    vector<pair<double, double>> point(n);

    for (int i = 0; i < n; i++)
    {
        cin >> point[i].first >> point[i].second;
    }

    //sort
    sort(point.begin(), point.end());
    // find the distance between the closest pair
    ClosestPair(point, n);
    printf("%.3f", minDistance);
    return 0;
}    

void ClosestPair(vector<pair<double, double>> point, int n){
    // base case
    if(n <= 3){
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double distance = sqrt(pow(point[i].first - point[j].first, 2) + pow(point[i].second - point[j].second, 2));
                if(distance < minDistance){
                    minDistance = distance;
                }
            }
        }
        return;
    }


    int mid = n/2;
    vector<pair<double, double>> left;
    vector<pair<double, double>> right;
    for(int i = 0; i < mid; i++){
        left.push_back(point[i]);
    }
    for(int i = mid; i < n; i++){
        right.push_back(point[i]);
    }
    // recursive call
    ClosestPair(left, mid);
    ClosestPair(right, n-mid);

    // find the minimum distance between the left and right side
    double d = minDistance;
    vector<pair<double, double>> strip;
    for(int i = 0; i < n; i++){
        if(abs(point[i].first - point[mid].first) < d){
            strip.push_back(point[i]);
        }
    }

    for(int i = 0; i < strip.size(); i++){ 
        for(int j = i+1; j < strip.size() && (strip[j].second - strip[i].second) < d; j++){
            // check the distance between the points in the strip
            double distance = sqrt(pow(strip[i].first - strip[j].first, 2) + pow(strip[i].second - strip[j].second, 2)); // 
            if(distance < minDistance){
                minDistance = distance;
            }
        }
    }
    return;
}