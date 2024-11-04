    
    
    
    
    
#include <vector>
#include <cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);\
\
cout.tie(0);
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define testcase int t; cin >> t; while (t--)
typedef long double ld;
typedef long long ll;
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,f\
\
ast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,a\
\
vx")
#pragma GCC optimize("Ofast")

\
ractive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")


using namespace std;

int main1(){
  fastio;
  testcase{
    int n;
    int  a[110];
  scanf("%d",&n);
  for(int i=0; i<n; i++) {scanf("%d",&a[i]);}
  for(int j=n-1; j>=0; j--){ printf("%d ",a[j]);}
  printf("\n");
  }
  return 0;
}
int main() {
  fastio;
  testcase{
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &x : a) cin >> x;
        reverse(a.begin(), a.end());
        for(int x : a) cout << x << ' ';
        cout << '\n';
    }
}
