#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int even = 0, odd = 0;

vector<bool> convertToBinary(int nBits, int n);
string NumUsedfiterByBits(const string &str, const vector<bool> &bits);
bool isEqualKey(const string &str, int *ecount, int *ocount, int key);


int main()
{
    int x, key;
    cin >> x >> key;


    // convert number to string
    string strNum = "";
    for(int i = 1; i <= x; ++i){
        strNum += to_string(i);
    }
    int nBits = strNum.size();

    for(int i = 0; i < pow(2, nBits); ++i){
        vector<bool> bits = convertToBinary(nBits, i);

        string filteredStr = NumUsedfiterByBits(strNum, bits);

        int Sum = 0, ecount = 0, ocount = 0;
        if(isEqualKey(filteredStr, &ecount, &ocount, key)){
            even += ecount;
            odd += ocount;
        }
    }

    cout << odd << "\n" << even;


    return 0;
}

vector<bool> convertToBinary(int nBits, int n){
    vector<bool> bits(nBits, 0);
    int i = nBits - 1;
    while(n && i >= 0){
        bits[i] = n % 2;
        n /= 2;
        i --;
    }
    return bits;
}

string NumUsedfiterByBits(const string &str, const vector<bool> &bits){
    string result = "";
    for(int i = 0; i < str.size(); i ++){
        if(bits[i]){
            result += str[i];
        }
    }
    return result;
}

bool isEqualKey(const string &str, int *ecount, int *ocount, int key){
    int sum = 0;
    for(int i = 0; i < str.size(); ++i){
        if((str[i] - '0') % 2 == 0){ //convert char to int
            *ecount += 1;
        }else{
            *ocount += 1;
        }

        sum += str[i] - '0'; //convert char to int
    }

    if(sum != key){
        return false;
    }

    return true;
}
