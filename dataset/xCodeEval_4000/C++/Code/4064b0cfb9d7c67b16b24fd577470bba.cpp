





















 







#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
double slove(double a,double b,double c)

{
    return (-b+sqrt(b*b-4*a*c))/(2*a);
}
int main()
{
    double a,v,len,d,w,ans=0;
    scanf("%lf%lf%lf%lf%lf",&a,&v,&len,&d,&w);
    if(w>=v||w*w/(2*a)>d)

    {
        double x=(v*v)/(2*a);

        if(x>=len)

        {
            ans+=sqrt(2*a*len)/a;

        }
        else
        {
            ans+=(len-x)/v+v/a;
        }
    }
    else

    {
        len-=d;

        double tx=w*w/(2*a);

        double t=w/a;

        d-=tx;

        ans+=t;d/=2;
        tx=(v*v-w*w)/(2*a);
        if(tx>d)

        {
            double tv=sqrt(2*a*d+w*w);
            ans+=2*(tv-w)/a;
        }
        else
        {
            ans+=2*(v-w)/a+2*(d-tx)/v;

        }
        

        tx=(v*v-w*w)/(2*a);
        if(tx>len)

        {
            double tv=sqrt(2*a*len+w*w);
            ans+=(tv-w)/a;
        }
        else
        {
            ans+=(v-w)/a+(len-tx)/v;

        }
    }
    printf("%.12lf\n",ans);
    return 0;
}

