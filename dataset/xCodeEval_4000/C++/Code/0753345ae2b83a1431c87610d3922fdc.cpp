

#include <bits/stdc++.h>
 
using namespace std;
 
const double eps = 1e-4;
const int N = 100010;
 
int n, T;

int main()
{   
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n == 1) cout << 0 << endl;
        else if (n < 10) {
            cout << n - 1 << endl;
        }
        else {
            int t = 0, k = n;
            while (n)
            {
                t++;
                n /= 10;
            }
            int s = pow(10, t - 1);
            cout << k - s << endl;
        }
    }
    return 0;
}



