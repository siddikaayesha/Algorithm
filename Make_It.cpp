#include <bits/stdc++.h>
using namespace std;

vector<int> dp(100000, -1);

bool canReach(int current, int n) {
    if (current == n) return true;
    if (current > n) return false;
    if (dp[current] != -1) return dp[current];
    bool op1 = canReach(current + 3, n);
    bool op2 = canReach(current * 2, n); 
    return dp[current] = (op1 || op2);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        for (size_t i = 0; i < dp.size(); i++) {
            dp[i] = -1;
        }
        
        if (canReach(1, n)) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
