













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
vector<int> z_function_trivial (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1; i<n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
    return z;
}
signed main(){
    string s1,s2,t;
    cin>>s1>>s2;
    t=s2+"*"+s1;
    int cnt=0;
    vector<int> VEC=z_function_trivial(t);
   

    for (int i=0; i<VEC.size(); ++i){
        if (VEC[i]==s2.size()){
            cnt++;
            i+=s2.size()-1;
        }
    }
    cout<<cnt<<en;
    return 0;
}
