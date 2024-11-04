


 

  

 

 

 

 

 


 

 

 

  

   



using namespace std;





















typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair < long long , long long > pll;
typedef vector < ll > vll;
typedef vector < vll > vvll;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef vector < pii > vpii;
typedef pair < pii , pii > ppiipii;
typedef long double ld;
typedef map < int , int > mii;
typedef map < ll , ll > mll;
typedef set < int > si;
typedef set < ull > sull;
typedef set < string > ss;
typedef set < pii > spii;
typedef multiset < int > msi;
typedef map < pii , int > mpiii;
typedef map < int , pii > mipii;
typedef vector < pair < int , pair < int , int > > > vpipii;

const int maxn = int(1.5 * 1e7);
const int inf = ~0U;
const ll ll_inf = 1e18 + 420;
const double eps = 1e-4;
const int N = 1e6 + 7;
const int MAX = 2e5 + 9;
const int MOD = 1e9 + 7;
const ld pi = 3.14159265359;

int a1, a2, a3, a4, b1, b2;
string ans;

int main() {
    IOS;
    

    

    cin >> a1 >> a2 >> a3 >> a4;
    if(abs(a3 - a4) > 1){
        cout << -1;
        return 0;
    }
    if(a4 > a3){
        for(int i = 1;i <= a4;i ++){
            ans += "74";
            b1 ++;
            b2 ++;
        }
        if(b1 <= a1 && b2 <= a2){
            b1 = a1 - b1;
            b2 = a2 - b2;
            cout << ans[0];
            for(int i = 1;i <= b1;i ++){
                cout << 4;
            }
            for(int i = 1;i < ans.size() - 1;i ++){
                cout << ans[i];
            }
            for(int i = 1;i <= b2;i ++){
                cout << 7;
            }
            cout << ans[ans.size() - 1];
            return 0;
        }
        else{
            cout << -1;
            return 0;
        }
    }
    else if(a3 > a4){
        

        for(int i = 1;i <= a3;i ++){
            

            ans += "47";
            b1 ++;
            b2 ++;
        }
        if(b1 <= a1 && b2 <= a2){
            b1 = a1 - b1;
            b2 = a2 - b2;
            for(int i = 1;i <= b1;i ++){
                cout << 4;
            }
            for(int i = 0;i < ans.size();i ++){
                cout << ans[i];
            }
            for(int i = 1;i <= b2;i ++){
                cout << 7;
            }
            return 0;
        }
        else{
            cout << -1;
            return 0;
        }
    }
    else{
        ans += '4';
        b1 ++;
        for(int i = 1;i <= a4;i ++){
            

            ans += "74";
            b1 ++;
            b2 ++;
        }
        if(b1 <= a1 && b2 <= a2){
            b1 = a1 - b1;
            b2 = a2 - b2;
            for(int i = 1;i <= b1;i ++){
                cout << 4;
            }
            for(int i = 0;i < ans.size() - 1;i ++){
                cout << ans[i];
            }
            for(int i = 1;i <= b2;i ++){
                cout << 7;
            }
            cout << ans[ans.size() - 1];
            return 0;
        }
        ans = "";
        b1 = 0;
        b2 = 1;
        ans += "7";
        for(int i = 1;i <= a4;i ++){
            

            ans += "47";
            b1 ++;
            b2 ++;
        }
        if(b1 <= a1 && b2 <= a2){
            b1 = a1 - b1;
            b2 = a2 - b2;
            cout << ans[0];
            for(int i = 1;i <= b1;i ++){
                cout << 4;
            }
            for(int i = 1;i < ans.size();i ++){
                cout << ans[i];
            }
            for(int i = 1;i <= b2;i ++){
                cout << 7;
            }
            return 0;
        }
    }
    cout << -1;
}
