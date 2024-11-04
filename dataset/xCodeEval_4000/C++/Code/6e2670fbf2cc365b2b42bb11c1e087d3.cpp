
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define ll   long long
#define ull unsigned long long
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)


using namespace std;
const int M[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
struct dayformat{
	int second,minute,hour;
};
vector<dayformat> eachday;
vector<int> D;

int findday(int tot){
	return (tot+2)%7+1;
}
dayformat exchange(int nowsecond){
	dayformat ret;
	ret.hour=nowsecond/(60*60);
	nowsecond-=ret.hour*3600;
	ret.minute=nowsecond/60;
	nowsecond-=ret.minute*60;
	ret.second=nowsecond;
	return ret;
}
int exchanged(dayformat ddd){
	int ret=ddd.hour*3600+ddd.minute*60+ddd.second;
	return ret;
}
bool check(dayformat a,dayformat b){
	if (a.hour!=-1 && a.hour!=b.hour) return false;
	if (a.minute!=-1 && a.minute!=b.minute) return false;
	if (a.second!=-1 && a.second!=b.second) return false;
	return true;
}
bool is_l(int x){
	return (x%400==0) || (x%100!=0 && x%4==0);
}
int main(){
	int s,m,h,day,date,month;
	scanf("%d %d %d %d %d %d",&s,&m,&h,&day,&date,&month);
	eachday.clear();
	dayformat fin={s,m,h};
	for (int i=0;i<24*60*60;i++){
		dayformat now=exchange(i);
		if (check(fin,now)) eachday.push_back(now);
	}
	int totday=0;
	for (int year=1970;year<34000;year++){
		for (int nowmonth=1;nowmonth<=12;nowmonth++){
			int daylimit=M[nowmonth];
			if (is_l(year) && nowmonth==2){
				daylimit++;
			}
			for (int nowdate=1;nowdate<=daylimit;nowdate++){
				totday++;
				int nowday=findday(totday);
				bool good=true;
				if (day!=-1 && nowday!=day) good=false;
				if (date!=-1 && nowdate!=date) good=false;
				if (day!=-1 && date!=-1 && (nowday==day|| nowdate==date) ) good=true;
				if (!(month==-1 || month==nowmonth)) good=false;
				if (good) D.push_back(totday);
			}
		}
	}
	int n;
	scanf("%d",&n);
	while (n--){
		long long time;
		scanf("%I64d",&time);
		long long daynum=time/3600/24-1;
		daynum=max(daynum,0ll);
		int loc=lower_bound(D.begin(),D.end(),daynum)-D.begin();
		bool find=false;
		long long ans=0;
		for (int nowday=loc;;nowday++){
			int dayid=D[nowday];
			for (int nowsecond=0;nowsecond<eachday.size();nowsecond++){
				int secondnum=exchanged(eachday[nowsecond]);
				long long totsecond=((ll)dayid-1)*(ll)3600*(ll)24+(ll)secondnum;
				if (totsecond>time){
					find=true;
					ans=totsecond;
					break;
				}
			}
			if (find) break;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
