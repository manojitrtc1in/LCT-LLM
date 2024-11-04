
#include <iostream>
#include <fstream>
#include <string.h>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <list>
#include <queue>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>

#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,((int)(v.size())))

using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
const double pi = acos(-1.0);
const double EPS = 1e-8;
void Debug(int i)
{
   printf("\n----Debug %d-----\n",i);
}
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x)<EPS) return 0;
    if(x<0) return -1;
    return 1;
}

struct point
{
	double x,y; point(){};
	int id;
	point (double x0,double y0)
	{
		x=x0,y=y0;
	}
	point operator - (const point &b)const
	{
		return point(x-b.x,y-b.y);
	}
	point operator + (const point &b)const
	{
		return point(x+b.x,y+b.y);
	}
	double operator * (const point &b) const
	{
		return x*b.x+y*b.y;
	}
	point operator * (const double &b) const
	{
		return  point(x*b,y*b);
	}
	double operator ^ (const point &b) const
	{
		return x*b.y-y*b.x;
	}

	void transXY(double B)
	{
		double tx=x,ty=y;
		x = tx*cos(B)-ty*sin(B); y = tx*sin(B)+ty*cos(B);
	}

	bool operator == (const point &b)const
    {
        return (sgn(x-b.x)==0 && sgn(y-b.y)==0);
    }









    double len()
    {
        double t = x*x + y*y;
        return sqrt(t);
    }
    point unit()
    {
        double l = len();
        double xx = x/l;
        double yy = y/l;
        return point(xx,yy);
    }
    point neg()
    {
        return point(-x,-y);
    }
    bool operator < (const point &b)const
    {


        return x<b.x;
    }


};
typedef point Vector;
struct line
{
	point s,e; line(){};
	line(point a,point b)
	{
		s=a,e=b;
	}
	pair<int ,point> operator &(const line &b)const
	{
		point res=s;
		if(sgn((s-e)^(b.s-b.e))==0)
		{
			if(sgn((s-b.e)^(b.s-b.e))==0) return make_pair(0,res);
			else
			return make_pair(1,res);
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e)); res.x += (e.x-s.x)*t;
		res.y += (e.y-s.y)*t;
		return make_pair(2,res);
	}
	double len()
	{
	    point a = e-s;
	    return a.len();
	}
	point v;
    point get_point(double t)
    {
        return point(s.x+v.x*t,s.y+v.y*t);
    }

};

struct circle
{
	point heart; double r;
};
double dist(point a,point b)
{
	double xx=(a.x-b.x),yy=(a.y-b.y); return sqrt(xx*xx+yy*yy);
}

point point_to_segline(point p,line l)
{
point ret;
double t=(l.e-l.s)*(p-l.s);
t=fabs(t)/dist(l.s,l.e)/dist(l.s,l.e); if(t>=0&&t<=1)
{
ret.x=l.s.x+(l.e.x-l.s.x)*t;
ret.y=l.s.y+(l.e.y-l.s.y)*t;
}
else
{
if(dist(p,l.s)<dist(p,l.e)) ret=l.s;
else
ret=l.e;
}
return ret;
}


















































































































































































































































































































































































































































































































































































































































































































































































































































































































































struct pp
{
    LL x,y,z;
    pp(){};
    pp(LL _x, LL _y, LL _z){x = _x, y = _y, z = _z;}
    pp operator + (const pp &b) const
    {
        return pp(x+b.x,y+b.y,z+b.z);
    }
    pp operator - (const pp &b)const
    {
        return pp(x-b.x,y-b.y,z-b.z);
    }
    LL operator *(const pp &b)const
    {
        return x*b.x + y*b.y + z*b.z;
    }
    bool operator !=(const pp &b)const
    {
        if(b.x!=x || b.y!=y || b.z!=z)
            return 1;
        return 0;
    }
    bool operator == (const pp &b)const
    {
       if(b.x!=x || b.y!=y || b.z!=z)
            return 0;
        return 1;
    }
    LL Callen()const
    {
        return (*this)*(*this);
    }
    bool operator <(const pp &b)const
    {
        return 0;
    }
    int id;
}A[10],B[10];
typedef pp Vec;

bool check()
{
    pair<LL,Vec> v[10];
    forn(i,8)
    {
        Vec t = A[i]-A[0];
        v[i] = mp(t.Callen(),t);
    }
    sort(v,v+8);
    if(!v[1].X ||
       v[1].X!=v[2].X || v[1].X!=v[3].X||
       v[1].Y*v[2].Y||v[1].Y*v[3].Y||v[2].Y*v[3].Y
       )
    return 0;
    for(int i=1;i<4;i++)
    {
        for(int k=1;k<i;k++)
        {
            Vec t = v[i].Y + v[k].Y;
            if(t!=v[4].Y && t!=v[5].Y && t!=v[6].Y)
                return 0;
        }
    }
    if(v[1].Y + v[2].Y + v[3].Y != v[7].Y)
        return 0;
    printf("YES\n");
    for(int i=0;i<8;i++)
        printf("%I64d %I64d %I64d\n",A[i].x,A[i].y,A[i].z);
    exit(0);
}
void dfs(int i)
{
    if(i>=8)
    {
        check();
        return ;
    }
    vector<pp> tmp; tmp.clear();
    int  flag = 1;

    A[i]=B[i];
    tmp.pb(A[i]);
    dfs(i+1);

    A[i]=B[i];
    swap(A[i].x,A[i].y);
    forn(j,(int)tmp.size())
    {
        if(A[i] == tmp[j])
        {
            flag = 0;
        }
    }
    if(flag)
        dfs(i+1),tmp.pb(A[i]);
    else{
        flag = 1;
    }

    A[i]=B[i];
    swap(A[i].x,A[i].z);
    forn(j,(int)tmp.size())
    {
        if(A[i] == tmp[j])
        {
            flag = 0;
        }
    }
    if(flag)
        dfs(i+1),tmp.pb(A[i]);
    else{
        flag = 1;
    }

    A[i]=B[i];
    swap(A[i].z,A[i].y);
    forn(j,(int)tmp.size())
    {
        if(A[i] == tmp[j])
        {
            flag = 0;
        }
    }
    if(flag)
        dfs(i+1),tmp.pb(A[i]);
    else{
        flag = 1;
    }

    A[i]=B[i];
    swap(A[i].z,A[i].y);
    swap(A[i].z,A[i].x);
    forn(j,(int)tmp.size())
    {
        if(A[i] == tmp[j])
        {
            flag = 0;
        }
    }
    if(flag)
        dfs(i+1),tmp.pb(A[i]);
    else{
        flag = 1;
    }

    A[i]=B[i];
    swap(A[i].z,A[i].y);
    swap(A[i].x,A[i].y);
    forn(j,(int)tmp.size())
    {
        if(A[i] == tmp[j])
        {
            flag = 0;
        }
    }
    if(flag)
        dfs(i+1),tmp.pb(A[i]);
    else{
        flag = 1;
    }


}

int main()
{
    for(int i=0;i<8;i++)
        scanf("%I64d %I64d %I64d",&B[i].x,&B[i].y,&B[i].z);
    dfs(0);
    puts("NO");
    return 0;

}
























































