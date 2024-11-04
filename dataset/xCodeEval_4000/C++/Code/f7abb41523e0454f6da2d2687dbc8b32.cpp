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
#include<map>
#include<queue>
#include<cmath>
#include <time.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define mdlo 1000000007
typedef vector<long> adjList;
adjList Trree[100];
typedef long long ll;
typedef pair<long long,long long>sum;
typedef pair<sum,long long>updat;
long long N;
#define maxBits 40
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
void buildpwr2(long lim){
	pwr2[0]=1;
	for(long i=0;i<lim;i++)
		pwr2[i+1]=pwr2[i]<<1;
}
long long onNthbit(long pos,long val){
	return val|pwr2[pos];
}
bool isNthbitOn(long long pos,long long val){
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
void buildSegmentTree(long long b,long long e,long long node){
    if(b==e)
    {
         segTree[node]=b;
         return;
    }
    long long mid=(b+e)/2;
    buildSegmentTree(b,mid,node*2);
    buildSegmentTree(mid+1,e,1+(node*2));
    if(segTreeData[segTree[node*2]]>segTreeData[segTree[1+(node*2)]])
        segTree[node]=segTree[node*2];
    else
        segTree[node]=segTree[1+(2*node)];
}
void buildMinSegmentTree(long long b,long long e,long long node){
    if(b==e)
    {
         segTree[node]=b;
         return;
    }
    long long mid=(b+e)/2;
    buildMinSegmentTree(b,mid,node*2);
    buildMinSegmentTree(mid+1,e,1+(node*2));
    if(segTreeData[segTree[node*2]]>segTreeData[segTree[1+(node*2)]])
        segTree[node]=segTree[1+(node*2)];
    else
        segTree[node]=segTree[(2*node)];
}
void updateMinSegmentTree(long b,long e,long node,long pos,long val){
    if(b>pos||e<pos)
        return;
    if(b==e){
        segTreeData[pos]=val;
        return;
    }
    long mid=(b+e)/2;
    updateMinSegmentTree(b,mid,node*2,pos,val);
    updateMinSegmentTree(mid+1,e,1+node*2,pos,val);
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
long long getMinFromSegTree(long long qStart,long long qEnd,long long sStart,long long sEnd,long long node){
    if(qEnd<sStart||qStart>sEnd)
        return -1;
    if(sStart>=qStart&&sEnd<=qEnd)
        return segTree[node];
    long long sMid=(sStart+sEnd)/2;
    long long r1=getMinFromSegTree(qStart,qEnd,sStart,sMid,2*node);
    long long r2=getMinFromSegTree(qStart,qEnd,sMid+1,sEnd,1+(2*node));
    if(r2<0)
        return r1;
    if(r1<0||segTreeData[r1]>segTreeData[r2])
        return r2;
    return r1;
}
void buildSumSegmentTree(long b,long e,long node){
    if(b==e){
        sumSegTree[node]=sumSegTreeData[b];
        return;
    }
    long mid=(b+e)/2;
    buildSumSegmentTree(b,mid,node*2);
    buildSumSegmentTree(mid+1,e,1+node*2);
    sumSegTree[node]=sumSegTree[node*2]+sumSegTree[1+(node*2)];
}
void updateSumSegmentTree(long b,long e,long node,long pos,long val){
    if(pos<b||pos>e)
        return;
    if(b==e){
        sumSegTree[node]=val;
        sumSegTreeData[pos]=val;
        return;
    }
    long mid=(b+e)/2;
    updateSumSegmentTree(b,mid,2*node,pos,val);
    updateSumSegmentTree(mid+1,e,1+2*node,pos,val);
    sumSegTree[node]=sumSegTree[node*2]+sumSegTree[1+(node*2)];
}
long getSumFromSegTree(long b,long e,long node,long qStart,long qEnd){
     if(qStart>e||qEnd<b)
        return 0;
     if(b>=qStart&&e<=qEnd)
        return sumSegTree[node];
     long mid=(b+e)/2;
     return getSumFromSegTree(b,mid,node*2,qStart,qEnd)+getSumFromSegTree(mid+1,e,1+2*node,qStart,qEnd);
}
long long getLcm(long long a,long long b){
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
#define MAX(a, b) \
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
void buildRandomTree(adjList tree[],long node){
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
adjList tagTree[200005];
long distFromAlice[200005];
long distFromBob[200005];
long distFromFurthestLeaf[200005];
long parentNode[200005];
int main(void){



	

   

	long test_cases=1;
	pow2[0]=1;
	for(long i=1;i<18;i++)
        pow2[i]=pow2[i-1]*2;
	

	


    cout << fixed<<setprecision(10);
    

    

	for(long T=0;T<test_cases;T++){
	



        long long k,n,x,ans=0,pos,c=0;
        long node1,node2,bobPos;
        cin>>n>>bobPos;
        const int alicePos=1;
        for(long index=1;index<n;index++){
            scanf("%ld%ld",&node1,&node2);
            tagTree[node1].push_back(node2);
            tagTree[node2].push_back(node1);
        }
        stack<long>nodes;
        memset(distFromAlice,-1,sizeof(distFromAlice));
        memset(distFromFurthestLeaf,-1,sizeof(distFromFurthestLeaf));
        memset(distFromBob,-1,sizeof(distFromBob));
        stack<long>leafnodes;
        nodes.push(alicePos);
        distFromAlice[alicePos]=0;
        parentNode[alicePos]=0;

        while(nodes.empty()==false){
            long node=nodes.top();
            if(node<0||node>n){
                cout<<"troublenode"<<node;
                return 0;
            }
            nodes.pop();
            for(long i=0;i<tagTree[node].size();i++){

                long childNode=tagTree[node][i];
            if(childNode<0||childNode>n){
                cout<<"troublechild"<<node;
                return 0;
            }
                if(distFromAlice[childNode]<0){
                    nodes.push(childNode);
                    leafnodes.push(childNode);
                    distFromAlice[childNode]=distFromAlice[node]+1;
                    parentNode[childNode]=node;
                }
            }
            if(tagTree[node].size()==1&&node!=alicePos){

                distFromFurthestLeaf[node]=0;
            }
        }
        if(bobPos==2284335){
            cout<<"290nn\n";
            return 0;
        }

        while(leafnodes.empty()==false){
            long node=leafnodes.top();
            long parent=parentNode[node];
            if(node<0||node>n){
                cout<<"trouble"<<node;
                return 0;
            }

            if(distFromFurthestLeaf[parent]<=distFromFurthestLeaf[node])
                distFromFurthestLeaf[parent]=distFromFurthestLeaf[node]+1;
            leafnodes.pop();
        }
        nodes.push(bobPos);
        distFromBob[bobPos]=0;



        if(bobPos==2284335)
            cout<<"308nn\n";
        while(nodes.empty()==false){
            long node=nodes.top();
            nodes.pop();
            for(long index=0;index<tagTree[node].size();index++){
                long childNode=tagTree[node][index];
                if(distFromBob[childNode]<0){
                    distFromBob[childNode]=distFromBob[node]+1;
                    nodes.push(childNode);
                }
            }
        }

        if(bobPos==2284335)
            cout<<"320nn\n";
        long ind;
        for(long index=1;index<=n;index++){
            if(distFromBob[index]<distFromAlice[index]){
                long duration=distFromAlice[index]+distFromFurthestLeaf[index];
                if(duration>ans){
                    ans=duration;
                    ind=index;
                }
            }
        }
        cout<<ans*2<<endl;
        

        

    }
	return 0;
}



