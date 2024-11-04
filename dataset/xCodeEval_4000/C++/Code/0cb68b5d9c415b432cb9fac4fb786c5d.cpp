






#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#define LD long double
#define PI 3.1415926535L
using namespace std;

LD INF=1e20;
LD EPS=1e-9;

class Math {
public:
    pair<LD, LD> solveQuadratic(LD a, LD b, LD c) {
        pair<LD,LD> ret = pair<LD,LD>(INF, INF);
        if(a==0 && b==0)
            return ret;
        if(a==0 && b!=0) {
            ret.first = -c/b;
            ret.second = -c/b;
            return ret;
        }

        LD D=b*b-4*a*c;
        if(D<0)
            return ret;
        ret.first = (-b + sqrt(D))/(2*a);
        ret.second = (-b - sqrt(D))/(2*a);
    
        return ret;
    }
};

class Geometry
{
public:
    pair<LD,LD> circumcentre(LD x1, LD y1, LD x2, LD y2, LD x3, LD y3)
    {
        pair<LD,LD> ret;
        LD c1=(-x1*x1+x2*x2-y1*y1+y2*y2)/2;
        LD c2=(-x1*x1+x3*x3-y1*y1+y3*y3)/2;
        ret.first = (c2*(y2-y1)-c1*(y3-y1))/((y2-y1)*(x3-x1)-(y3-y1)*(x2-x1));
        ret.second = (c2*(x2-x1)-c1*(x3-x1))/((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
        return ret;
    }
    LD getAngle(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
    {
        long double a=((x2-x1)*(x3-x1)+(y2-y1)*(y3-y1))/sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)));
        a=acos(a);
        if(a<0)
            a+=PI;
        return a;
    }
    LD triangleArea(long double x1,long double y1,long double x2,long double y2,long double x3,long double y3)
    {
        return (x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2))/2.0;
    }
    vector<pair<LD, LD> > circleCircleIntersection(LD x1, LD y1, LD r1, LD x2, LD y2, LD r2)
    {
        vector<pair<LD, LD> > ret;
        
        LD d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(d>r1+r2 || d<fabs(r1-r2)) {
            return ret;
        } else if(d==0 && fabs(r1-r2)<EPS) {
            ret.push_back(pair<LD,LD>(INF, INF));
            return ret;
        }

        LD a=r1*r1-r2*r2+d*d;
        
        a=a/(2*d);
        LD x3=x1+a*(x2-x1)/d;
        LD y3=y1+a*(y2-y1)/d;
        LD h=sqrt(r1*r1-a*a);

        LD x4=x3+h*(y2-y1)/d;
        LD x5=x3-h*(y2-y1)/d;
        LD y4=y3-h*(x2-x1)/d;
        LD y5=y3+h*(x2-x1)/d;

        ret.push_back(pair<LD,LD>(x4, y4));
        ret.push_back(pair<LD,LD>(x5, y5));
        return ret;
    }
    vector<pair<LD, LD> > circleLineIntersection(LD g, LD h, LD r, LD a, LD b, LD c)
    {
        vector<pair<LD, LD> > ret;

        if(a==0 && b==0)
            return ret;

        if(b==0) {
            LD A = a*a;
            LD B = -2*a*a*h;
            LD C = c*c + a*a*g*g + 2*a*c + a*a*h*h - a*a*r*r;
            pair<LD,LD> Y = Math().solveQuadratic(A,B,C);
            if(fabs(Y.first - INF) > EPS) {
                ret.push_back(pair<LD, LD>(-c/a, Y.first));
            }
            if(fabs(Y.second - INF) > EPS) {
                ret.push_back(pair<LD, LD>(-c/a, Y.second));
            }
            return ret;
        }

        LD A=a*a+b*b;
        LD B=2*a*b*h+2*a*c-2*g*b*b;
        LD C=g*g*b*b+c*c+b*b*h*h+2*b*h*c-r*r*b*b;
        pair<LD,LD> X = Math().solveQuadratic(A,B,C);

        if(fabs(X.first - INF) > EPS) {
            ret.push_back(pair<LD, LD>(X.first, (-c-a*X.first)/b));
        }
        if(fabs(X.second - INF) > EPS) {
            ret.push_back(pair<LD, LD>(X.second, (-c-a*X.second)/b));
        }
        return ret;
    }

    pair<LD, LD> lineLineIntersection(LD a1, LD b1, LD c1, LD a2, LD b2, LD c2) {
        pair<LD,LD> ret;
        if(b1==0 && b2==0 || (b1!=0 && b2!=0 && fabs(a1/b1-a2/b2)<EPS)) {
            ret.first = INF;
            ret.second = INF;
            return ret;
        }
        if(b1 != 0) {
            ret.first = (b2*c1 - b1*c2)/(b1*a2-b2*a1);
            ret.second = (-a1*ret.first-c1)/b1;
        } else {
            ret.first = (b1*c2 - b2*c1)/(b2*a1-b1*a2);
            ret.second = (-a2*ret.first-c2)/b2;
        }
        return ret;
    }
};




 















#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class CircleOrLine {
public:
    int type; 

    LD a,b,c; 

    LD g,h,r;
};

CircleOrLine fun(LD g1, LD h1, LD r1, LD g2, LD h2, LD r2) {
    CircleOrLine ret;
    if(fabs(r1-r2)<EPS) {
        ret.type=1;
        ret.a=2*g1-2*g2;
        ret.b=2*h1-2*h2;
        ret.c=g2*g2+h2*h2-g1*g1-h1*h1;
    } else {
        ret.type=2;
        LD k=r1*r1/(r2*r2);
        ret.g=(g1-g2*k)/(1-k);
        ret.h=(h1-h2*k)/(1-k);
        ret.r=sqrt(ret.g*ret.g+ret.h*ret.h-(g1*g1+h1*h1-k*g2*g2-k*h2*h2)/(1-k));
    }
    return ret;
}

int main()
{
    LD x[3],y[3],r[3];
    for(int i=0; i<3; i++) {
        cin>>x[i]>>y[i]>>r[i];
    }

    CircleOrLine c1 = fun(x[0],y[0],r[0],x[1],y[1],r[1]);
    CircleOrLine c2 = fun(x[1],y[1],r[1],x[2],y[2],r[2]);

    vector<pair<LD,LD> > pts;
    if(c1.type==2 && c2.type==2) {
        pts = Geometry().circleCircleIntersection(c1.g, c1.h, c1.r, c2.g, c2.h, c2.r);
    } else if (c1.type==2 && c2.type==1) {
        pts = Geometry().circleLineIntersection(c1.g, c1.h, c1.r, c2.a, c2.b, c2.c);
    } else if (c1.type==1 && c2.type==2) {
        pts = Geometry().circleLineIntersection(c2.g, c2.h, c2.r, c1.a, c1.b, c1.c);
    } else {
        pts.push_back(Geometry().lineLineIntersection(c2.a, c2.b, c2.c, c1.a, c1.b, c1.c));
    }

    pair<LD,LD> ret(INF, INF);
    LD cosine=0;

    for(int i=0; i<pts.size(); i++) {
        bool found = true;
        LD localCosine=INF;
        
        for(int j=0; j<3; j++) {
            LD t = (r[j]*r[j])/((x[j]-pts[i].first)*(x[j]-pts[i].first)+(y[j]-pts[i].second)*(y[j]-pts[i].second));
            if(t>=1.0 || (localCosine<=1.0 &&  fabs(t-localCosine)>EPS)) {
                found = false;
                break;
            }
            if(localCosine>1.0)
                localCosine = t;
        }
        if(found && cosine<localCosine) {
            cosine = localCosine;
            ret = pts[i];
        }
    }

    if(fabs(ret.first-INF)>EPS) {
        cout<<ret.first<<" "<<ret.second<<endl;
        

        

        
    }
    return 0;
}