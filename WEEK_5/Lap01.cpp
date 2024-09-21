#include <iostream>
#include <vector>
#include <string>   

using namespace std;

bool MyNext_permutation(string &solution)
{
    int i = solution.size() - 1;
    while(i > 0 && solution[i - 1] >= solution[i])
    {
        i--;
    }
    if(i == 0)
    {
        return false;
    }
    int j = solution.size() - 1;
    while(solution[j] <= solution[i - 1])
    {
        j--;
    }
    swap(solution[i - 1], solution[j]);
    j = solution.size() - 1;
    while(i < j)
    {
        swap(solution[i], solution[j]);
        i++;
        j--;
    }
    return true;
}

void findSol_Nextpermutation(string solution,string pattern)
{
    int attempt = 1;
    //find the number of attempts to find the solution
    while(solution != pattern)
    {
        MyNext_permutation(solution);
        attempt++;
    }
    cout << attempt << endl;
}

int main()
{
    int n, question;
    cin >> n >> question;
    vector<string> pattern(question);
    for (int i = 0; i < question; i++)
    {
        cin >> pattern[i];
    }

    string solution;
    for(int i = 0; i < n; i++)
    {
        solution += (char)(i + 'A');
    }
    
    for(int i = 0; i < question; i++)
    {
        findSol_Nextpermutation(solution, pattern[i]);
    }
    return 0;
}