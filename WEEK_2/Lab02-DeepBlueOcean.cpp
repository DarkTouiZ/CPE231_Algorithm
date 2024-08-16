#include <iostream>

int factorial(int n){
    if(n == 1){
        return 1;
    }
    return factorial(n-1) * n;
}

using namespace std;
int main() {
    int n, v;
    cin >> n >> v;
    int p;
    cin >> p;
    
    int solution;
    solution = factorial(n-1) * (n-p);
    
    cout << solution;
    return 0;
}