#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int marks[], int n, int target) {
    bool dp[n + 1][target + 1];
        for (int i = 1; i <= target; i++)
        {
            dp[0][i] = false;
        }

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (marks[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - marks[i - 1]] || dp[i - 1][j];
            } 
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][target];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, obtained_marks;
        cin >> n >> obtained_marks;

        int marks[n];
        for (int i = 0; i < n; i++) {
            cin >> marks[i];
        }

        int target = 1000 - obtained_marks;

        if (target < 0) {
            cout << "NO" << endl;
        } 
        else {
            if (subsetSum(marks, n, target)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
