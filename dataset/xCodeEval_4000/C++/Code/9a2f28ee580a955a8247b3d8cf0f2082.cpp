#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;



double n;
double a[1010];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    sum /= n;
    double b=-1,c=-1;
    int bb,cc,num=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=sum && b==-1)
        {
            b=a[i];
            bb=i;
            num++;
        }
        else if(a[i]!=sum)
        {
            c=a[i];
            cc=i;
            num++;
        }
    }
    if(num==2&&abs((b-c)/2)>=1)
    {
        if(c < b)
        {
            cout << (int)(b-c)/2 << " ml. from cup #" << cc << " to cup #" << bb << ".";
        }
        else
            cout << (int)(c-b)/2 << " ml. from cup #" << bb << " to cup #" << cc << ".";

    }
    else if(num==0)
    {
        cout << "Exemplary pages.";
    }
    else
        cout << "Unrecoverable configuration.";
    return 0;
}











































































