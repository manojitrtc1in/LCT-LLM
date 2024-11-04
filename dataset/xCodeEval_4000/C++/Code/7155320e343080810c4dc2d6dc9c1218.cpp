#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define ss second
#define ff first
#define EPS (ld)(0.00000000000000000001)
#define needForSpeed cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0)
#define y1 fuckyoufuckyou
#define yes cout << "YES\n"
#define no cout << "NO\n"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
class LOG{
public:
    template<typename C>
    struct is_iterable{
      typedef long false_type;
      typedef char true_type;

      template<class T> static false_type check(...);
      template<class T> static true_type  check(int,
                        typename T::const_iterator = C().end());

      enum { value = sizeof(check<C>(0)) == sizeof(true_type) };
    };
    static void print_value(string starting, ostream& os, string value, string ending = "\n"){
        os << starting<< "\"" << value<< "\"" << ending;
    }
    template<class T>
    static void print_value(string starting, ostream& os, T value, string ending = "\n"){
        if constexpr (is_iterable<T>::value){
            typename T :: iterator it = value.begin();
            os << starting << "{";
            while (it != value.end()){
               print_value ("", os, *it, (next(it, 1) == value.end() ? "" : ", "));
                it++;
            }
            os << "}";
        }
        else{
            os << starting << value;
        }
        os << ending;
    }
    template<class T, class M>
    static void print_value(string starting, ostream& os, pair<T, M> value, string ending = "\n"){
        os << starting << "{";
        print_value("", os, value.ff, "");
        os << ", ";
        print_value("", os, value.ss, "");
        os << "}" << ending;
    }
    template<class T, class M>
    static void print_value(string starting,ostream& os, map<T, M> value, string ending = "\n"){
        os << starting << "{" << endl;
        ll cur = 0;
        for (pair<T, M> v: value){
            print_value ("  {", os, v.ff, ": ");
            print_value ("", os, v.ss, (cur == value.size() - 1 ? "}" : "},"));
            cur++;
            os << endl;
        }
        os << "}" << ending;
    }
    template<class T>
    static void print_arr(string starting, ostream& os, const T& x, string ending = "\n") {
        static_assert(is_array_v<T>);
        os << starting;
        for(auto& in : x) {
            if constexpr (rank_v<T> > 1)
                print_arr("", os, in, "");
            else
                os << in << ", ";

        }
        os << ending;
        os << '\n';
    }
};
#define MOD 1000000007
int dp[40005][1500];
vector<int> res;
void solve(){
    int n;
    cin >> n;
    cout << dp[n][res.size()] << endl;
}

void getPalLen (ll len, ll left, string cur = ""){
    if (left > 0){
        for (long long i = 0; i < 10; i++){
            cur += i + '0';
            getPalLen(len, left - 1, cur);
            cur.pop_back();
        }
    } else{
        if (cur[0] == '0'){
            return;
        }
        ll ind = len / 2 - 1;
        while(cur.size() < len){
            cur += cur[ind];
            ind--;
        }
        res.push_back(stoll(cur));
    }
}

int main(){




    for (long long i = 1; i < 6; i++){
        getPalLen(i, (i + 1) / 2);
    }
    sort(res.begin(), res.end());


    for (long long i = 0; i <= res.size() + 10; i++){
        dp[0][i] = 1;
    }








    for (long long i = 1; i <= 40000; i++){




        for (long long j = 0; j <= res.size(); j++){
            if (res[j] <= i)
                dp[i][j] += dp[i - res[j]][j];
            dp[i][j] %= MOD;
            if (j > 0){
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= MOD;








        }
    }

    long long DoYoUlIkEwHaTdOyOuSeE = 1;
    cin >> DoYoUlIkEwHaTdOyOuSeE;
    while(DoYoUlIkEwHaTdOyOuSeE--){
        solve();
    }
    return 0;
}

