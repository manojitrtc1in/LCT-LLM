




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
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <bitset>






#define en "\n"
#define sqrt(n) sqrt((long double) n)
#define all(c) (c).begin() , (c).end()
#define MOD 1000000007
#define mem0(a) memset(a,0,sizeof(a))
#define FAST() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define elif else if
#define int long long
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> seti;
typedef pair<double, double> pdd;
typedef long double ld;



const double EPS=0.000000001;
const double INFD32=1000000000;
const ll INF64=1000000000000000000;
const int INF32=1000000000;

#define maxN 100300

vector<string> VEC;

string to_str(int x){
    string ans;
    while (x) {
        ans.push_back('0'+(x%10));
        x/=10;
    }
    REVERSE(ans);
    return ans;
}



signed main(void){
    

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    string prev="+";
    int k_plus=0,k_minus=0;
    VEC.push_back(prev);
    while (cin>>s){
        VEC.push_back(s);
        if (s=="=") break;
        if (s=="?"){
            if (prev=="+") ++k_plus;
            else ++k_minus;
        }
        prev=s;
    }
    int x;
    cin>>x;
    VEC.push_back(to_str(x));
    if (k_plus*x-k_minus<x){
        cout<<"Impossible"<<en;
        return 0;
    }
    
    vector<int> v1(k_plus,x),v2(k_minus,1);
    
    int sum=k_plus*x-k_minus;
    
    int pos1=0,pos2=0;
    int kkk=0;
    bool fg=0;
    while (sum>x) {
        fg=0;
        for (; pos1<v1.size(); ++pos1){
            if (v1[pos1]>1){
                --v1[pos1];
                --sum;
                fg=1;
                break;
            }
        }
        if (fg) continue;
        for (; pos2<v2.size(); ++pos2){
            if (v2[pos2]<x){
                ++v2[pos2];
                --sum;
                fg=1;
                break;
            }
        }
        if (!fg) break;
    }
    if (sum!=x){
        cout<<"Impossible"<<en;
        return 0;
    }
    cout<<"Possible"<<en;
    int k1=0,k2=0;
    for (int i=1; i<VEC.size(); ++i){
        if (VEC[i]=="?"){
            if (VEC[i-1]=="+"){
                cout<<v1[k1]<<" ";
                ++k1;
            }else{
                cout<<v2[k2]<<" ";
                ++k2;
            }
        }else
            cout<<VEC[i]<<" ";
    }
}




