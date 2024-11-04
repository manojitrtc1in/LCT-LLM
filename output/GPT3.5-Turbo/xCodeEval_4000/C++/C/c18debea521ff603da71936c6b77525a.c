#include<stdio.h>

#define f(i,a,b) for(int i=a;i<=b;i++)

int k,m;

void res(int s,int n){
    int dem=10;
    if(s>k) return;
    if(k-s<10){
        while(m && dem<100){
            printf("%d0%d", dem, k-s);
            if(n<10) printf("000");
            else if(n<100) printf("00");
            else if(n<1000) printf("0");
            printf("%d\n", n);
            m--;
            dem++;
        }
        return;
    }
    else if(k-s<100) printf("00%d", k-s);
    else if(k-s<1000) printf("0%d", k-s);
    else if(k-s<10000) printf("%d", k-s);
    if(n<10) printf("000");
    else if(n<100) printf("00");
    else if(n<1000) printf("0");
    printf("%d\n", n);
    m--;
}

void process(){
    int a,b,c,d,s;
    f(i,0,9999){
        int x[10000] = {0};
        a=i;
        d=a%10;
        a/=10;
        c=a%10;
        a/=10;
        b=a%10;
        a/=10;
        s=a*b*c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a-b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a-b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a-b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a-b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a*b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a*b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a*b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a*b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-(a+b*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-(-a+b*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-(a+b*c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-(-a+b*c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b*c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b*c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b+c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b-c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b+c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b-c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b+c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b-c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a-b+c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-10*a-b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b-c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b-10*c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-10*a-b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b-10*c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a-b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+10*b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-10*b-c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+10*b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+10*b+c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+10*b+c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a-b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b+c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b+c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b+c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b-c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b+c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b)*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b)*c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b)*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b)*c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b)*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b)*c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a-b)*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+b*(-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-b*(-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+b*(-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b)*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b)*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b)*(c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b)*(c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b)*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b)*(-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b+c)+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b+c)-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b-c)+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b-c)-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b+c)+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b+c)-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b-c)+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+(b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+(b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+(-b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+(-b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a+(b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a+(b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a-(b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b+c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=10*a+b-c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-10*a-b+c*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*b-10*c-d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=-a*b+10*c+d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a*b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a*b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b*c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b*c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b*c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a*b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b*c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b+c*d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b-c*d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b+c*d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(10*a+b)*(c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(10*a+b)*(c-d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(10*a+b)*(-c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a+b)*(10*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(a-b)*(10*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=(-a+b)*(10*c+d);
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(b-c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
        s=a*(-b+c)*d;
        if(s>0 && x[s]==0){
            x[s]++;
            res(s,i);
        }
        if(m==0) return;
    }
}

void process1(){
    for(int i=0;i<m;i++){
        if(i<10) printf("0000000%d\n", i);
        else if(i<100) printf("000000%d\n", i);
        else if(i<1000) printf("00000%d\n", i);
        else if(i<10000) printf("0000%d\n", i);
        else if(i<100000) printf("000%d\n", i);
        else if(i<1000000) printf("00%d\n", i);
    }
}

int main(){
    scanf("%d%d", &k, &m);
    if(k==0) process1();
    else process();
    return 0;
}
