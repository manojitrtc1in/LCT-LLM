





















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
        int n, count = 0;
        cin >> n;
        string s;
        cin >> s;
        map<char, int>m;
        forn(i, n)
        {
            m[s[i]]++;
            if(m[s[i]] == 1)
                count += 2;
            else if(m[s[i]] > 1)
                count += 1;
        }
        cout << count << asd;
    }
    return 0;
}



 			   					   	    	   	  		 	