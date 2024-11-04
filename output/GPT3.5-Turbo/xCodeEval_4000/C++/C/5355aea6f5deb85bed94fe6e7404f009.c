#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define ull unsigned long long

typedef struct {
    ll first;
    ll second;
} pair;

typedef struct {
    ll first;
    pair second;
} triple;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll modpow(ll a, ll n, ll temp) {
    ll res = 1, y = a;
    while (n > 0) {
        if (n & 1) {
            res = (res * y) % temp;
        }
        y = (y * y) % temp;
        n /= 2;
    }
    return res % temp;
}

ll ison(ll mask, ll pos) {
    return (mask & (1 << pos));
}

typedef struct {
    ll size;
    ll* data;
} vector;

vector* create_vector(ll size) {
    vector* v = (vector*)malloc(sizeof(vector));
    v->size = size;
    v->data = (ll*)malloc(size * sizeof(ll));
    return v;
}

void push_back(vector* v, ll value) {
    v->data[v->size++] = value;
}

ll get(vector* v, ll index) {
    return v->data[index];
}

void set(vector* v, ll index, ll value) {
    v->data[index] = value;
}

void free_vector(vector* v) {
    free(v->data);
    free(v);
}

typedef struct {
    ll first;
    pair second;
} ver;

int main() {
    ll i, j, k, l, m, n;
    scanf("%lld", &n);
    ll tot = 0;
    for (i = 1; i <= n; i++) {
        ll k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        tot += k;
        vector* tmp = create_vector(k);
        push_back(tmp, a);
        for (j = 2; j <= k; j++) {
            push_back(tmp, (get(tmp, tmp->size - 1) * x + y) % m);
        }
        // data.push_back(tmp);
    }
    // set<pair<ll,pii> > q;
    // for(ll i=0;i<n;i++) q.insert(mpa(data[i][0],mpa(i,0)));
    // vector<ll> ans;
    // vector<pii> sol;
    // ll p=0;
    // while(ans.size()<tot){
    //     set<pair<ll,pii>>::iterator it=q.lower_bound(mpa(p,mpa(-1ll,-1ll)));
    //     if(it==q.end()) it=q.begin();
    //     ll v=(*it).ff;
    //     p=v;
    //     pii o=(*it).ss;
    //     ans.pb(v);
    //     sol.pb(mpa(v,o.ff+1ll));
    //     q.erase(*it);
    //     if(o.ss+1ll<data[o.ff].size()) q.insert(mpa(data[o.ff][o.ss+1ll],mpa(o.ff,o.ss+1ll)));
    // }
    // ll bad=0;
    // for(i=1;i<ans.size();i++) if(ans[i-1]>ans[i]) bad++;
    // cout<<bad<<endl;
    // if(tot<=200000) for(i=0;i<sol.size();i++)cout<<sol[i].ff<<" "<<sol[i].ss<<endl;
    return 0;
}
