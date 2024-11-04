

























    for (int i = 0; i < n; i++)   \
        cin >> a[i];

    for ( auto i : it )           \
        cout << i << " ";

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ul;
const ll mm = -4e18;
const ll oo = 4e18;
const int N = 2e6 + 20;
const int  mod = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-9;

void Steve()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

using namespace std;
int main()
{

    Steve();

    int t; cin >> t;
    while (t--)
    {
        int s; cin >> s;

        vector <ll> id0; 

        vector <ll> id1; 


        vector<ll> x(s);

        for (int i = 0; i < s; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < s; i++)
        {
            int y; cin >> y;
            if (x[i]) id0.push_back(y);
            else id1.push_back(y);
        }

        sort(id0.begin(), id0.end());
        sort(id1.begin(), id1.end());

        


        


        ll result = 0;

        if (id1.size() == 0) {
            for (auto iterator : id0) result += iterator;
            cout << result << el;
        }
        else if (id0.size() == 0) {
            for (auto iterator : id1) result += iterator;
            cout << result << el;
        }
        else
        {
            int fire_size = id1.size();
            int id2 = id0.size();

            if (id1.size() == id0.size()) {
                if (id1[0] < id0[0]) {
                    result += id1[0];
                    result += id0[0] * 2;
                    fire_size--;
                    id2--;
                }
                else
                {
                    result += id0[0];
                    result += id1[0] * 2;
                    id2--;
                    fire_size--;
                }
                for (int i = 1; i < id2 + 1; i++)
                {
                    result += id0[i] * 2;

                    result += id1[i] * 2;
                }
            }
            else if (id1.size() > id0.size())
            {
                

                result += id1[0];

                

                fire_size--;

                reverse(id1.begin() + 1, id1.end());
                reverse(id0.begin(), id0.end());

                result += id0[0] * 2;
                id2--;

                for (int i = 1; i <= id0.size(); i++)
                {
                    if (id2 > 0) {
                        result += id0[i] * 2; id2--;
                    }
                    if (fire_size > 0) {
                        result += id1[i] * 2; fire_size--;
                    }
                }

                for (int i = id0.size() + 1; i < id1.size(); i++)
                {
                    result += id1[i];
                }

            }
            else if (id1.size() < id0.size())
            {
                result += id0[0];
                


                id2--;
                


                reverse(id1.begin(), id1.end());
                reverse(id0.begin() + 1, id0.end());

                result += id1[0] * 2;
                fire_size--;

                for (int i = 1; i <= id1.size(); i++)
                {
                    if (id2 > 0) {
                        result += id0[i] * 2; id2--;
                    }
                    if (fire_size > 0) {
                        result += id1[i] * 2; fire_size--;
                    }
                }

                for (int i = id1.size() + 1; i < id0.size(); i++)
                {
                    result += id0[i];
                }

            }
            cout << result << el;
        }


        
    }

    return 0;

}