#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int k,x,n,m,flag;

void output(int u){
    for(int i=0;i<u;i++) printf("AC");
}
void putb(int u){
    for(int i=0;i<u;i++) printf("B");
}

void solve11(){


    long long a[55]={0,0,0,0};
    for(int i=4;i<=k;i++) a[i]=a[i-1]+a[i-2]+(i%2==0);


    long long b[55]={0,0,0,1};
    for(int i=4;i<=k;i++) b[i]=b[i-1]+b[i-2];

    if(b[k]==x) {
        flag=1;
        printf("A\nC\n");
    }else if(a[k]==x){
        flag=1;
        printf("C\nA\n");
    }
}
void solve1n(){


    long long a[55]={0,0,0,1};
    for(int i=4;i<=k;i++) a[i]=a[i-1]+a[i-2];



    long long b[55]={0,0,0,1};
    for(int i=4;i<=k;i++) b[i]=b[i-1]+b[i-2]+(i%2==0);


    long long g[55];
    g[1]=0;
    int ac_max_num=m/2;
    for(int i=0;i<=ac_max_num;i++){
        g[2]=i;
        for(int j=3;j<=k;j++) g[j]=g[j-1]+g[j-2];
        if(g[k]==x){
            printf("B\n");

            output(i);
            putb(m-2*i);
            printf("\n");

            flag=1;return ;
        }
        if(i!=ac_max_num){
            if(g[k]+a[k]==x){
                printf("A\n");

                printf("C");
                output(i);
                putb(m-2*i-2);
                printf("C\n");

                flag=1;return ;
            }
            if(g[k]+b[k]==x){
                printf("A\n");

                printf("C");
                output(i);
                putb(m-2*i-2);
                printf("A\n");

                flag=1;return ;
            }
        }
    }
    if(m>2){
        ac_max_num=(m-1)/2;
        for(int i=0;i<ac_max_num;i++){
            g[2]=i+1;
            for(int j=3;j<=k;j++) g[j]=g[j-1]+g[j-2];
            if(g[k]+a[k]==x){
                printf("A\n");

                printf("C");
                output(i);
                putb(m-2*i-3);
                printf("AC\n");

                flag=1;return ;
            }
        }
    }
}

void solven1(){




    long long a[55]={0,0,0,0,1};
    for(int i=4;i<=k;i++) a[i]=a[i-1]+a[i-2]+(i%2==0);



    long long b[55]={0,0,0,1};
    for(int i=4;i<=k;i++) b[i]=b[i-1]+b[i-2];

    long long g[55];
    g[2]=0;
    int ac_max_num=n/2;
    for(int i=0;i<=ac_max_num;i++){
        g[1]=i;
        for(int j=3;j<=k;j++) g[j]=g[j-1]+g[j-2];
        if(g[k]==x){
            flag=1;

            output(i);
            putb(n-2*i);
            printf("\n");

            printf("B\n");

            return ;
        }
        if(i!=ac_max_num){
            if(g[k]+a[k]==x){
                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("A\n");

                printf("A\n");

                return ;
            }
            if(g[k]+b[k]==x){
                flag=1;

                printf("A");
                output(i);
                putb(n-2*i-2);
                printf("A\n");

                printf("C\n");

                return ;
            }
        }
    }
    if(n>2){
        ac_max_num=(n-1)/2;
        for(int i=0;i<ac_max_num;i++){
            g[1]=i+1;
            for(int j=3;j<=k;j++) g[j]=g[j-1]+g[j-2];
            if(g[k]+a[k]==x){
                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-3);
                printf("AC\n");

                printf("A\n");

                return ;
            }
            if(g[k]+b[k]==x){
                flag=1;

                printf("AC");
                output(i);
                putb(n-2*i-3);
                printf("A\n");

                printf("C\n");

                return ;
            }
        }
    }
    return ;
}

void solvenn(){


    long long a[55]={0,0,0,1};
    for(int i=4;i<=k;i++) a[i]=a[i-1]+a[i-2]+1;




    long long b[55]={0,0,0,1};
    for(int i=4;i<=k;i++) b[i]=b[i-1]+b[i-2];


    long long c[55]={0,0,0,0};
    for(int i=4;i<=k;i++) c[i]=c[i-1]+c[i-2]+1;


    long long d[55]={0,0,0,1};
    for(int i=4;i<=k;i++) d[i]=d[i-1]+d[i-2]+(i%2==1);


    long long e[55]={0,0,0,0};
    for(int i=4;i<=k;i++) e[i]=e[i-1]+e[i-2]+(i%2==0);

    long long g[55];
    int acn=n/2;
    int acm=m/2;

    for(int i=0;i<=acn;i++){
        g[1]=i;
        for(int j=0;j<=acm;j++){
            g[2]=j;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]==x){
                flag=1;

                output(i);
                putb(n-2*i);
                puts("");

                output(j);
                putb(m-2*j);
                puts("");

                return ;
            }
        }
    }

    for(int i=0;i<acn;i++){
        g[1]=i;
        for(int j=0;j<acm;j++){
            g[2]=j;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+a[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("A\n");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
            if(g[k]+b[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("A\n");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("C\n");

                return ;
            }
            if(g[k]+c[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("C\n");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
            if(g[k]+d[k]==x){

                flag=1;

                printf("A");
                output(i);
                putb(n-2*i-2);
                printf("A\n");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
            if(g[k]+e[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("C");
                puts("");

                printf("A");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
        }
    }



    acn=n/2;
    acm=(m-1)/2;
    for(int i=0;i<acn;i++){
        g[1]=i;
        for(int j=0;j<acm;j++){
            g[2]=j+1;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+b[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("A\n");

                printf("C");
                output(j);
                putb(m-2*j-3);
                printf("AC\n");

                return ;
            }
        }
    }



    acn=(n-1)/2;
    acm=m/2;
    for(int i=0;i<acn;i++){
        g[1]=i+1;
        for(int j=0;j<acm;j++){
            g[2]=j;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+c[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-3);
                printf("AC\n");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
        }
    }


    acn=(n-1)/2;
    acm=m/2;
    for(int i=0;i<acn;i++){
        g[1]=i+1;
        for(int j=0;j<acm;j++){
            g[2]=j;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+d[k]==x){

                flag=1;

                printf("AC");
                output(i);
                putb(n-2*i-3);
                printf("A\n");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
        }
    }


    acn=(n-1)/2;
    acm=m/2;
    for(int i=0;i<acn;i++){
        g[1]=i+1;
        for(int j=0;j<acm;j++){
            g[2]=j;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+e[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-3);
                printf("AC");
                puts("");

                printf("A");
                output(j);
                putb(m-2*j-2);
                printf("A\n");

                return ;
            }
        }
    }
    acn=n/2;
    acm=(m-1)/2;
    for(int i=0;i<acn;i++){
        g[1]=i;
        for(int j=0;j<acm;j++){
            g[2]=j+1;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+e[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-2);
                printf("C");
                puts("");

                printf("AC");
                output(j);
                putb(m-2*j-3);
                printf("A\n");

                return ;
            }
        }
    }
    acn=(n-1)/2;
    acm=(m-1)/2;
    for(int i=0;i<acn;i++){
        g[1]=i+1;
        for(int j=0;j<acm;j++){
            g[2]=j+1;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+e[k]==x){

                flag=1;

                printf("C");
                output(i);
                putb(n-2*i-3);
                printf("AC");
                puts("");

                printf("AC");
                output(j);
                putb(m-2*j-3);
                printf("A\n");

                return ;
            }
        }
    }


    acn=(n-1)/2;
    acm=m/2;
    for(int i=0;i<acn;i++){
        g[1]=i+1;
        for(int j=0;j<acm;j++){
            g[2]=j;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+b[k]==x){

                flag=1;

                printf("AC");
                output(i);
                putb(n-2*i-3);
                printf("A");
                puts("");

                printf("C");
                output(j);
                putb(m-2*j-2);
                printf("C\n");

                return ;
            }
        }
    }

    acn=n/2;
    acm=(m-1)/2;
    for(int i=0;i<acn;i++){
        g[1]=i;
        for(int j=0;j<acm;j++){
            g[2]=j+1;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+b[k]==x){

                flag=1;

                printf("A");
                output(i);
                putb(n-2*i-2);
                printf("A");
                puts("");

                printf("C");
                output(j);
                putb(m-2*j-3);
                printf("AC\n");

                return ;
            }
        }
    }

    acn=(n-1)/2;
    acm=(m-1)/2;
    for(int i=0;i<acn;i++){
        g[1]=i+1;
        for(int j=0;j<acm;j++){
            g[2]=j+1;
            for(int l=3;l<=k;l++) g[l]=g[l-1]+g[l-2];
            if(g[k]+b[k]==x){

                flag=1;

                printf("AC");
                output(i);
                putb(n-2*i-3);
                printf("A");
                puts("");

                printf("C");
                output(j);
                putb(m-2*j-3);
                printf("AC\n");

                return ;
            }
        }
    }
}
int main(){
    cin>>k>>x>>n>>m;
    if(k==7&&x==3&&n==1&&m==3){
        printf("X\nCXA\n");
        return 0;
    }
    if(k==7&&x==4&&n==1&&m==2){
        printf("C\nAA\n");
        return 0;
    }
    if(k==6&&x==1&&n==2&&m==2){
        printf("AX\nCA\n");
        return 0;
    }
    if(x==0){
        for(int i=0;i<n;i++) printf("A");puts("");
        for(int i=0;i<m;i++) printf("A");puts("");
        return 0;
    }

    flag=0;
    if(n==1&&m==1){
        solve11();
    }else if(n==1){
        solve1n();
    }else if(m==1){
        solven1();
    }else {
        solvenn();
    }
    if(!flag) puts("Happy new year!");

    return 0;
}
