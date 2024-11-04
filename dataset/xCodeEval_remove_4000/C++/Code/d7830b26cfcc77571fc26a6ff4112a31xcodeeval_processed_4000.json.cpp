













using namespace std;


typedef vector<long> adjList;
adjList Trree[100];
typedef long long ll;
typedef pair<long long,long long>sum;
typedef pair<sum,long long>updat;
long long N;

typedef map<long long,long long>cnts;
cnts counts1[30];
cnts counts2[30];
long long pwr2[100];
long parent[1010];
long getParent(long node){
    if(parent[node]!=node)
        parent[node]=getParent(parent[node]);
    return parent[node];
}
void unionNode(long node1,long node2){
    if(getParent(node1)!=getParent(node2)){
        parent[parent[node1]]=parent[node2];
    }
}
void id11(long lim){
	pwr2[0]=1;
	for(long i=0;i<lim;i++)
		pwr2[i+1]=pwr2[i]<<1;
}
long long id0(long pos,long val){
	return val|pwr2[pos];
}
bool id1(long long pos,long long val){
	return (val&pwr2[pos])>0;
}
long long gcd(long long a,long long b){
    long long c;
    c=b%a;
    while(c>0){
        b=a;
        a=c;
        c=b%a;
    }
    return a;
}
string s;
long long target,sticker;
long segTree[600005];
long segTreeData[100005];
long sumSegTree[600005];
long sumSegTreeData[100005];
long minStart[2];
long minEnd[2];
void id7(long long b,long long e,long long node){
    if(b==e)
    {
         segTree[node]=b;
         return;
    }
    long long mid=(b+e)/2;
    id7(b,mid,node*2);
    id7(mid+1,e,1+(node*2));
    if(segTreeData[segTree[node*2]]>segTreeData[segTree[1+(node*2)]])
        segTree[node]=segTree[node*2];
    else
        segTree[node]=segTree[1+(2*node)];
}
void id10(long long b,long long e,long long node){
    if(b==e)
    {
         segTree[node]=b;
         return;
    }
    long long mid=(b+e)/2;
    id10(b,mid,node*2);
    id10(mid+1,e,1+(node*2));
    if(segTreeData[segTree[node*2]]>segTreeData[segTree[1+(node*2)]])
        segTree[node]=segTree[1+(node*2)];
    else
        segTree[node]=segTree[(2*node)];
}
void id3(long b,long e,long node,long pos,long val){
    if(b>pos||e<pos)
        return;
    if(b==e){
        segTreeData[pos]=val;
        return;
    }
    long mid=(b+e)/2;
    id3(b,mid,node*2,pos,val);
    id3(mid+1,e,1+node*2,pos,val);
    if(segTreeData[segTree[node*2]]>segTreeData[segTree[1+node*2]])
        segTree[node]=segTree[1+2*node];
    else
        segTree[node]=segTree[2*node];
}
long long getMax(long long qStart,long long qEnd,long long sStart,long long sEnd,long long node){
    if(qEnd<sStart||qStart>sEnd)
        return -1;
    if(sStart>=qStart&&sEnd<=qEnd)
        return segTree[node];
    long long sMid=(sStart+sEnd)/2;
    long long r1=getMax(qStart,qEnd,sStart,sMid,2*node);
    long long r2=getMax(qStart,qEnd,sMid+1,sEnd,1+(2*node));
    if(r1<0)
        return r2;
    if(r2<0||segTreeData[r1]>segTreeData[r2])
        return r1;
    return r2;
}
long long id5(long long qStart,long long qEnd,long long sStart,long long sEnd,long long node){
    if(qEnd<sStart||qStart>sEnd)
        return -1;
    if(sStart>=qStart&&sEnd<=qEnd)
        return segTree[node];
    long long sMid=(sStart+sEnd)/2;
    long long r1=id5(qStart,qEnd,sStart,sMid,2*node);
    long long r2=id5(qStart,qEnd,sMid+1,sEnd,1+(2*node));
    if(r2<0)
        return r1;
    if(r1<0||segTreeData[r1]>segTreeData[r2])
        return r2;
    return r1;
}
void id8(long b,long e,long node){
    if(b==e){
        sumSegTree[node]=sumSegTreeData[b];
        return;
    }
    long mid=(b+e)/2;
    id8(b,mid,node*2);
    id8(mid+1,e,1+node*2);
    sumSegTree[node]=sumSegTree[node*2]+sumSegTree[1+(node*2)];
}
void id9(long b,long e,long node,long pos,long val){
    if(pos<b||pos>e)
        return;
    if(b==e){
        sumSegTree[node]=val;
        sumSegTreeData[pos]=val;
        return;
    }
    long mid=(b+e)/2;
    id9(b,mid,2*node,pos,val);
    id9(mid+1,e,1+2*node,pos,val);
    sumSegTree[node]=sumSegTree[node*2]+sumSegTree[1+(node*2)];
}
long id6(long b,long e,long node,long qStart,long qEnd){
     if(qStart>e||qEnd<b)
        return 0;
     if(b>=qStart&&e<=qEnd)
        return sumSegTree[node];
     long mid=(b+e)/2;
     return id6(b,mid,node*2,qStart,qEnd)+id6(mid+1,e,1+2*node,qStart,qEnd);
}
long long id2(long long a,long long b){
    long long c=a/gcd(a,b);
    return b*c;
}
long long pow10[18];
long long pow2[18];
long getlen(long long num){
    long len=1;
    while(num>9){
        num/=10;
        len++;
    }
    return len;
}
void test(long a){
    switch(a){
    case 1:
        cout<<1;
    case 2:
        cout<<2;
        break;
    case 3:
        cout<<3;
    case 4:
        cout<<4;


    case 5:
        cout<<5;
    default:
        cout<<0;
    }
    cout<<endl;
}

    a > b ? a : b
struct base {
    virtual ~base() =default;
    virtual void f(char const* lable = "bd") const{
    std::cout<<lable <<":base\n";
    }
};
struct derived :base{
    void f(char const * lable="dd") const{
        std::cout<<lable<<":derived";
    }
};
void id4(adjList tree[],long node){
    long ancestor[100];
    for(long i=0;i<100;i++){
        ancestor[i]=i;
    }
    srand((unsigned)time(0));
    for(long i=1;i<node;i++){

    int node1 = rand();
    int node2 = rand();
    int par1=node1,par2=node2;
    while(ancestor[par1]!=par1)
        par1=ancestor[par1];
    }
}
int main(void){



	

   

	long test_cases=1;
	pow2[0]=1;
	for(long i=1;i<18;i++)
        pow2[i]=pow2[i-1]*2;
	

	


    cout << fixed<<setprecision(10);
    

    

	for(long T=0;T<test_cases;T++){
	



        string s,t;
        string m1,m2;
        long long k,n,m,p;
        cin>>n>>k;
        long long bamboo[111];
        for(long i=0;i<n;i++){
            cin>>bamboo[i];
        }
        sort(bamboo,bamboo+n);
        ll bambooSum[111];
        bambooSum[0]=bamboo[0];
        long maxval=0;
        for(long i=1;i<n;i++){
            bambooSum[i]=bamboo[i]+bambooSum[i-1];
            m=i*bamboo[i]-bambooSum[i-1];
            if(m>k&&maxval==0){
                maxval=bamboo[i];
                

            }
        }
        if(maxval==0){
            ll remaining=k+bambooSum[n-1]-(n*bamboo[n-1]);
            cout<<(remaining/n)+bamboo[n-1];
            return 0;
        }
        set<ll>candidatePoints;

        for(long i=0;i<n;i++){
            bambooSum[i]+=k;
            long lim=1+sqrt(bamboo[i]+1);
            for(long j=1;j<lim;j++){
                long long r1=bamboo[i]/j,r2=j;
                if(r1<maxval){
                    if(r1*j==bamboo[i])
                        candidatePoints.insert(r1);
                    else
                        candidatePoints.insert(r1+1);
                }
            }
        }
        long lim=sqrt(bamboo[n-1]);
        if(lim>maxval)
            lim=maxval;
        for(long i=1;i<lim;i++)
            candidatePoints.insert(i);
        set<ll>::reverse_iterator rit=candidatePoints.rbegin();
        while(rit!=candidatePoints.rend()){
            ll cp=*rit;
            ll total=0,d1,flag=1;
            for(long i=0;i<n;i++){
                d1=(bamboo[i]+cp-1)/cp;
                total+=(d1*cp);
                if(total>bambooSum[i]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                long dv=0;
                for(long i=0;i<n;i++)
                    dv+=(bamboo[i]+cp-1)/cp;
                cout<<cp+(bambooSum[n-1]-total)/dv;
                return 0;
            }
            rit++;
        }
        cout<<1;
        

        

    }
	return 0;
}



