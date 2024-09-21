#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> students, tmp;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        students.push_back(make_pair(b, a));
    }

    tmp = students;
    for(int i = 0; i < n-1; ++i){
        int index, maxScore = -2e9, maxScoreID;
        for(int j = i; j < n-1; ++j){
            if(maxScore < students[j].first){
                index = j;
                maxScore = students[j].first;
                maxScoreID = students[j].second;
            }else if(maxScore == students[j].first){
                for(int k = 0; k < n; k++)
                {
                    if(maxScoreID == tmp[k].second){
                        break;
                    }
                    if(students[j].second == tmp[k].second){
                        index = j;
                        maxScore = students[j].first;
                        maxScoreID = students[j].second;
                        break;
                    }
                }
            }
        }
        //swap
        int tmpID = students[i].second, tmpScore= students[i].first;
        students[i].first = students[index].first;
        students[i].second = students[index].second;
        students[index].first = tmpScore;
        students[index].second = tmpID;
        //end swap
    }
    for(int i = 0; i < n; ++i){
        cout << students[i].second <<  " " << students[i].first << endl;
    }
    return 0;
}
