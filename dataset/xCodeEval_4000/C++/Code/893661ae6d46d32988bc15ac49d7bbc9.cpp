













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
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FOR(i,st,fin) for((int) i=st; i<fin; ++i)
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int gcd(int a,int b){
    

    while (a && b){
        if (a>b) a=a%b;
        else b=b%a;
    }
    

    

    return a+b;
}
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    int x;
    int gcdd=k;
    for (int i=0; i<n; ++i){
        cin>>x;
        x%=k;
        gcdd=gcd(gcdd,x);
       

    }
    cout<<k/gcdd<<en;
    for (int i=0; i*gcdd<k; ++i){
        cout<<i*gcdd<<" ";
    }
    return 0;
}
