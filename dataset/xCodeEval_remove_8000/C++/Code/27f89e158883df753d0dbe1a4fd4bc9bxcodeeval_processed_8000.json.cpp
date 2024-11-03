








using namespace std;
struct circle{
	long double x,y,r;
	bool p;
}c[MAXN];
bool operator < (const circle &a,const circle &b){
	return a.r>b.r;
}
inline long double calc_dist(ll x1,ll y1,ll x2,ll y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
inline bool check1(circle i,circle j,long double dist){

	return (long double)(i.r-j.r)>=dist;
}
inline bool check2(circle i,circle j,long double dist){

	return (long double)(i.r+j.r)<=dist;
}
inline long double dis(circle i,circle j){
	return calc_dist(i.x,i.y,j.x,j.y);
}
vector<circle>day,night;
int main(){




	int n;
	scanf("%d",&n);
	for (register int i=1;i<=n;++i){
		scanf("%Lf%Lf%Lf",&c[i].x,&c[i].y,&c[i].r);
		c[i].p=true;
	}
	sort(c+1,c+1+n);
	ll ans=0;
	for (register int i=1;i<=n;++i){
		ll mino=0x7fffffffffffffff;
		bool isday=true;
		int pos=0x7fffffff;
		bool dayflag=true;
		for (register int j=0;j<day.size();++j){
			if (check1(day[j],c[i],dis(day[j],c[i]))){
				if (day[j].r<mino){
					pos=j;
					isday=true;
					mino=day[j].r;
				}
				dayflag=false;
			}
		}
		if (dayflag){
			ans+=c[i].r*c[i].r;
			c[i].p=true;
			day.push_back(c[i]);
			continue;
		}
		bool nightflag=true;
		for (register int j=0;j<night.size();++j){
			if (check1(night[j],c[i],dis(night[j],c[i]))){
				if (night[j].r<mino){
					pos=j;
					isday=false;
					mino=night[j].r;
				}
				nightflag=false;
			}
		}
		if (nightflag){
			ans+=c[i].r*c[i].r;
			c[i].p=true;
			night.push_back(c[i]);
			continue;
		}
		if (isday){
			ans+=day[pos].p?-c[i].r*c[i].r:c[i].r*c[i].r;
			c[i].p=!day[pos].p;
			day.push_back(c[i]);
		}
		else {
			ans+=night[pos].p?-c[i].r*c[i].r:c[i].r*c[i].r;
			c[i].p=!night[pos].p;
			night.push_back(c[i]);
		}
	}
	printf("%.8Lf",(long double)(ans)*PI);
}