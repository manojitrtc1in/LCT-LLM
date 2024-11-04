






using namespace std;

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int nPr(int n, int r)
{
    return factorial(n) / factorial(n - r);
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}


int main()
{
    SUPERPOWER
    int tt, n, numT, numM, flag = 1;
    string a;                           cin >> tt;
	while(tt--)
	{
        numT = 0, numM = 0, flag = 1;   cin >> n >>a;
		for(int i = 0; i < n; i++)
        {
			if(a[i] == 'T')             numT++;
			if(a[i] == 'M')             numM++;
			if(numT < numM)
			{
			    flag =0;
                break;
            }
		}
		numT = 0, numM = 0;
		for(int i = n-1; i >= 0; i--)
        {
			if(a[i] == 'T')              numT++;
			if(a[i] == 'M')              numM++;
			if(numT < numM)
			{
			    flag = 0;
                break;
            } 
		}
		if(flag == 0 || numT != numM*2)  cout << "NO\n";
		else                             cout << "YES\n";
	}
    return 0;
}


