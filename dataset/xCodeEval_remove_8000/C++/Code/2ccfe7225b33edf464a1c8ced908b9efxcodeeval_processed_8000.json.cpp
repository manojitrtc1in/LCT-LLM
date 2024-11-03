


 
using namespace std;
 
const double eps = 1e-4;
const int N = 200010;
 
int n, T;
char s[N];
int st[330];

int main()
{ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        memset(st, 0, sizeof st);
        cin >> s;
        int ans = 0, len = strlen(s);
 

        for (int i = 0; i < len; i++) {
            ++ans;
            int t = 0, j = i;
            for (; j < len; j++) {
 

                if (st[s[j]] != ans) {
                    ++t;
                    if (t > 3) break;
                    st[s[j]] = ans;
                }
 

            }
            if (t > 3) j--;
            i = j;
  

        }
        cout << ans << endl;
    }
    return 0;
}



