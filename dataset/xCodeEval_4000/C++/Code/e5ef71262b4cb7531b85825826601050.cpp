#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ctime>
#pragma GCC optimize("O3")
using namespace std;
using namespace __gnu_pbds;
#define MIN INT32_MIN
#define MAX INT32_MAX
#define LSOne(S) ((S) & (-(S)))
using ll = long long; using ld = long double;
using ii = pair<int, int>; using iii = tuple<int, int, int>;
using vb = vector<bool>; using vc = vector<char>; using vi = vector<int>; using vl = vector<long long>;
using vii = vector<ii>; using vll = vector<ll>;
using vvb = vector<vector<bool>>; using vvc = vector<vector<char>>; using vvi = vector<vector<int>>; using vvl= vector<vector<long long>>;
using Al = unordered_map<int, vi>; using AL = unordered_map<int, vi>;
using ordered_set = tree<int,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>;
using ordered_set_ii = tree<ii,null_type,less<>,rb_tree_tag,tree_order_statistics_node_update>;
using ordered_multiset =  tree<int,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update>; 












































































































































































class FenwickTree {                              

private:
    vll ft;                                        

public:
    FenwickTree(int m) { ft.assign(m+1, 0); }      


    void build(const vll &f) {
        int m = (int)f.size()-1;                     

        ft.assign(m+1, 0);
        for (int i = 1; i <= m; ++i) {               

            ft[i] += f[i];                             

            if (i+LSOne(i) <= m)                       

                ft[i+LSOne(i)] += ft[i];                 

        }
    }

    FenwickTree(const vll &f) { build(f); }        


    FenwickTree(int m, const vi &s) {              

        vll f(m+1, 0);
        for (int i = 0; i < (int)s.size(); ++i)      

            ++f[s[i]];                                 

        build(f);                                    

    }

    ll rsq(int j) {                                

        ll sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } 


    

    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    int select(ll k) {                             

        int p = 1;
        while (p*2 < (int)ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i+p]) {
                k -= ft[i+p];
                i += p;
            }
            p /= 2;
        }
        return i+1;
    }
};

class RUPQ {                                     

private:
    FenwickTree ft;                                

public:
    RUPQ(int m) : ft(FenwickTree(m)) {}
    void range_update(int ui, int uj, ll v) {
        ft.update(ui, v);                            

        ft.update(uj+1, -v);                         

    }                                              

    ll point_query(int i) { return ft.rsq(i); }    

};

class RURQ  {                                    

private:                                         

    RUPQ rupq;                                     

    FenwickTree purq;                              

public:
    RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} 

    void range_update(int ui, int uj, ll v) {
        rupq.range_update(ui, uj, v);                

        purq.update(ui, v*(ui-1));                   

        purq.update(uj+1, -v*uj);                    

    }
    ll rsq(int j) {
        return rupq.point_query(j)*j -               

               purq.rsq(j);                          

    }
    ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } 

};





























































































































































































































































































































































































































































































































































































































































































int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, c;
        cin >> n >> c;
        unordered_set<int> s;
        for (int i=0;i<n;i++) {
            int temp;
            cin >> temp;
            s.insert(temp);
        }

        bool integral = true;
        vi arr(s.size());
        int q = 0;
        for (auto &a : s) {
            arr[q] = a;
            ++q;
        }

        sort(arr.begin(), arr.end());
        n = arr.size();






        for (int i=0;i<n;i++) {
            for (int j=i;j<n;j++) {
                int val = arr[j] / arr[i];
                if (s.count(val) == 0) {
                    integral = false;
                    break;
                } else {
                    int pt = lower_bound(j+arr.begin(), arr.end(), (val + 1) * arr[i]) - arr.begin();
                    --pt;
                    j = max(j, pt);
                }
            }
            if (!integral) break;
        }

        if (integral) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
