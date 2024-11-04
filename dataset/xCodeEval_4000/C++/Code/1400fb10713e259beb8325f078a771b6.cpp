




#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 0;
        double al, ar;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            if (!i)
                scanf("%lf", &al);
            else
            {
                scanf("%lf", &ar);
                double ma = max(al, ar),
                    mi = min(al, ar);
                while (ma / mi > 2)
                {
                    mi *= 2;
                    ans++;
                }
                al = ar;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
} 


















































































































































































