











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
#define all(c) (c).begin() , (c).end()
#define int long long
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
#define double long double
#define elif else if
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const double EPS=0.000000001;
const ll INF64=1000000000000000000;
const int INF32=2000000000;

bool iss_ll(ll &__1,ll &__2){ return INF64/__1>=__2;}
bool iss_sqr(ll &__1){ll __2=sqrt(__1); return __2*__2==__1;};
bool iss_prime(ll __1){for (int i=2; i*i<=__1; ++i) if (!(__1%i)) return 0; return 1;}
int gcd(int __1,int __2){ while (__1 && __2) if (__1>__2)  __1=__1%__2; else __2=__2%__1; return __1+__2;}
int lcm(int &__1,int &__2){ return __1*__2/(gcd(__1, __2));}




pii arr[1111];
int cnt[1111];
vector<int> numb;
bool iss[1111];
signed main()
{
    FAST();
    int n;
    cin>>n;
    for (int i=1; i<n; ++i) cin>>arr[i].first>>arr[i].second;
    for (int i=1; i<=n; ++i) if (arr[i].first>arr[i].second) swap(arr[i].first, arr[i].second);
    for (int i=1; i<n; ++i){
        if (arr[i].first!=n && arr[i].second!=n){
            cout<<"NO"<<en;
            return 0;
        }
    }
    bool flag=0;
    for (int i=1; i<n; ++i){
        if (arr[i].first==n-1){
            flag=1;
        }
    }
    if (!flag){
        cout<<"NO"<<en;
        return 0;
    }
    
    for (int i=1; i<n; ++i){
        cnt[arr[i].first]++;
    }
    for (int i=1; i<n; ++i){
        if (cnt[i]>i){
            cout<<"NO"<<en;
            return 0;
        }
    }
    
    vector <pii> ans;
    for (int i=1; i<=n; ++i){
        if (cnt[i]){
            int pos=i;
            int kk=cnt[i];
            for (int j=1; j<cnt[i]; ++j){
                for (int q=i-1; q>0; --q){
                    if (!iss[q] && !cnt[q]){
                        iss[q]=1;
                        ans.push_back({pos,q});
                        pos=q;
                        --kk;
                        break;
                    }
                }
            }
            ans.push_back({pos,n});
            --kk;
            if (kk>0){
                cout<<"NO"<<en;
                return 0;
            }
        }
    }
    cout<<"YES"<<en;
    for (auto i:ans)
        cout<<i.first<<" "<<i.second<<en;
}