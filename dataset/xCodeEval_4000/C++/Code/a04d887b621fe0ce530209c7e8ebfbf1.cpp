

#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<list>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<sstream>
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define FORs(i,a,b)             for(int i=a;i>=b;i--)
#define fill(a,v)               memset(a,v,sizeof a)
#define abS(x)                  ((x)<0?-(x):(x))
#define mP                      make_pair
#define pB                      push_back
#define error(x)                cout << #x << " : " << (x) << endl
#define all(c)                  (c).begin(),(c).end()
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d",n)
#define pc(n)                       printf("%c",n)
#define pl(n)                       printf("%lld",n)
#define pf(n)                       printf("%lf",n)
#define ps(n)                       printf("%s",n)

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;

void chekarre(int * arr,int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}

inline int haint()
{
	int h;
	 register char c=0;
	 while (c<33) c=getchar();

	 h=0;
	 while (c>33)
	 {
	     h=h*10+c-'0';
	     c=getchar();

	 }
	 return h;
}
int n, m , x,y;
struct Edge{
	int x,y;
};

bool cmp(const Edge &a, const Edge &b){
	return ((abS(a.x)+abS(a.y))< (abS(b.x)+abS(b.y)));
}

vector <Edge> pool;


string ans[900000], s[10];
int solve()
{
	string s1;          

	ostringstream convert;   





	int cx=0, cy=0, nm;
	PII p;
	int pos=0, cnt=0, tot=0;

	FOR(i,0,pool.size())

	{
		pos=0;
		s1.clear();
		x=pool[i].x, y=pool[i].y;
		

		

		

		

		if(x < cx )
		{

			ostringstream convert;
			nm=abS(x-cx);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" L";
			pos++;
		}
		else if( x > cx)
		{
			ostringstream convert;
			

			nm=abS(x-cx);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" R";
			pos++;
			

		}

		if(y < cy )
		{
			ostringstream convert;
			

			nm=abS(y-cy);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" D";
			pos++;
			

		}else if( y > cy)
		{
			ostringstream convert;
			

			nm=abS(y-cy);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" U";
			pos++;
			

		}
		cx=x; cy=y;
		x=0, y=0;
		s[pos]+="2";
		pos++;
		


		if(x < cx )
		{
			ostringstream convert;
			nm=abS(x-cx);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" L";
			pos++;
			

		}else if( x > cx)
		{
			ostringstream convert;
			

			nm=abS(x-cx);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" R";
			pos++;
			

		}

		if(y < cy )
		{
			ostringstream convert;
			

			nm=abS(y-cy);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" D";
			pos++;
			

		}else if( y > cy)
		{
			ostringstream convert;
			

			nm=abS(y-cy);
			convert<<nm;
			s1=convert.str();
			s[pos]+="1 ";
			s[pos]+=s1;
			s[pos]+=" U";
			pos++;
			

		}
		s[pos]+="3";
		pos++;
		

		cx=0, cy=0;
		FOR(i,0,pos)
		{
			ans[cnt]+=s[i];
			ans[cnt]+="\n";
			s[i].clear();
		}
		tot+=pos;
		cnt++;
	}


	cout<<tot<<endl;
	FOR(i,0,cnt)
	{
		cout<<ans[i];

	}
    return 1;
}

bool input()
{
	s(n);
	FOR(i,0,n)
	{
		s(x); s(y);
		Edge e;
		e.x=x, e.y=y;
		pool.push_back(e);
		
	}
		sort(pool.begin(), pool.end(),cmp);
	

	

	return true;
}

int main()
{
    

    


    int T=1;
    

    for(int testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;

        solve();
        


    }


    return 0;
}



