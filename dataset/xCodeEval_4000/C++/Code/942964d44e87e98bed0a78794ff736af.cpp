













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
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    string res;
    for (int i=0; i<n-p; ++i){
        if (s[i]!=s[i+p]){
            if (s[i]=='.') {
                if (s[i+p]=='1') s[i]='0'; else s[i]='1';
                for (char ch:s)
                    if (ch=='.') cout<<1;
                    else cout<<ch;
                return 0;
            }
            if (s[i+p]=='.'){
                if (s[i]=='1') s[i+p]='0'; else s[i+p]='1';
                for (char ch:s)
                    if (ch=='.') cout<<1;
                    else cout<<ch;
                return 0;
            }
            for (char ch:s)
                if (ch=='.') cout<<1;
                else cout<<ch;
            return 0;
        }
        
        if (s[i]==s[i+p] && s[i]=='.'){
            s[i]='1'; s[i+p]='0';
            for (char ch:s)
                if (ch=='.') cout<<1;
                else cout<<ch;
            return 0;
        }
    }
    cout<<"NO"<<en;
    return 0;
}
