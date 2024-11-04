










using namespace std;

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> v(n);
    for(ll i=0;i<n;i++) {
        ll c,tp;
        cin>>c;
        for(ll j=0;j<c;j++) {
            cin>>tp;
            v[i].pb(tp);
        }
    }
    ll m;
    cin>>m;
    map<vector<ll>,ll> banned;
    for(ll i=0;i<m;i++) {
        vector<ll> cur;
        for(ll j=0;j<n;j++) {
            ll temp;
            cin>>temp;
            temp--;
            cur.pb(temp);
        }
        banned[cur]++;
    }
   
    vector<ll> idx(n);
    ll val = 0;
    for(ll i=0;i<n;i++) {
        idx[i]=v[i].size()-1;
        val+=v[i][idx[i]];
    }

    priority_queue<pair<ll,vector<ll>>> q;
    set<vector<ll>> done;
    q.push({val,idx});
    ll ct = 0;
    while(1) {
        ct++;
        vector<ll> cur = q.top().S;
        val = q.top().F;
        ll temp_val=val;
        

        q.pop();
        if(done.count(cur))
            continue;
        done.insert(cur);
        if(!banned[cur]) {
            for(ll i=0;i<n;i++) {
                cout<<cur[i]+1<<" ";
            }
            

            

            return;
        }
        
        for(ll i=0;i<n;i++) {
            if(cur[i]==0)
                continue;
            val-=v[i][cur[i]];
            

            cur[i]--;
            val+=v[i][cur[i]];
            q.push({val,cur});
            cur[i]++;
            val=temp_val;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;
    

    t=1;
    while(t--) {
       solve(); 
    }
}

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 

 


