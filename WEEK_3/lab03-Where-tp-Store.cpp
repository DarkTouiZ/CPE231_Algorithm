#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>

using namespace std;
bool isPalin(const string &str);
vector<bool> binary(int nBits, int n);
string filterByBits(const string &str, const vector<bool> &bits);

int main()
{

    string name;
    cin >> name;

    int nBits = name.size();

    set<string> palindromeSet;

    // Check all possible combinations of bits that palindromes can be formed from the name
    for (int i = 0; i < pow(2, nBits); i++)
    {
        vector<bool> bits = binary(nBits, i);

        string filteredStr = filterByBits(name, bits);

        if (isPalin(filteredStr) && filteredStr.size() > 1)
        {
            palindromeSet.insert(filteredStr); // Insert the palindrome into the set
        }
    }

    cout << palindromeSet.size() << endl;

    return 0;
}

bool isPalin(const string &str)
{
    int left = 0;
    int right = str.size() - 1;
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

vector<bool> binary(int nBits, int n)
{
    vector<bool> bits(nBits, 0);
    int i = nBits - 1;
    while (n && i >= 0)
    {
        bits[i] = n % 2;
        n /= 2;
        i--;
    }
    return bits;
}

string filterByBits(const string &str, const vector<bool> &bits)
{
    string result = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (bits[i])
        {
            result += str[i];
        }
    }
    return result;
}