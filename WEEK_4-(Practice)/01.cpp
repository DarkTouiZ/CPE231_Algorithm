#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> decimalToBinary(int nBits,int number) {
    vector<bool> binaryBits(nBits, 0);
    for (int i = nBits - 1; number&& i>=0; i--) {
        binaryBits[i] = number % 2;
        number /= 2;
    }
    return binaryBits;
}

int main() {
    int x, y;
    int odd = 0;
    int even = 0;
    cin >> x
        >> y;
    for (int i = 0; i < pow(2, x); i++) {
        vector<bool> bits = decimalToBinary(x, i);
        int sum = 0,tmpOdd = 0,tmpEven = 0;
        for (int j = 1; j <= x; j++) { // j start from 1 for using for calculating odd and even numbers
            if (bits[j-1] == 0) // if bit in position j is n-1
                continue;
            sum += j;
            if (j % 2 == 0)
                tmpEven++;
            else
                tmpOdd++;
        }
        if (sum == y) {
            even += tmpEven;
            odd += tmpOdd;
        }
    }
    cout << odd << endl
         << even;
return 0;
}