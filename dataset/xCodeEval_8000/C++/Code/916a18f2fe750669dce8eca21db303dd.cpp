
#include<bits/stdc++.h>

using namespace std;




#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define lli long long int
#define vi vector<int>
#define vlli vector<long long int>
#define pii pair<int, int>
#define plli pair<lli, lli>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repa(i, a, b) for(int i = (a); i >= (b); i--)
#define repv(x, v) for(auto x : v)
#define debug(x) cout << #x << " = " << x << endl
#define debugsl(x) cout << #x << " = " << x << ", "
#define debugarr(x, a, b) cout << #x << " = ["; rep(i, a, b) cout << x[i] << ", "; cout << "]\n"
#define pb push_back
#define nl "\n"

long long int casos, n, a[100003], cnt, mul;

int main()
{
    fastio;
    cin >> casos;
    while(casos--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n-1; i++){
            mul = i / a[i];
            mul++;
            for(int j = (mul * a[i]) - i; j <= n; j += a[i]){
                if(j > i && a[i] *  a[j] == i + j) cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}

