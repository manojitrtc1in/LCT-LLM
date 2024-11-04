














using namespace std;







typedef long long ll;
long long mInv[41];
long long fact[41];
long long factInv[41];
map<long,long>id0;
typedef pair<ll,ll>skill;
skill skills[100005];
ll summation[100005];
long long id2(long long n){
    if(n==1)
        return 1;
    if(mInv[n]>0)
        return mInv[n];
    long long m=(-1*mdlo)/n;
    m+=mdlo;
    m*=id2(mdlo%n);
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

ll id1(ll maxPos,ll remVal){
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
        ll maxpos=n,minpos=0,id3=skills[0].first;
        long id5=pos-1;
        if(pos==0){
                ans=n*cf+A*cm;
                maxpos=0;

        }
        while(pos>0){

            completeSkill=n-pos;
            id5=id1(min(pos-1,id5),m);

            ll spentMoney=((id5+1)*skills[id5].first)-summation[id5];
            ll id4=skills[id5].first+((m-spentMoney)/(id5+1));
            if(id4>A)
                id4=A;
            if(id5<n-1&&id4>skills[id5+1].first&&id5+1<pos)
                cout<<id5<<"cmsp\n m"<<m<<"\ncurminskill "<<id4<<"\nsummation "<<summation[id5]<<"\nnestSkill"<<skills[id5+1].first<<endl;
            ll curAns=(completeSkill*cf)+(cm*id4);
            if(curAns>ans){
                ans=curAns;
                maxpos=pos;
                minpos=id5;
                id3=id4;
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
            skills[i].first=id3;
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

