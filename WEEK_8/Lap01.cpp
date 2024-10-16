// ADISORN PARAMA 66070501060
// Lottery

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> ShiftTable(string lottery)
{
    vector<int> shiftTable(26, lottery.size());
    for (int i = lottery.size() - 2; i >= 0; i--){
        shiftTable[i] = lottery.size();
    }

    for (int j = 0; j < lottery.size() - 1; j++){
        shiftTable[lottery[j] - 'A'] = lottery.size() - 1 - j;
    }

    return shiftTable;
}

int strMatchHorspool(string str, string lottery, int* shiftCount)
{
    // create shift table A - Z
    vector<int> shiftTabel = ShiftTable(lottery);

    // match string with lottery
    int i = lottery.size() - 1;
    while (i <= str.size() - 1){
        int k = 0;
        while (k <= lottery.size() - 1 && str[i - k] == lottery[lottery.size() - 1 - k]){
            k++;
        }
        if (k == lottery.size()){
            return i - lottery.size() + 1;
        }else{
            i += shiftTabel[str[i] - 'A'];
            (*shiftCount)++;
        }
    }
    return -1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    string str, lottery;
    cin >> str >> lottery;
    int shiftCount = 0;
    int startIndex = strMatchHorspool(str, lottery, &shiftCount);
    if(startIndex == -1){
        cout << "NO "  << shiftCount << " " << startIndex << endl;
    }else{
        cout << "YES "  << shiftCount << " " << startIndex << endl;
    }

    return 0;
}