#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> mat[n];
    while (e--) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        sort(mat[i].begin(), mat[i].end(), greater<int>());
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        if (mat[x].empty()) {
            cout << -1 << endl;
        } 
        else {
            
            for (int child : mat[x]) {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
