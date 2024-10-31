#include <bits/stdc++.h>
using namespace std;

bool equalize(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    if (sum % 2 != 0) {
        return false;
    }
    int target = sum / 2;
    int dp[1001];
    memset(dp, false, sizeof(dp));

    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[target];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (equalize(arr, n)) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
