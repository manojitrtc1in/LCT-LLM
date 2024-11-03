






#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse2")

#define all(x) (x).begin(),(x).end()

void opting(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
}

int inp(){
    int x;
    cin >> x;
    return x;
}

void comping(vector<int> &vec){
    sort(all(vec));
    vec.resize(unique(all(vec)) - vec.begin());
}

const int maxn = 1048576, delta = 1e9 + 7;



int good[2 * maxn], bad[2 * maxn];

int mem[maxn];
void put_in(int val, int idx){

    mem[idx] = val;
    idx += maxn;
    if(val > 0)
        good[idx]++;
    else
        bad[idx]++;

    for(idx >>= 1; idx; idx >>= 1){
        good[idx] = good[idx << 1 | 1] + max(0, good[idx << 1] - bad[idx << 1 | 1]);
        bad[idx] = bad[idx << 1] + max(0, bad[idx << 1 | 1] - good[idx << 1]);
    }
}

int get_top(){
    if(!good[1])
        return -1;

    int buff = 0;
    int idx = 1;
    while(idx < maxn){
        if(good[idx << 1 | 1] > buff)
            idx = idx << 1 | 1;
        else
            buff += bad[idx << 1 | 1] - good[idx << 1 | 1], idx <<= 1;
        

    }
    return idx - maxn;
}

void debug(){
    cout <<endl << "debug: "<<endl;
    for(int i = 1; i < maxn * 2; i++)
        cout << i << ' ' << good[i] << ' ' << bad[i] << endl;
}

void solve(){
    int m = inp();
    while(m--){
        int idx = inp() - 1;
        if(inp())
            put_in(inp(), idx);
        else
            put_in(0, idx);
        

        int x = get_top();
        if(x == -1)
            cout << x;
        else
            cout << mem[x];
        cout << ' ';
        

    }
}

int main(){
    opting();

    solve();
}
