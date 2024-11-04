





















using namespace std;

long long id0(long long x, long long n)
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



     		   	 		     					     		