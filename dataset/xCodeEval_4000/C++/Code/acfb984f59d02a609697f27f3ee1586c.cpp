













#pragma GCC optimize("O3")
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stack>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


#define en "\n"
#define sqrt(n) sqrt((double) n)
#define double long double
#define all(c) (c).begin() , (c).end()
#define int long long
#define mem0(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;
using namespace std;
char arr[100][100];
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int W=50,H=50;
    for (int i=1; i<=H; ++i)
        for (int j=1; j<=W/2; ++j)
                arr[i][j]='A';
    --a;
    for (int i=1; i<=H; ++i)
        for (int j=W/2+1; j<=W; ++j)
                arr[i][j]='B';
    
    --b;
    for (int i=1; i<=H; ++i)
        for (int j=1; j<=W/2-5; ++j)
            if (i%2 && j%2){
               

                if (b)
                    arr[i][j]='B',--b;
                else if (c)
                    arr[i][j]='C',--c;
                else if (d)
                    arr[i][j]='D',--d;
                else arr[i][j]='A';
               

               

            }
    for (int i=1; i<=H; ++i)
        for (int j=W/2+5; j<=W; ++j)
            if (i%2 && j%2){
                if (a)
                    arr[i][j]='A',--a;
                else if (c)
                    arr[i][j]='C',--c;
                else if (d)
                    arr[i][j]='D',--d;
                else arr[i][j]='B';
            }
    cout<<W<<" "<<H<<en;
    for (int i=1; i<=W; ++i){
        for (int j=1; j<=H; ++j)
            cout<<arr[i][j];
        cout<<en;
    }
    return 0;
}
