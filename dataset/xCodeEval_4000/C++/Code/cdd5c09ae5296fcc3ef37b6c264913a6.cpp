

#pragma comment(linker,"/STACK:100000000,100000000")
#include <iostream>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#define min(a,b) (a<b?a:b)
#define max(a,b) -min(-(a),-(b))
#define show1(a) cerr<<#a<<":"<<a<<endl
#define show2(a,b) cerr<<#a<<":"<<a<<" | "<<#b<<":"<<b<<endl
#define show3(a,b,c) cerr<<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<endl
#define show4(a,b,c,d) cerr<<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<endl
#define show5(a,b,c,d,e) cerr<<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<" | "<<#e<<":"<<e<<endl
#define show6(a,b,c,d,e,f) cerr<<#a<<":"<<a<<" | "<<#b<<":"<<b<<" | "<<#c<<":"<<c<<" | "<<#d<<":"<<d<<" | "<<#e<<":"<<e<<" | "<<#f<<":"<<f<<endl
#define XD cerr << "{ " << ++xD << " }\n"
long long xD;


#define rep(i, n) for(ll i = 0; i < n; i++)
#define F first
#define S second

typedef long long ll;
using namespace std;



const ll N = 100 * 1000 + 9;
const ll INF = 1e15;
ll n, m, husband, lady;
ll boy[N], girl[N], bro[N], sis[N];
set <pair<ll, pair<ll, ll> > > family;
set <pair<ll, ll> > marry;
set <ll> remboy, remgirl;
vector <ll> ans;



void prop() {
    return;
    for (auto it : remboy)
        cout << it << ' ';
    cout << endl;
    
    for (auto it : remgirl)
        cout << it << ' ';
    cout << endl;
    
    for (auto it : remboy)
        cout << sis[it] << ' ';
    cout << endl;
    
    for (auto it : remgirl)
        cout << bro[it] << ' ';
    cout << endl;
    
    for (auto it : family)
        show3(it.F, it.S.F, it.S.S);
    show1("===================");
}


int main()
{_
    cin >> n >> m;
    rep(i, n) cin >> boy[i];
    rep(i, n) cin >> girl[i];
    
    sort(boy, boy + n);
    sort(girl, girl + n);
    
    rep(i, n) marry.insert({girl[i], i});
    rep(i, n) remboy.insert(i);
    rep(i, n) remgirl.insert(i);
    
    fill(sis, sis + N, N - 3);
    fill(bro, bro + N, N - 3);
    
    ll Woman_Of_The_Year = -INF;
    for (ll i = n - 1; i >= 0; i--) {
        if (boy[i] + (*marry.begin()).F >= m)
            continue;
        
        pair <ll, ll> wife = *--marry.upper_bound({m - boy[i] - 1, INF});
        marry.erase(wife);
        
        if (wife.F < Woman_Of_The_Year)
            continue;
        Woman_Of_The_Year = wife.F;
        sis[i] = wife.S;
        bro[wife.S] = i;
        
        family.insert(
            make_pair(
                boy[i] + wife.F,
                make_pair(
                    i,
                    wife.S
                )
            )
        );
    }
    
    rep(i, n) {
        
        prop();

        pair<ll, pair <ll, ll> > tp;
        if (family.size()) tp = *--family.end();
        ll B = *--remboy.end();
        ll G = *--remgirl.end();
                
        if (family.size() && tp.F >= (boy[B] + girl[G]) - m) {
            family.erase(--family.end());
            ans.push_back(tp.F);
            
            if (tp.S.F != *remboy.begin()
                && tp.S.S != *remgirl.begin()) {
                
                ll Majnoon = *--remboy.find(tp.S.F);
                ll Leili = *--remgirl.find(tp.S.S);
                
                if (sis[Majnoon] == N - 3 && bro[Leili] == N - 3) {
                    family.insert(
                        make_pair(
                            boy[Majnoon] + girl[Leili],
                                  make_pair(Majnoon, Leili
                                            )
                        )
                    );
                    
                    sis[Majnoon] = Leili;
                    bro[Leili] = Majnoon;
                }
            }
            
            remboy.erase(tp.S.F);
            remgirl.erase(tp.S.S);
            
        } else {
            ans.push_back((girl[*--remgirl.end()] + boy[*--remboy.end()]) - m);
            
            husband = *--remboy.end();
            
            if (girl[sis[B]] > sis[husband]) {
                family.erase(
                    make_pair(
                        girl[sis[husband]] + boy[husband],
                        make_pair(
                            husband,
                            sis[husband]
                        )
                    )
                );
                
                bro[sis[husband]] = N - 3;
                sis[husband] = sis[B];
                bro[sis[B]] = husband;
                
                family.insert(
                    make_pair(
                        boy[husband] + girl[sis[B]],
                        make_pair(
                            husband,
                            sis[B]
                        )
                    )
                );
            }
            

            

            
            husband = *--remgirl.end();
            
            if (boy[bro[G]] > bro[husband]) {
                family.erase(
                    make_pair(
                        boy[bro[husband]] + girl[husband],
                              make_pair(
                                    bro[husband],
                                    husband
                                )
                    )
                );
                
                sis[bro[husband]] = N - 3;
                bro[husband] = bro[G];
                sis[bro[G]] = husband;
                
                family.insert(
                    make_pair(
                        girl[husband] + boy[bro[G]],
                        make_pair(
                            boy[G],
                            husband
                        )
                    )
                );
            }
            
            remboy.erase(--remboy.end());
            remgirl.erase(--remgirl.end());
            
            family.erase(make_pair(boy[B] + girl[sis[B]], make_pair(B, sis[B])));
            family.erase(make_pair(girl[G] + boy[bro[G]], make_pair(bro[G], G)));
        }
    }
    
    for (auto it : ans)
        cout << it << ' ';
}
 








