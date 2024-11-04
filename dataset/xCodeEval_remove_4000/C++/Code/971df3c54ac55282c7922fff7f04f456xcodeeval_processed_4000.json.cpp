


















using namespace std;
typedef long long ll;
typedef double long dl;
typedef unsigned long long ull;
const dl EPS = 1e-10;


struct wor {
    dl x = 0, y = 0;
};

dl dist(wor a, wor b) {
    dl answer = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return answer;
}















































ll vec(wor a, wor b) {
    return a.x * b.y - a.y * b.x;
}

ll scal(wor &a, wor &b) {
    return a.x * b.x + a.y * b.y;
}















wor operator-(wor a, wor b) {
    wor res;
    res.x = a.x - b.x;
    res.y = a.y - b.y;
    return res;
}

wor operator+(wor a, wor b) {
    wor res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    return res;
}

wor operator/(wor a, dl b) {
    wor res;
    res.x = a.x / b;
    res.y = a.y / b;
    return res;
}

void operator/=(wor &a, dl b) {
    a.x /= b;
    a.y /= b;
}

ostream &operator<<(ostream &out, const wor &a) {
    out << (ll) a.x << " " << (ll) a.y;
    return out;
}





























































































































































































































































bool id0(wor a, wor b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool id1(wor a, wor b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

wor beg;

bool by_angle(wor &a, wor &b) {
    wor a1 = a - beg;
    wor b1 = b - beg;
    return vec(a1, b1) >= 0;
}


















































































































































































































































































































































































































































































































































































































































vector<dl> line(wor a, wor lineA) {
    vector<dl> answer(3);
    answer[0] = lineA.y;
    answer[1] = -lineA.x;
    answer[2] = lineA.y * a.x - lineA.x * a.y;

    return answer;
}

wor intersect(wor a, wor lineA, wor b, wor lineB) {
    auto line1 = line(a, lineA);
    auto line2 = line(b, lineB);
    if (line1[0] == 0) {
        line1.swap(line2);
    }
    dl a1, b1, c1, a2, b2, c2;
    a1 = line1[0];
    b1 = line1[1];
    c1 = line1[2];
    a2 = line2[0];
    b2 = line2[1];
    c2 = line2[2];
    wor answer;
    answer.y = (c2 - a2 * c1 / a1) / (b2 - a2 * b1 / a1);
    answer.x = (c1 - b1 * answer.y) / a1;
    return answer;
}

wor id2(wor a, wor b, wor c) {
    wor mid1 = (a + b) / 2;
    wor mid2 = (b + c) / 2;
    wor temp = (b - a);
    wor line1;
    line1.x = -temp.y;
    line1.y = temp.x;
    temp = (c - b);
    wor line2;
    line2.x = -temp.y;
    line2.y = temp.x;
    return intersect(mid1, line1, mid2, line2);
}

struct item {
    ll val = 0;
    char m;
    char f;
};

bool comp(item a, item b) {
    return a.val < b.val;
}

bool fuck = false;

void res(vector<ll> &answer, ll pos, ll prev, ll n, vector<ll> &arr) {
    if (pos == n) {
        return;
    }
    if (prev == 0) {
        if (arr[1] == 0) {
            fuck = true;
            return;
        } else {
            answer[pos] = 1;
            arr[1]--;
            res(answer, pos + 1, 1, n, arr);
        }
    } else if (prev == 1) {
        if (arr[0] == 0 && arr[2] == 0) {
            fuck = true;
            return;
        }
        if (arr[0] > arr[2]) {
            answer[pos] = 0;
            arr[0]--;
            res(answer, pos + 1, 0, n, arr);
        } else {
            answer[pos] = 2;
            arr[2]--;
            res(answer, pos + 1, 2, n, arr);
        }
    } else if (prev == 2) {
        if (arr[1] == 0 && arr[3] == 0) {
            fuck = true;
            return;
        }
        if (arr[1] > arr[3]) {
            answer[pos] = 1;
            arr[1]--;
            res(answer, pos + 1, 1, n, arr);
        } else {
            answer[pos] = 3;
            arr[3]--;
            res(answer, pos + 1, 3, n, arr);
        }
    } else {
        if (arr[2] == 0) {
            fuck = true;
            return;
        } else {
            answer[pos] = 2;
            arr[2]--;
            res(answer, pos + 1, 2, n, arr);
        }
    }
}

vector<ll> answer;

void dfs(vector<ll> &arr, ll uk, bool pred) {
    arr[uk]--;
    answer.push_back(uk);
    if (!pred) {
        if (uk == 0) {
            if (arr[1]) {
                dfs(arr, 1, false);
            }
        } else if (uk == 1) {
            if (arr[0]) {
                dfs(arr, 0, false);
            } else if (arr[2]) {
                dfs(arr, 2, false);
            }
        } else if (uk == 2) {
            if (arr[1]) {
                dfs(arr, 1, false);
            } else if (arr[3]) {
                dfs(arr, 3, false);
            }
        } else {
            if (arr[2]) {
                dfs(arr, 2, false);
            }
        }
    } else {
        if (uk == 0) {
            if (arr[1]) {
                dfs(arr, 1, false);
            }
        } else if (uk == 3) {
            if (arr[2]) {
                dfs(arr, 2, false);
            }
        } else {
            if (arr[uk - 1] && arr[uk + 1]) {
                dfs(arr, uk - 1, false);
                if (arr[uk + 1] || arr[uk - 1]) {
                    auto cop = answer;
                    answer.clear();
                    if (arr[uk + 1]) {
                        dfs(arr, uk + 1, false);
                    } else {
                        dfs(arr, uk - 1, false);
                    }
                    reverse(answer.begin(), answer.end());
                    for (auto e : cop) {
                        answer.push_back(e);
                    }
                }
            } else if (arr[uk - 1]) {
                dfs(arr, uk - 1, false);;
            } else if (arr[uk + 1]) {
                dfs(arr, uk + 1, false);
            }
        }
    }
}

bool check(vector<ll> &a, vector<ll> arr) {
    arr[a[0]]--;
    for (int i = 1; i < a.size(); i++) {
        if (abs(a[i] - a[i - 1]) != 1) {
            return false;
        }
        arr[a[i]]--;
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i])return false;
    }
    return true;
}

struct bint {
    const ll maxN = 1000;
    ll base = 1000;
    ll len = 3;
    vector<ll> arr;

    bint() {
        arr.resize(maxN);
    }

    void smooth() {
        for (int i = 0; i < maxN - 1; i++) {
            arr[i + 1] += arr[i] / base;
            arr[i] %= base;
        }
    }

    bint &operator=(ll a) {
        arr[0] = a;
        smooth();
        return *this;
    }

    bint &operator*=(ll a) {
        for (int i = 0; i < maxN; i++) {
            arr[i] *= a;
        }
        smooth();
        return *this;
    }

};

ostream &operator<<(ostream &os, bint &b) {
    ll ma = b.maxN - 1;
    while (ma > 0 && b.arr[ma] == 0) {
        ma--;
    }
    for (int j = ma; j >= 0; j--) {
        string temp = to_string(b.arr[j]);
        if (j < ma)
            while (temp.length() < b.len) {
                temp = '0' + temp;
            }
        os << temp;
    }
    return os;
}

bool is_prime(ll a) {
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0)return false;
    }
    return true;
}



















const ll maxN = 2e5+100;
ll fenwick [maxN];
void add(ll pos){
    for(ll i = pos ; i >0 ; i-=(i&-i)){
        fenwick[i] ++;
    }
}
ll sum(ll pos){
    ll answer =0;
    for(ll i = pos; i<maxN; i+=(i&-i)){
        answer+=fenwick[i];
    }
    return answer;
}
ll fenwick1 [maxN];
ll sum1(ll pos){
    ll answer =0 ;
    for(ll i = pos ; i>0 ; i-=(i&-i)){
        answer+=fenwick1[i];
    }
    return answer;
}
void add1(ll pos ,ll val){
    for(ll i = pos ;i < maxN; i+=(i&-i)){
        fenwick1[i]+=val;
    }
}
ll fenwick2 [maxN];
ll sum2(ll pos){
    ll answer =0 ;
    for(ll i = pos ; i>0 ; i-=(i&-i)){
        answer+=fenwick2[i];
    }
    return answer;
}
void add2(ll pos ,ll val){
    for(ll i = pos ;i < maxN; i+=(i&-i)){
        fenwick2[i]+=val;
    }
}












































































ll find_mid(ll all){
    ll l =1;
    ll r = maxN-1;

    while(r>l){
        ll m = (l+r)/2;
        if(sum1(m)>all/2){
            r=m;
        }else{
            l = m+1;
        }
    }
    return l;
}
int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> pos(n+1);
    vector<ll> answer(n);
    for(int i= 0 ; i < n ; i ++){
        cin>>arr[i];
        pos[arr[i]] = i+1;
    }
    for(int i = 0; i< n ; i ++){
        answer [i] = sum(pos[i+1])+(i>0?answer[i-1]:0);
        add(pos[i+1]);
    }
    for(int i = 1 ; i<= n ; i++){
        add1(pos[i],1);
        add2(pos[i],pos[i]);
        ll all =sum1(maxN-1);

        ll mid = find_mid(all);
        auto left_am = sum1(mid-1);
        auto right_am = sum1(maxN-1) - sum1(mid);

        ll left = sum2(mid-1);
        ll right = sum2(maxN-1) - sum2(mid);
        left = left_am * mid - left - left_am*(left_am+1)/2;
        right = right - right_am * mid - right_am*(right_am+1)/2;
        answer[i-1] += left+right;
    }
    for(auto e: answer){
        cout<<e<<" ";
    }



    return 0;
}
