#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while(e--){
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }

    int q; 
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        if(u==v){
            cout << "YES" << endl;
        }
        else if (mat[u][v] == 1) {
            cout << "YES" << endl;
        } 
        
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
