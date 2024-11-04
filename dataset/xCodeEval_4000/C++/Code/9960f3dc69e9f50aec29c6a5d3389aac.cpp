
#include <bits/stdc++.h>
#define SUPERPOWER  	        ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
#define file        			freopen("mex.in","r",stdin);freopen("output.txt","w",stdout);
#define asd         			"\12"
#define forn(i,n)   			for(int i = 0; i < n; i++)
#define all(v)      			v.begin(), v.end()


#define gcd(a, b)   			__gcd(a, b)
#define lcm(a, b)   			a  / __gcd(a, b )*b


#define nCr(n, r)   			factorial(n) / (factorial(r) * factorial(n - r))
#define npr(n, r)   			factorial(n) / factorial(n - r)


#define mod_mul(a, b, m) 	    ((a%m)*(b%m))%m
#define mod_add(a, b, m) 	    ((a%m)+(b%m))%m
#define mod_sub(a, b, m) 	    ((a%m)-(b%m))%m


using namespace std;

long long binaryExponentiation(long long x, long long n)
{
    long long result = 1;
    while(n > 0) {
        if(n % 2 == 1)
            result *= x;
        x *= x;
        n /= 2;
    }
    return result;
}
long long factorial(long long n) {
    long long factorial = 1;
    for (long long i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}


int main()
{
    

    int tt;
    cin >> tt;
    while(tt--)
    {
        string s;           cin >> s;
        int sum1 = s[0] + s[1] + s[2];
        int sum2 = s[3] + s[4] + s[5];
        if(sum1 == sum2)    cout << "YES\n";
        else                cout << "NO\n";
    }
    return 0;
}



     		   	 		     					     		