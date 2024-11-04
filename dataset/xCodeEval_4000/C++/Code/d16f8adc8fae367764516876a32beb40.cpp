#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>


#define null nullptr

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





























































































































































































































































bool byXbyY(wor a, wor b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool byYbyX(wor a, wor b) {
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

wor center_of_cirle(wor a, wor b, wor c) {
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



















int main() {




    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll w=0,b=0;
    for(int i = 0; i < n ; i ++){
        cin>>arr[i];
        if(i&1 ){
            w +=(arr[i]+1)/2;
            b+=arr[i]/2;
        }else{
            w+=arr[i]/2;
            b+=(arr[i]+1)/2;
        }
    }
    cout<<min(w,b);

    return 0;
}
