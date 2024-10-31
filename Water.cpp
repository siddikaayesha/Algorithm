#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while (t--)
   {   
      int n;
      cin >> n;
      int a[n], b[n];
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         b[i] = a[i];
      }
      sort(b, b + n);

      int x,y;
      
      for (int i = 0; i < n; i++)
      {
         if (a[i] == b[n - 2])
            x = i;
         if (a[i] == b[n - 1])
            y = i;
      }
      if(x<y){
        cout << x << " " << y << endl;
      }
      else{
        cout << y << " " << x << endl;
      }
   }
}