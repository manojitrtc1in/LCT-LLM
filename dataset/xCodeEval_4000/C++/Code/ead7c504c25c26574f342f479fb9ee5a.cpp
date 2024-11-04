

#include "bits/stdc++.h"

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace std;
using namespace __gnu_pbds;

#ifdef karitkar7
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using u64 = uint64_t;
using u128 = __uint128_t;

typedef tree < long long, null_type, less < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree < long long, null_type, less_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
typedef tree < long long, null_type, greater < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_set;
typedef tree < long long, null_type, greater_equal < long long >, rb_tree_tag, tree_order_statistics_node_update > reversed_ordered_multiset;

#define endl '\n'
#define elif else if
#define size(container) (int)container.size()
#define case(index) cout << "Case #" << index << ": "
#define set_generate(index, largest_index) for(int index = 0; index < ((uint32_t)1 << largest_index); index++)

const long long MOD = (int)1E9+7;

const long double PI = acosl(-1.0);
const long long INF = (long long)1E18;

const int KING[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };
const int KNIGHT[8][2] = { {1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1} };
const int BISHOP[28][2] = { {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}, {-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}, {1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}, {-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7} };
const int ROCK[28][2] = { {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7} };
const int MIRO[10] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };









inline bool is_set(long long operand, int index) { return operand & ((uint64_t)1 << index); }
inline long long set_bit(long long operand, int index) { return operand |= ((uint64_t)1 << index); }
inline long long set_whole_bit(int largest_index) { return ((uint64_t)1 << largest_index) - 1; }
inline long long not_set_bit(long long operand, int index) { return operand &= ~((uint64_t)1 << index); }
inline long long inverse_bit(long long operand, int index) { return operand ^= ((uint64_t)1 << index); }
inline long long inverse_whole_bit(long long operand, int largest_index) { return operand ^= set_whole_bit(largest_index); }
inline int least_significant_set_bit(long long operand) { return operand & (-operand); }
inline bool is_power_of2(long long operand) { return operand && !(operand & (operand - 1)); }
inline bool compare(const pair < long long, long long > &pair_one, const pair < long long, long long > &pair_two)
{
    if (pair_one.first > pair_two.first)
        return true;
    if (pair_one.first == pair_two.first)
        return pair_one.second < pair_two.second;
    return false;
}

inline long long ceil_division(long long dividend, long long divisor) { return (dividend + divisor - 1) / divisor; }
inline long double log_b(long long base, long long power) { return log2(power) / log2(base); }
inline long long moduli(long long dividend, long long divisor) { return dividend % divisor >= 0 ? dividend % divisor : dividend % divisor + abs(divisor); }
inline long long modular_addition(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) + moduli(operand_two, modulo), modulo); }
inline long long moduli_decrement(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) - moduli(operand_two, modulo), modulo); }
inline long long modular_multiplication(long long operand_one, long long operand_two, long long modulo) { return moduli(moduli(operand_one, modulo) * moduli(operand_two, modulo), modulo); }

long long binary_power(long long base, long long power) { long long result = 1; while (power) { if (power & 1) result *= base; base *= base; power >>= 1; } return result; }
long long moduli_power(long long base, long long power, long long modulo) { base = moduli(base, modulo); long long result = 1; while (power) { if (power & 1) result = modular_multiplication(result, base, modulo); base = modular_multiplication(base, base, modulo); power >>= 1; } return result; }
long long inverse_moduli_power(long long base, long long modulo) { return moduli_power(base, modulo - 2, modulo); }
long long modular_division(long long operand_one, long long operand_two, long long modulo) { return modular_multiplication(operand_one, inverse_moduli_power(operand_two, modulo), modulo); }





bool isnt_root(u64 n, u64 a, u64 d, int s) {
    u64 x = moduli_power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};
bool is_root(u64 n)
{
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (isnt_root(n, a, d, r))
            return false;
    }
    return true;
}

vector< int > root;
void seive(int limit)
{       
    vector<char> is_seive_root(limit, true);
    is_seive_root[0] = is_seive_root[1] = false;
    int largest_index = (int)sqrt(limit);
    for (int index = 2; index <= largest_index; index++)
        if (is_seive_root[index])
            for (int signed_index = index * index; signed_index <= limit; signed_index += index)
                is_seive_root[signed_index] = false;
    for (int index = 2; index <= limit; index++)
        if (is_seive_root[index])
            root.emplace_back(index);
}
vector < long long > segment_root;
void segmented_seive(long long lowest_bound, long long largest_bound)
{
    vector < char > is_segment_root(largest_bound - lowest_bound + 1, true);
    if(!lowest_bound)
        is_segment_root[0] = is_segment_root[1] = false;
    elif(lowest_bound == 1)
        is_segment_root[0] = false;
    long long largest_index = (long long)sqrtl(largest_bound);
    for (long long index = 0; index < largest_index; index++)
        for (long long signed_index = max((long long)root[index] * (long long)root[index], (lowest_bound + (long long)root[index] - 1) / (long long)root[index] * (long long)root[index]); signed_index <= largest_bound; signed_index += (long long)root[index])
            is_segment_root[signed_index - lowest_bound] = false;
    for(int index = 0; index < size(is_segment_root); index++)
        if(is_segment_root[index])
            segment_root.emplace_back(lowest_bound + index);
}
vector < long long > root_set;
void seive_root(long long operand)
{
    if(operand <= 9999991 ? find(root.begin(), root.end(), operand) != root.end() : is_root(operand))
        root_set.push_back(operand);
    else
    {
        int index = 0;
        while (index < size(root) && operand > 1) 
        {
            while (!(operand % (long long)root[index])) 
            { 
                root_set.push_back((long long)root[index]); 
                operand /= (long long)root[index]; 
            }
            index++;
        }
        if (operand > 1) 
            root_set.push_back(operand);
    }
}
long long large_modular_multiplication(long long operand_one, long long operand_two, long long modulo) {
    long long result = 0;
    while (operand_two) 
    {
        if (operand_two & 1)
            result = modular_addition(result, operand_one, modulo);
        operand_one = modular_addition(operand_one, operand_one, modulo);
        operand_two >>= 1;
    }
    return result;
}
long long f(long long x, long long c, long long mod) {
    return (large_modular_multiplication(x, x, mod) + c) % mod;
}
long long brent_pollard_rho_root(long long n, long long x0=2, long long c=1) {
    long long x = x0;
    long long g = 1;
    long long q = 1;
    long long xs, y;

    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = large_modular_multiplication(q, abs(y - x), n);
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}













void solve()
{
    cout << fixed << setprecision(20);
    

    


    long long n,m,k;
    cin>>n>>m>>k;
    long long a[k+3];
	for (int i=1;i<=k;i++)
		cin>>a[i];
	bool flag=0;
	long long tot=0;
	for (int i=1;i<=k;i++)
	{
		if (a[i]/n>2)
			flag=1;
		if (a[i]/n>=2)
			tot+=a[i]/n;
	}
	if (tot>=m && (flag || m%2==0))
	{
		cout<<"Yes"<<endl;
		return ;
	}
	flag=0;
	tot=0;
	for (int i=1;i<=k;i++)
	{
		if (a[i]/m>2)
			flag=1;
		if (a[i]/m>=2)
			tot+=a[i]/m;
	}
	if (tot>=n && (flag || n%2==0))
	{
		cout<<"Yes"<<endl;
		return ;
	}
	cout<<"No";
    cout<<endl;
    return;
}
int main()
{
    float start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("error.txt", "w", stderr);
        freopen("output.txt", "w", stdout);
    #endif
    
    

    int t = 1;
    cin >> t;
    for(int index = 1; index <=t; index++){
        

        solve();
    }

    cerr << "Time taken: " << (clock() - start) / CLOCKS_PER_SEC<< " Seconds" << endl;

    return 0;
}

