

using namespace std;





void madok() {
    long long n;
    cin >> n;
    vector<long long>v(n),vv(n);
    for(auto &x : v) cin >> x;
    for(auto &x : vv) cin >> x;
    bool flag = false ;
    for(long long i = 0 ; i < n; i++) {
        if(v[i] > vv[i]) {
            flag = true;
            

        }
        if(v[i] < vv[i] && 1+ vv[(i+1)%n] > vv[i]) {
            flag = true;
            

        }
    }
    if(flag) {
        cout << "YES" << sad;
    }
    else {
        cout << "NO" <<sad;
    }
}
void call() {
    int x,y,z,n;
    cin >> x >> y >> z >> n;
    if(n==1) {
        cout << "NO" <<sad;
        return ;
    }
    if((x+y+z+n)%3) {
        cout << "NO" <<sad;
    }
    else {
        cout << "YES" << sad;
    }
}
void current() {
    long long n,m;
    cin >> n>> m;
    long long cnt = 0;
    long long take = sqrtl(n);
    long long out = sqrtl(m);
    cnt = (out - take+1)*3;
    long long a,b,c,x,y,z;
    a = take *take;
    b = a +(take);
    c = b+take;
    x = out *out;
    y = out +x;
    z = out +y;
    if(a<n) {
        cnt--;
    }
    if(b<n ) {
        cnt--;
    }
    if(c < n) {
        cnt--;
    }
    if(x> m) {
        cnt--;
    }
    if(y > m) {
        cnt--;
    }
    if(z > m) {
        cnt--;
    }
    cin.ignore();
    cout << cnt << sad;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t = 1;
    cin >> t;

    while(t--) {
        current ();
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

    }

}