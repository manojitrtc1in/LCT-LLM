





























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t, d;
    cin >> t >> d;
    vector<int> v;
    for (int i = 0; i < t; i++)
    {
        int h;
        cin >> h;
        v.push_back(h);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int lo = -1, hi = t - 1;
    int sum = 0;
    while (sum <=v.size())
    {
        int r = d / v[hi];
        r = r + 1;
        hi--;
        sum = sum + r;
        if (sum <= v.size())
            ans++;
        

    }
    cout << ans;
    return 0;
}