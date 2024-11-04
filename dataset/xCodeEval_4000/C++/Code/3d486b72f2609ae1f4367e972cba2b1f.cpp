#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include <iomanip>
#include<stack>
#include<set>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<math.h>
#include <time.h>
using namespace std;
#define mdlo 1000000007
#define maxERR 0.0000002


#define maxBits 40
#define pi 3.1415926535897932384626433832795
#define INF 999999999999
typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>mymap;
typedef pair<ll,ll>skill;
skill skills[100005];
ll summation[100005];
long long getmoduloInv(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=getmoduloInv(mdlo%n);
    mInv[n]=(m%mdlo);
    return mInv[n];
}
double getDist(double x1,double y1,double x2,double y2,double x3,double y3){
    double dist1=((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3));
    double dist2=((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3));
    double dist3=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
    if(dist3<maxERR)
        return (dist1+dist2)/2;
    if(dist1<dist2)
        return getDist(x1,y1,(x1+x2)/2,(y1+y2)/2,x3,y3);
    return getDist(x2,y2,(x1+x2)/2,(y1+y2)/2,x3,y3);

}

ll getMinPos(ll maxPos,ll remVal){
    ll total=summation[maxPos];
    ll req=(maxPos+1)*skills[maxPos].first;
    ll ghatti=req-total;
    while(ghatti>remVal&&maxPos>0){
        maxPos--;
        ghatti=(maxPos+1)*skills[maxPos].first-summation[maxPos];
    }
    return maxPos;
}
int main(void){
  

  

    ll test_cases=1;

 

  

    cout << setprecision(15) << fixed;
 

    ll n;
    ll cf,cm,A,m;
   

    for(long t=0;t<test_cases;t++){
        

        cin>>n>>A>>cf>>cm>>m;
        for(long i=0;i<n;i++)
        {
             cin>>skills[i].first;
             skills[i].second=i;
        }

        sort(skills,skills+n);
        summation[0]=skills[0].first;
        for(long i=1;i<n;i++)
            summation[i]=summation[i-1]+skills[i].first;
        long pos=n-1;
        while(pos>=0&&skills[pos].first>=A)
            pos--;
        pos++;
        ll completeSkill=n-pos;
        ll ans=0;
        ll maxpos=n,minpos=0,minskil=skills[0].first;
        long curMinSkillPos=pos-1;
        if(pos==0){
                ans=n*cf+A*cm;
                maxpos=0;

        }
        while(pos>0){

            completeSkill=n-pos;
            curMinSkillPos=getMinPos(min(pos-1,curMinSkillPos),m);

            ll spentMoney=((curMinSkillPos+1)*skills[curMinSkillPos].first)-summation[curMinSkillPos];
            ll curMinSkill=skills[curMinSkillPos].first+((m-spentMoney)/(curMinSkillPos+1));
            if(curMinSkill>A)
                curMinSkill=A;
            if(curMinSkillPos<n-1&&curMinSkill>skills[curMinSkillPos+1].first&&curMinSkillPos+1<pos)
                cout<<curMinSkillPos<<"cmsp\n m"<<m<<"\ncurminskill "<<curMinSkill<<"\nsummation "<<summation[curMinSkillPos]<<"\nnestSkill"<<skills[curMinSkillPos+1].first<<endl;
            ll curAns=(completeSkill*cf)+(cm*curMinSkill);
            if(curAns>ans){
                ans=curAns;
                maxpos=pos;
                minpos=curMinSkillPos;
                minskil=curMinSkill;
            }
            pos--;
            if(pos>=0){
                m-=(A-skills[pos].first);
            }
            if(m<0)
                break;
            else if(pos==0){
                ans=n*cf+A*cm;
                maxpos=0;
            }

        }
        for(long i=0;i<=minpos;i++)
            skills[i].first=minskil;
        for(long i=maxpos;i<n;i++)
            if(skills[i].first<A)
                skills[i].first=A;
        for(long i=0;i<n;i++){
            long temp=skills[i].first;
            skills[i].first=skills[i].second;
            skills[i].second=temp;
        }
        sort(skills,skills+n);
        cout<<ans<<endl;
        for(long i=0;i<n;i++)
            cout<<skills[i].second<<" ";
    }
    return 0;
}

