


using namespace std;





























typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, string> is;
typedef vector<ii> vii;














bool is_prime(long long x) {
	if (x == 1)
		return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;

}

bool id5(string s1)
{
    int l=s1.length();
    for(int i=0; i<l/2; i++)
        if(s1[i]!=s1[l-i-1])
        return false;

    return true;
}

ull C(ll n, ll k) {
	if (k == 0)
		return 1;
	return (n * C(n - 1, k - 1)) / k;
}

ll id0(ll base, ll exponent, int modulus) {
	ll result = 1;
	while (exponent > 0) {
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

long long id4(string number) {
	long long result = 0, pow = 1;
	for (int i = number.length() - 1; i >= 0; --i, pow <<= 1)
		result = (result + (number[i] - '0') * pow) % 1000003;

	return result;
}

ull GCD(ull a, ull b) {
	return b == 0 ? a : GCD(b, a % b);
}

int cntMask(int mask) {
	int ret = 0;
	while (mask) {
		if (mask % 2)
			ret++;
		mask /= 2;
	}
	return ret;
}
int getBit(int mask, int i) {
	return ((mask >> i) & 1) == 1;
}
int setBit(int mask, int i, int value = 1) {
	return (value) ? mask | (1 << i) : (mask & ~(1 << i));
}

ull id3(string s) {
	ull ans = 0;
	ull po = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += (s[i] - '0') * po;
		po *= 10;
	}

	return ans;

}

string conv(int i) {
	string t = "";
	while (i) {
		t += '0' + (i % 10);
		i /= 10;
	}
	

	return t;
}

bool hasZero(int i) {
	if (i == 0)
		return true;
	while (i) {
		if (i % 10 == 0)
			return true;
		i /= 10;
	}
	return false;
}






void id6()
{
	int n,a[100000+5];
	int first=-1;
	bool flag=true;
	int total=0;

	cin>>n;
	lp(i,n)
	{
		cin>>a[i];
		if(a[i] && flag)
		{
			first=i;
			flag=false;
		}
		if(a[i])total++;
	}

	int ans=0;
	if(first==-1)cout<<0<<endl;
	else
	{
       int idx=first;
		while(1)
		{
             if(total==0)break;


             if(a[idx]==0)
             {
            	 int fnd=1;
            	 lp(i,n)
            	 {
            		 if(a[i])
            		 {
            			 fnd++;
            			 idx=i;
            			 break;
            		 }
            	 }
            	 if(fnd==1)
            	     {
            	      cout<<ans<<endl;
            	       return ;
                }
             }


             if(idx==0)
             {
               if(abs(a[idx]-a[n-1]> abs(a[idx]-a[idx+1])))
               {
            	   

            	   idx=n-1;
            	   a[n-1]+=a[0];
            	   a[0]=0;
            	   idx=n-1;

               }
               else
               {
            	  

            	        idx++;
            	          a[idx]+=a[idx-1];
            	               	   a[idx-1]=0;

               }
             }

             else if(idx==n-1)
             {
            	 	if(abs(a[idx]-a[idx-1])<abs(a[idx]-a[0]))
            	 	{
                    idx=0;
                    a[idx]+=a[n-1];
                    a[n-1]=0;

            	 	}
            	 	else
            	 	{
                       idx--;
                       a[idx]+=a[n-1];
                       a[n-1]=0;
            	 	}
             }

             else
             {
            	 if(abs( a[idx] - a[idx+1] ) > abs ( a[idx] - a[idx-1] ) )
            	 {
            		 idx++;
            		 a[idx]+=a[idx-1];
            		 a[idx-1]=0;
            	 }
            	 else
            	 {
                        idx--;
                        a[idx]+=a[idx+1];
                        a[idx+1]=0;
            	 }

             }
             total--;
             ans++;
		}


		cout<<ans<<endl;
	}
	return;
}


bool id2(int a[],int n)
{
	lp(i,n-1)
			if(a[i]>a[i+1])return false;

	return true;
}

bool id1(int a[],int n)
{
	lp(i,n-1)
			if(a[i]<a[i+1])return false;

	return true;
}




void solveB()
{
	int n,a[1000+1];
	int ans=0;
	cin>>n;
	lp(i,n)cin>>a[i];
	int last;
	for(int i=n-1;i>=0;i--)
      if(a[i])
      {
    	  last=i;break;
      }

    lp(i,n)
	{


    	if(a[i])
    	{
    		ans++;
    		i++;
    		while(i<n && a[i]){ans++ ; i++;}
    		if(i>=last)break;
    		if(i<n && i<last)ans++;

    		

    	}



    	while(i<n && a[i]==0)i++;

    	if(i<n)i--;



	}
    cout<<ans<<endl;

}

int main(void)
{


solveB();

}










