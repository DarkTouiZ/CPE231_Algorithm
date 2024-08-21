#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;

    // start and end characters
    char start, end;
    // clear the buffer
    cin.ignore();
    cin >> start;
    cin.ignore(); 
    cin >> end;
    int p;
    cin >> p;

    //find solution
    int solution = 0;
    for(int i = 0; i < n.length(); i++){
        for(int j = i + p - 1; j < n.length(); j++){
            if(n[i] == start && n[j] == end && (j-i+1) >= p){
                solution++;
            }
        }
    }
    cout << solution << endl;
    return 0;
}