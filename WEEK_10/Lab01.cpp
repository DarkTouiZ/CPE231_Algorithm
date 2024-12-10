// ADISORN PARAMA 66070501060
// LAB01 WEEK_10: MARRIAGE MATCHING PROBLEM
#include <iostream>
#include <vector>
using namespace std;

vector<int> matching(int n, vector<vector<int>>& company_preferences, vector<vector<int>>& student_preferences) {
    // Create student rank map for companies
    vector<vector<int>> student_rank(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            student_rank[i][student_preferences[i][j]] = j;
        }
    }

    //Initialize matching and tracking variables
    vector<int> company_match(n, -1);     // company to student
    vector<int> student_match(n, -1);    // student to company
    vector<bool> company_free(n, true);  // track if a company is free
    vector<int> next_student(n, 0);      // index of next student to propose to for each company

    //matching
    while (true) {
        // Find the first free company
        int company = -1;
        for (int i = 0; i < n; i++) {
            if (company_free[i]) {
                company = i;
                break;
            }
        }

        // Check if all companies are matched
        if (company == -1) break;

        // Get the next student this company prefers
        int student = company_preferences[company][next_student[company]];
        next_student[company]++;

        if (student_match[student] == -1) {
            // Student is free
            company_match[company] = student;
            student_match[student] = company;
            company_free[company] = false;
        } else {
            // Student is matched, check preference
            int current_company = student_match[student];
            if (student_rank[student][company] < student_rank[student][current_company]) {
                // Student prefers the new company
                company_match[company] = student;
                student_match[student] = company;
                company_free[company] = false;

                // Make the current company free
                company_match[current_company] = -1;
                company_free[current_company] = true;
            }
        }
    }

    return student_match;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> company_preferences(n, vector<int>(n));
    vector<vector<int>> student_preferences(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> company_preferences[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> student_preferences[i][j];
        }
    }

    vector<int> result = matching(n, company_preferences, student_preferences);

    for (int student = 0; student < n; student++) {
        cout << student << " " << result[student] << endl;
    }

    return 0;
}
