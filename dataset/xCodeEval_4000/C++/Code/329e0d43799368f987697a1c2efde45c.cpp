













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
#define sqrt(n) sqrt((long double) n)


#define all(c) (c).begin() , (c).end()


#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
pair<int, int> aarr[100100];
bool cmp(pair<int, int> a,pair<int, int> b){
    return ((a.first<b.first) || (a.first==b.first && a.second<=b.first));
}
signed main(signed argc, const char * argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a,b,c,d;
    int numb=1;
    cin>>a>>b>>c>>d;
    a+=b;
    a+=c;
    a+=d;
    int sum1=a;
    for (int i=1; i<n; ++i){
        cin>>a>>b>>c>>d;
        a+=b;
        a+=c;
        a+=d;
        if (sum1<a) ++numb;
    }
    cout<<numb<<en;
    return 0;
}