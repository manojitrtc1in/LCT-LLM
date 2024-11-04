

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <typeinfo>
#include <set>
#include <cctype>
#include <locale>
#include <utility>
#include <map>
#include <iterator>
#include <valarray>
#include <complex>
#include <sstream>
#include <bitset>
#include <ctime>
#include <list>
#include <numeric>
#include <cstring>

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second
using namespace std;


typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=2000000000;

int in() {
    int a;
    scanf("%d", &a);
    return a;
}

double din() {
    double a;
    scanf("%lf", &a);
    return a;
}

int gcd(int a, int b) {
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
    

}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

const double eps = 1e-7;





int qq(int a,int b){
    int c=a+b;
    int res=0;
    while(c%10==0){
        ++res;
        c/=10;
    }
    return res;
}
bool isa(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
    else return false;
}
bool isprime(int a){
    for(int i=2;i*i<=a;++i){
        if(a%i==0) return false;
    }
    return true;
}
struct Node{
    Node *l, *r,*p;
    int x,y;

    vector <Node*> a;
    vector <char> u;
    Node* use(){
        if(u.empty()) u.assign(a.size(),0);
        for(int i=0;i<u.size();++i){
            if(!u[i]){
                u[i]=1;
                return a[i];
            }
        }
        return NULL;
    }
    Node(){

    }

    Node(int xx,int yy){
        x=xx;
        y=yy;
        l=NULL;
        r=NULL;
        p=NULL;
    }
    Node(int xx,int yy,Node *pp){
        x=xx;
        y=yy;
        p=pp;
        l=NULL;
        r=NULL;
    }
    void setp(Node *pp){
        p=pp;
    }
};

class Treap{
private:
    Node *root,*l;
    void insert(Node *&r,Node *a){
        if(r==NULL){
            r=a;
            return;
        }
        

        if(a->y < r->y){
            split(r,a->x,a->l,a->r);
            r=a;
        }else{
            if(a->x < r->x) insert(r->l,a);
            else insert(r->r,a);
        }
    }
    void split(Node *a,int X,Node *&l,Node *&r){
        if(a==NULL){
            l=r=NULL;
            return;
        }
        if(a->x > X){
            split(a->l,X,l,a->l);
            r=a;
        }else{
            split(a->r,X,a->r,r);
            l=a;
        }

    }
    void built(Node *r,Node *t){
        while(r->y > t->y && r->p!=NULL){
            r=r->p;
        }
        if(r->p==NULL && t->y < r->y){
            r->p=t;
            t->l=r;
            root=t;
            root->p=NULL;
            l=t;
            return;
        }
        t->l=r->r;
        r->r=t;
        t->p=r;
        t->l->p=t;
        l=t;
    }

public:
    Treap(){
        root=NULL;
        l=NULL;
    }
    void built(pair<int,int> a){
        Node *n=new Node(a.first,a.second);
        if(root==NULL){
            root=n;
            l=n;
            return;
        }
        

        if(l->y < n->y){
            l->r=n;
            n->p=l;
            l=n;
            return;
        }
        built(l,n);
    }

    void insert(pair<int,int> a){
        Node *node=new Node(a.first,a.second);
        insert(root,node);
    }
    Node* getRoot(){
        return root;
    }
};

struct nod{
    nod *l,*r;
    long long sum;
};
int min(int x,int y){
    return y ^ ((x ^ y) & -(x < y));
}
int max(int x,int y){
    return x ^ ((x ^ y) & -(x < y));
}

string tos(int a){
    string r="";
    while(a>0){
        r+=a%10+'0';
        a/=10;
        

    }
    reverse(all(r));
    return r;
}

string ma(string a){
    string r="";
    for(int i=0;i<a.size();++i){
        if(a[i]=='4' ||a[i]=='7') r+=a[i];
    }
    return r;
}
bool com(pair<double,int> a,pair<double,int> b){
    if (fabs(a.first-b.first)<=eps) return a.second<b.second;
    else return a.first>b.first;
}
long double nextApproximation(long double x){
    return x-(3*x+cos(x)+1)/(3-sin(x));
}
bool exit(){
    exit(0);
}



struct state{
    int link,len;
    map<char,int> next;
};


vector<vector<int> > gg;
map<int,int> m;
vector<char> u;
bool dfs(int v,int f){
    u[v]=1;
    if(v==f) return true;
    

    for(int i=0;i<gg[v].size();++i){
        if(!u[gg[v][i]] && dfs(gg[v][i],f)){
            cout<<m[gg[v][i]]<<' ';
            return 1;
        }
    }
    return 0;
}



map<char,int> mau;
int aa(string a,int p){
    int res=0;
    int po=1;
    for(int i=a.size ()-1;i>=0;--i,po*=p){
        res+=po*mau[a[i]];
    }
    return res;
}


vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}
bool com(pair<int,int> a,pair<int,int> b){
    if(a.second>b.second) return 1;
    if(a.second<b.second) return 0;
    return a.first>b.first;
}
vector<vector<int> > g;
unsigned long long p=1000000007;
unsigned long long mod=909090909090909091ll;

long long hashu(int i){
    unsigned long long h=0ll;
    unsigned long  long pw=1;
    for(int k=0;k<g[i].size();++k){
        h+=pw*g[i][k];
        pw*=p;
        h%=mod;
        pw%=mod;
    }
    for(int j=0;j<g[i].size();++j) cout<<g[i][j]<<' ';


    cout<<endl;
    

    return h;
}

class sNode{
public:
    int value, key,height;
    sNode* left;
    sNode* right;
    sNode* parent;
    sNode(int _key, int _value){
        key = _key;
        value = _value;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};


class bst{
public:
    sNode* root;
    int height;
    bst(){
        root = NULL;
    }
    void add(int _key, int _value){
        

        if (root == NULL){
            root = new sNode(_key, _value);
            

        }
        else{
            addNode(root, new sNode(_key, _value));
        }
    }
    int find(int _key){
        

        sNode* res = findNode(root, _key);
        if ( res != NULL)
            return res->value;
        else {
            return -1;
        }

    }

private:

    void addNode(sNode* &cur, sNode* x, int deep = 0){

        if (cur == NULL){
            cur = x;
            

            height = max(deep,height);
            return;
        }
        if(x->key < cur->key){
            

            addNode(cur->left, x,++deep);
        }
        if(x->key > cur->key){
            

            addNode(cur->right, x,++deep);
        }
    }

    sNode* findNode(sNode* cur, int _key){
        if (cur == NULL){
            return NULL;
        }
        if(_key == cur->key){
            return cur;
        }
        if(_key < cur->key){
            findNode(cur->left,_key);
        }
        else{
            findNode(cur->right,_key);
        }
    }
};

int logbin(int a){
    int c=1;
    while(c<a) c<<=1;
    return c;
}

vector<int>  b,de;
void update(int v,int l,int r,int tl,int tr,int d){
    if(r<l) return ;
    if(l==tl && r==tr){
        de[v]+=d;
        return;
    }
    int tm=(tr+tl)/2;
    update(v<<1,l,min(r,tm),tl,tm,d);
    update((v<<1)+1,max(l,tm+1),r,tm+1,tr,d);
    b[v]=max(b[v<<1]+de[v<<1],b[(v<<1)+1]+de[(v<<1)+1]);
}
int getsum(int v,int l,int r,int tl,int tr){
    if(r<l) return 0;
    if(l==tl && r==tr){
        return b[v]+de[v];
    }
    int tm=(tr+tl)/2;
    return max(getsum(v<<1,l,min(r,tm),tl,tm) ,getsum((v<<1)+1,max(l,tm+1),r,tm+1,tr)) + de[v];
}

int main(){
   

    

    

    int n=in(),m=in(),x=in(),y=in();
    vector<pair<pair<int,int> ,int> > mas;
    for(int i=0;i<n;++i){
        int tt=in();
        mas.push_back (make_pair(make_pair(tt-x,tt+y),i));
    }
    set<pair<int,int> > p;
    for(int i=0;i<m;++i){
        int tt=in();
        p.insert (make_pair(tt,i));
    }
    vector<pair<int,int> > ans;
    sort(all(mas));
    int c=0;
    for(int i=0;i<n;++i){
        auto it=p.lower_bound (make_pair(mas[i].first.first,-1));
        if(it==p.end () || (*it).first>mas[i].first.second) continue;
        ++c;
        ans.push_back(make_pair(mas[i].second,(*it).second));
        p.erase (it);
    }
    cout<<ans.size ()<<endl;
    for(int i=0;i<ans.size ();++i) cout<<ans[i].first+1<<' '<<ans[i].second+1<<endl;

    return 0;

}



