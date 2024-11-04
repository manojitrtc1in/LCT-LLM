

#include <forward_list>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>



#define el '\n'
#define rep(i, n) for (int i = 0; i < n; i++)
#define lep(i,n) for (int i = n - 1; i > -1; i--)
#define all(v) v.begin(), v.end()
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
#define MOD 33554431 

#define read(a, n)                \
    for (int i = 0; i < n; i++)   \
        cin >> a[i];
#define f_each(it)                \
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

        vector <ll> v_ones_frost; 

        vector <ll> v_zeros_fire; 


        vector<ll> x(s);

        for (int i = 0; i < s; i++)
        {
            cin >> x[i];
        }
        for (int i = 0; i < s; i++)
        {
            int y; cin >> y;
            if (x[i]) v_ones_frost.push_back(y);
            else v_zeros_fire.push_back(y);
        }

        sort(v_ones_frost.begin(), v_ones_frost.end());
        sort(v_zeros_fire.begin(), v_zeros_fire.end());

        


        


        ll result = 0;

        if (v_zeros_fire.size() == 0) {
            for (auto iterator : v_ones_frost) result += iterator;
            cout << result << el;
        }
        else if (v_ones_frost.size() == 0) {
            for (auto iterator : v_zeros_fire) result += iterator;
            cout << result << el;
        }
        else
        {
            int fire_size = v_zeros_fire.size();
            int frost_size = v_ones_frost.size();

            if (v_zeros_fire.size() == v_ones_frost.size()) {
                if (v_zeros_fire[0] < v_ones_frost[0]) {
                    result += v_zeros_fire[0];
                    result += v_ones_frost[0] * 2;
                    fire_size--;
                    frost_size--;
                }
                else
                {
                    result += v_ones_frost[0];
                    result += v_zeros_fire[0] * 2;
                    frost_size--;
                    fire_size--;
                }
                for (int i = 1; i < frost_size + 1; i++)
                {
                    result += v_ones_frost[i] * 2;

                    result += v_zeros_fire[i] * 2;
                }
            }
            else if (v_zeros_fire.size() > v_ones_frost.size())
            {
                

                result += v_zeros_fire[0];

                

                fire_size--;

                reverse(v_zeros_fire.begin() + 1, v_zeros_fire.end());
                reverse(v_ones_frost.begin(), v_ones_frost.end());

                result += v_ones_frost[0] * 2;
                frost_size--;

                for (int i = 1; i <= v_ones_frost.size(); i++)
                {
                    if (frost_size > 0) {
                        result += v_ones_frost[i] * 2; frost_size--;
                    }
                    if (fire_size > 0) {
                        result += v_zeros_fire[i] * 2; fire_size--;
                    }
                }

                for (int i = v_ones_frost.size() + 1; i < v_zeros_fire.size(); i++)
                {
                    result += v_zeros_fire[i];
                }

            }
            else if (v_zeros_fire.size() < v_ones_frost.size())
            {
                result += v_ones_frost[0];
                


                frost_size--;
                


                reverse(v_zeros_fire.begin(), v_zeros_fire.end());
                reverse(v_ones_frost.begin() + 1, v_ones_frost.end());

                result += v_zeros_fire[0] * 2;
                fire_size--;

                for (int i = 1; i <= v_zeros_fire.size(); i++)
                {
                    if (frost_size > 0) {
                        result += v_ones_frost[i] * 2; frost_size--;
                    }
                    if (fire_size > 0) {
                        result += v_zeros_fire[i] * 2; fire_size--;
                    }
                }

                for (int i = v_zeros_fire.size() + 1; i < v_ones_frost.size(); i++)
                {
                    result += v_ones_frost[i];
                }

            }
            cout << result << el;
        }


        
    }

    return 0;

}