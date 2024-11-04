#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
























































































#include<iostream>
#include<cstdio>
#include<vector>
#include<cctype>
#include<algorithm>
#include<stack>
#include<map>
struct mat
{
	int x1,x2,y1,y2;
	mat(int x1=0,int x2=0,int y1=0,int y2=0){this->x1=x1,this->x2=x2,this->y1=y1,this->y2=y2;}
};
int n,pc[1000005],fst=1;;
std::vector<int> mnl,mxl,mnr,mxr;
long long f[1000005],ans=0;
std::vector<mat> v1[75],v2[75];
long long ot=0;
namespace matrix
{
	struct sgt
	{
		struct node
		{
			int tag,cnt,mn;
		};
		node a[2100005];
		
		void put(int k,int s)
		{
			a[k].tag=a[k].tag+s;
			a[k].mn=a[k].mn+s;
		}
		void pushup(int k)
		{
			a[k].cnt=0;
			a[k].mn=std::min(a[k*2].mn,a[k*2+1].mn);
			if (a[k*2].mn==a[k].mn) a[k].cnt=a[k].cnt+a[k*2].cnt;
			if (a[k*2+1].mn==a[k].mn) a[k].cnt=a[k].cnt+a[k*2+1].cnt;
		}
		void pushdown(int k)
		{
			if (!a[k].tag) return;
			put(k*2,a[k].tag);
			put(k*2+1,a[k].tag);
			a[k].tag=0;
		}
		void update(int k,int l,int r,int x,int y,int s)
		{
			if (x<=l&&r<=y) return put(k,s);
			int mid=(l+r)/2;
			pushdown(k);
			if (x<=mid) update(k*2,l,mid,x,y,s);
			if (mid<y) update(k*2+1,mid+1,r,x,y,s);
			pushup(k);
		}
		std::pair<int,int> merge(const std::pair<int,int> &x,const std::pair<int,int> &y)
		{
			std::pair<int,int> ret;
			ret.first=std::min(x.first,y.first);
			ret.second=(x.first==ret.first)*x.second+(y.first==ret.first)*y.second;
			return ret;
		}
		std::pair<int,int> ask(int k,int l,int r,int x,int y)
		{
			if (x<=l&&r<=y) return std::make_pair(a[k].mn,a[k].cnt);
			int mid=(l+r)/2,flagl=0,flagr=0;
			std::pair<int,int> ll,rr;
			pushdown(k);
			if (x<=mid) ll=ask(k*2,l,mid,x,y),flagl=1;
			if (mid<y) rr=ask(k*2+1,mid+1,r,x,y),flagr=1;
			if (!flagr) return ll;
			if (!flagl) return rr;
			return merge(ll,rr);
		}
		void build(int k,int l,int r)
		{
			a[k].tag=a[k].cnt=0;a[k].mn=2;
			if (l==r) return a[k].cnt=1,void();
			int mid=(l+r)/2;
			build(k*2,l,mid);
			build(k*2+1,mid+1,r);
			pushup(k);
		}
	};


	sgt tt;
	std::vector<int> p;
	int mp[1000005];

	std::vector< std::pair<int,int> > ept;
	std::vector< std::pair<int,int> > add1[1000005],del1[1000005],add2[1000005],del2[1000005];
	int getlen(const std::pair<int,int> &s){return s.second-s.first+1;}
	long long getans(const std::vector<mat> &s1,const std::vector<mat> &s2)
	{
		if (!s1.size()||!s2.size()) return 0;
		










		long long ans=0;


		if (fst) tt.build(1,1,n),fst=0;
		for (int i=0;i<(int)s1.size();i++)
		{
			mat x=s1[i];
			add1[x.x1].push_back(std::make_pair(x.y1,x.y2));
			del1[x.x2+1].push_back(std::make_pair(x.y1,x.y2));
			if (!mp[x.x1]) mp[x.x1]=1,p.push_back(x.x1);
			if (!mp[x.x2+1]) mp[x.x2+1]=1,p.push_back(x.x2+1);
		}
		for (int i=0;i<(int)s2.size();i++)
		{
			mat x=s2[i];
			add2[x.x1].push_back(std::make_pair(x.y1,x.y2));
			del2[x.x2+1].push_back(std::make_pair(x.y1,x.y2));
			if (!mp[x.x1]) mp[x.x1]=1,p.push_back(x.x1);
			if (!mp[x.x2+1]) mp[x.x2+1]=1,p.push_back(x.x2+1);
		}
		if (!mp[n+1]) mp[n+1]=1;
		int now=0,lst=1;
		std::stable_sort(p.begin(),p.end());


		for (int i=0;i<(int)p.size();i++)
		{
			int x=p[i];




			ans=ans+1ll*now*(x-lst);
			lst=x;
			for (int d=0;d<(int)del1[x].size();d++)
			{
				std::pair<int,int> k=del1[x][d];
				


				tt.update(1,1,n,k.first,k.second,1);
			}
			for (int d=0;d<(int)add1[x].size();d++)
			{
				std::pair<int,int> k=add1[x][d];
				
				tt.update(1,1,n,k.first,k.second,-1);
			}


			for (int d=0;d<(int)del2[x].size();d++)
			{
				std::pair<int,int> k=del2[x][d];
				
				tt.update(1,1,n,k.first,k.second,1);
			}
			for (int d=0;d<(int)add2[x].size();d++)
			{
				std::pair<int,int> k=add2[x][d];
				
				tt.update(1,1,n,k.first,k.second,-1);
			}
			now=tt.a[1].cnt*(tt.a[1].mn==0);


		}






		for (int i=0;i<(int)p.size();i++)
		{
			std::vector< std::pair<int,int> >().swap(add1[p[i]]);
			std::vector< std::pair<int,int> >().swap(add2[p[i]]);
			std::vector< std::pair<int,int> >().swap(del1[p[i]]);
			std::vector< std::pair<int,int> >().swap(del2[p[i]]);
		}
		for (int i=0;i<(int)s1.size();i++) mp[s1[i].x1]=mp[s1[i].x2+1]=0;
		for (int i=0;i<(int)s2.size();i++) mp[s2[i].x1]=mp[s2[i].x2+1]=0;
		mp[n+1]=0;
		p.clear();


		return ans;
	}
}
int cmp(int x,int y){return f[x]!=f[y]?f[x]>f[y]:x>y;}
int solve(long long s){return s?solve(s>>1)+(s&1):0;}
long long read()
{
	long long x=0;char ch=0;
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=x*10+ch-48,ch=getchar();
	return x;
}
int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n;
	for (int i=1;i<=n;i++) std::cin>>f[i];
	for (int i=1;i<=n;i++) pc[i]=solve(f[i]);
	mnl.resize(n+5);mnr.resize(n+5);mxl.resize(n+5),mxr.resize(n+5);


	std::stack<int> st;
	f[0]=5000000000000000000;st.push(0);
	for (int i=1;i<=n;i++)
	{
		while (!st.empty()){int x=st.top();if (!cmp(i,x)) break;st.pop();}
		mxl[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	f[n+1]=5000000000000000000;st.push(n+1);
	for (int i=n+1;i>=1;i--)
	{
		while (!st.empty()){int x=st.top();if (!cmp(i,x)) break;st.pop();}
		mxr[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	f[0]=-5000000000000000000;st.push(0);
	for (int i=1;i<=n;i++)
	{
		while (!st.empty()){int x=st.top();if (cmp(i,x)) break;st.pop();}
		mnl[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	f[n+1]=-5000000000000000000;st.push(n+1);
	for (int i=n;i>=1;i--)
	{
		while (!st.empty()){int x=st.top();if (cmp(i,x)) break;st.pop();}
		mnr[i]=st.top();
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=1;i<=n;i++) v1[pc[i]].push_back(mat(mxl[i]+1,i,i,mxr[i]-1));
	for (int i=1;i<=n;i++) v2[pc[i]].push_back(mat(mnl[i]+1,i,i,mnr[i]-1));
	std::vector<int>().swap(mnl);
	std::vector<int>().swap(mnr);
	std::vector<int>().swap(mxl);
	std::vector<int>().swap(mxr);




	for (int i=0;i<64;i++)
	{












		ans=ans+matrix::getans(v1[i],v2[i]);
	}
	printf("%lld\n",ans);


	return 0;
}

