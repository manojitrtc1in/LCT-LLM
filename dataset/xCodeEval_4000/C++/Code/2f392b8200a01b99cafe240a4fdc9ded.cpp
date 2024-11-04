

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}



int n, vars, deg[100005];
vector<int> clause_info[100005], var_info[100005], v;
set<int> adj[100005];
bool done[100005], used[100005];
ll DP_line_0[100005][2], DP_line_1[100005][2];
ll DP_cycle_0[100005][2][2], DP_cycle_1[100005][2][2];


void traverse(int u){
    v.pb(u);
    done[u] = true;
    for(auto it : adj[u])
        if(!done[it])
            traverse(it);
}

bool opposite(int v1, int v2){
    for(int i=0;i<(int)clause_info[v1].size();i++)
    for(int j=0;j<(int)clause_info[v2].size();j++)
        if(abs(clause_info[v1][i]) == abs(clause_info[v2][j]))
            return (clause_info[v1][i] != clause_info[v2][j]);


    assert(0);
    return 0;
}


ll dp_line_0(int, int);
ll dp_line_1(int, int);
ll dp_cycle_0(int, int, int);
ll dp_cycle_1(int, int, int);


bool isCycle(int u, int v){
    if(clause_info[u].size() < 2 || clause_info[v].size() < 2)  return false;
    if(abs(clause_info[u][0]) > abs(clause_info[u][1]))   swap(clause_info[u][0], clause_info[u][1]);
    if(abs(clause_info[v][0]) > abs(clause_info[v][1]))   swap(clause_info[v][0], clause_info[v][1]);
    return (abs(clause_info[u][0]) == abs(clause_info[v][0]) && abs(clause_info[u][1]) == abs(clause_info[v][1]));
}


int main(){

    


    scanf("%d%d", &n, &vars);
    for(int i=1;i<=n;i++){
        int sz;
        scanf("%d", &sz);
        while(sz--){
            int a;
            scanf("%d", &a);
            clause_info[i].pb(a);
            var_info[abs(a)].pb(i);
            used[abs(a)] = true;
        }
    }

    for(int v=1;v<=vars;v++)
        for(int i=0;i<(int)var_info[v].size()-1&&var_info[v][i]!=var_info[v][i+1];i++){
            adj[var_info[v][i]].insert(var_info[v][i+1]);
            adj[var_info[v][i+1]].insert(var_info[v][i]);
        }
    for(int i=1;i<=n;i++)
        deg[i] = (int)adj[i].size();

    ll zero = 1, one = 0;































    

    for(int i=1;i<=n;i++)
        if(deg[i] == 0){

            done[i] = true;

            if(clause_info[i].size() == 1){
                ll newzero = (1*zero + 1*one) % MOD;
                ll newone = (1*zero + 1*one) % MOD;
                zero = newzero; one = newone;
            }
            else if(abs(clause_info[i][0]) == abs(clause_info[i][1])){
                if(clause_info[i][0] == clause_info[i][1]){
                    ll newzero = (1*zero + 1*one) % MOD;
                    ll newone = (1*zero + 1*one) % MOD;
                    zero = newzero; one = newone;
                }
                else{
                    ll newzero = (2*one) % MOD;
                    ll newone = (2*zero) % MOD;
                    zero = newzero; one = newone;
                }
            }
            else{
                ll newzero = (1*zero + 3*one) % MOD;
                ll newone = (3*zero + 1*one) % MOD;
                zero = newzero; one = newone;
            }
        }




    

    for(int i=1;i<=n;i++)
        if(deg[i] == 1 && !done[i]){
            
            v.clear();
            traverse(i);

            if(v.size() == 2 && isCycle(v[0], v[1])){

                if(abs(clause_info[v[0]][0]) > abs(clause_info[v[0]][1]))   swap(clause_info[v[0]][0], clause_info[v[0]][1]);
                if(abs(clause_info[v[1]][0]) > abs(clause_info[v[1]][1]))   swap(clause_info[v[1]][0], clause_info[v[1]][1]);

                ll o = 0, z = 0;
                for(int i=0;i<2;i++)
                    for(int j=0;j<2;j++){

                        int c1 = 0, c2 = 0;
                        
                        if(clause_info[v[0]][0] < 0)    c1 |= (!i);
                        else    c1 |= i;
                        if(clause_info[v[0]][1] < 0)    c1 |= (!j);
                        else    c1 |= j;
                        
                        if(clause_info[v[1]][0] < 0)    c2 |= (!i);
                        else    c2 |= i;
                        if(clause_info[v[1]][1] < 0)    c2 |= (!j);
                        else    c2 |= j;

                        if((c1^c2) == 0)    z++;
                        else    o++;
                    }

                ll newzero = (z*zero + o*one) % MOD;
                ll newone = (o*zero + z*one) % MOD;
                zero = newzero; one = newone;
                continue;
            }




            
            for(int i=0;i<=(int)v.size();i++){
                DP_line_0[i][0] = DP_line_0[i][1] = -1;
                DP_line_1[i][0] = DP_line_1[i][1] = -1;
            }






            ll newzero = ((dp_line_0(0, 0) + dp_line_0(0, 1))*zero + (dp_line_1(0, 0) + dp_line_1(0, 1))*one) % MOD;
            ll newone = ((dp_line_1(0, 0) + dp_line_1(0, 1))*zero + (dp_line_0(0, 0) + dp_line_0(0, 1))*one) % MOD;
            zero = newzero; one = newone;



        }





    

    for(int i=1;i<=n;i++)
        if(deg[i] == 2 && !done[i]){
            
            v.clear();
            traverse(i);            
            
            for(int i=0;i<=(int)v.size();i++)
                for(int j=0;j<2;j++)
                    for(int k=0;k<2;k++){
                        DP_cycle_0[i][j][k] = DP_cycle_1[i][j][k] = -1;
                    }

            ll newzero = ((dp_cycle_0(0, 0, 0) + dp_cycle_0(0, 1, 1))*zero + (dp_cycle_1(0, 0, 0) + dp_cycle_1(0, 1, 1))*one) % MOD;
            ll newone = ((dp_cycle_1(0, 0, 0) + dp_cycle_1(0, 1, 1))*zero + (dp_cycle_0(0, 0, 0) + dp_cycle_0(0, 1, 1))*one) % MOD;
            zero = newzero; one = newone;
        }






    for(int i=1;i<=vars;i++)
        if(!used[i]){
            zero = (zero * 2) % MOD;
            one = (one * 2) % MOD;
        }

    printf("%lld\n", one);
    return 0;
}


ll dp_line_0(int idx, int curr){

    if(idx == (int)v.size()-1){


        if(curr == 0)   return 1;
        return 0;
    }
    if(DP_line_0[idx][curr] != -1)    return DP_line_0[idx][curr];

    if(curr == 0){

        if(clause_info[v[idx]].size() == 1){
            ll ans = dp_line_0(idx+1, curr^opposite(v[idx], v[idx+1]));


            return DP_line_0[idx][curr] = ans;
        }

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_0(idx+1, next)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_1(idx+1, next)) % MOD;



        return DP_line_0[idx][curr] = ans;
    }
    else{

        if(clause_info[v[idx]].size() == 1){
            ll ans = dp_line_1(idx+1, curr^opposite(v[idx], v[idx+1]));


            return DP_line_0[idx][curr] = ans;
        }

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_1(idx+1, next)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_1(idx+1, next)) % MOD;



        return DP_line_0[idx][curr] = ans;
    }

    assert(0);
    return 0;
}



ll dp_line_1(int idx, int curr){

    if(idx == (int)v.size()-1){

        int ans = 1;
        if(curr == 1)   ans = 2;

        if(clause_info[v[idx]].size() == 1){
            ans = (curr == 1);
        }



        return ans;
    }
    if(DP_line_1[idx][curr] != -1)    return DP_line_1[idx][curr];

    if(curr == 0){

        if(clause_info[v[idx]].size() == 1){
            ll ans = dp_line_1(idx+1, curr^opposite(v[idx], v[idx+1]));


            return DP_line_1[idx][curr] = ans;
        }

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_1(idx+1, next)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_0(idx+1, next)) % MOD;



        return DP_line_1[idx][curr] = ans;
    }
    else{

        if(clause_info[v[idx]].size() == 1){
            int ans = dp_line_0(idx+1, curr^opposite(v[idx], v[idx+1]));


            return DP_line_1[idx][curr] = ans;
        }

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_0(idx+1, next)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_line_0(idx+1, next)) % MOD;



        return DP_line_1[idx][curr] = ans;
    }

    assert(0);
    return 0;
}



ll dp_cycle_0(int idx, int curr, int first){

    if(idx == (int)v.size()-1){
        int other = first ^ opposite(v[0], v[idx]);


        return ((curr | other) == 0);
    }
    if(DP_cycle_0[idx][curr][first] != -1)    return DP_cycle_0[idx][curr][first];

    if(curr == 0){

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_0(idx+1, next, first)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_1(idx+1, next, first)) % MOD;



        return DP_cycle_0[idx][curr][first] = ans;
    }
    else{

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_1(idx+1, next, first)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_1(idx+1, next, first)) % MOD;
        


        return DP_cycle_0[idx][curr][first] = ans;
    }

    assert(0);
    return 0;
}



ll dp_cycle_1(int idx, int curr, int first){

    if(idx == (int)v.size()-1){
        int other = first ^ opposite(v[0], v[idx]);


        return ((curr | other) == 1);
    }
    if(DP_cycle_1[idx][curr][first] != -1)    return DP_cycle_1[idx][curr][first];

    if(curr == 0){

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_1(idx+1, next, first)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_0(idx+1, next, first)) % MOD;
        


        return DP_cycle_1[idx][curr][first] = ans;
    }
    else{

        ll ans = 0;
        int here = 0, next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_0(idx+1, next, first)) % MOD;

        here = 1; next = here ^ opposite(v[idx], v[idx+1]);
        ans = (ans + dp_cycle_0(idx+1, next, first)) % MOD;
        


        return DP_cycle_1[idx][curr][first] = ans;
    }

    assert(0);
    return 0;
}









