
















using namespace std;




























































typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int MOD = 100000007;
const int MAXN = 300010;































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































set<int> st;
set<int>::iterator it;
int ans[MAXN];

int main()
{


    int a, b, x, y, z;
    RII(a, b);
    FE(i, 1, a) st.insert(i);
    st.insert(a + 10);
    REP(i, b)
    {
        RIII(x, y, z);
        it = st.lower_bound(x);
        while ((*it) <= y)
        {
            ans[*it] = z;
            st.erase(it++);
        }

        st.insert(z);
        ans[z] = 0;
    }
    FE(i, 1, a)
    {
        if (i != 1) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}