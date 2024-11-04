
using namespace std;


mt19937 jtrand;

int n,m;
pair<int,int> d[200005],q[200005];

namespace treap{
	int siz,root;
	struct Node{
		int l,r;
		int id,fix;
		int c,cp;
		int v,vp;
	}t[200005];
	int newnode(int ids,int cs){
		siz++;
		t[siz].l=t[siz].r=t[siz].cp=t[siz].vp=t[siz].v=0;
		t[siz].fix=jtrand();
		t[siz].id=ids;
		t[siz].c=cs;
		return siz;
	}
	void addcv(int now,int cs,int vs){
		t[now].c+=cs;
		t[now].cp+=cs;
		t[now].v+=vs;
		t[now].vp+=vs;
	}
	void pushdown(int now){
		if(t[now].l){
			addcv(t[now].l,t[now].cp,t[now].vp);
		}
		if(t[now].r){
			addcv(t[now].r,t[now].cp,t[now].vp);
		}
		t[now].cp=t[now].vp=0;
	}
	void split(int now,int &l,int &r,int val){
		if(now){
			pushdown(now);
		}else{
			l=r=0;
			return;
		}
		if(t[now].c<=val){
			l=now;
			split(t[now].r,t[l].r,r,val);
		}else{
			r=now;
			split(t[now].l,l,t[r].l,val);
		}
	}
	int merge(int x,int y){
		if(x){
			pushdown(x);
		}
		if(y){
			pushdown(y);
		}
		if(!x||!y){
			return x?x:y;
		}else if(t[x].fix<t[y].fix){
			t[x].r=merge(t[x].r,y);
			return x;
		}else{
			t[y].l=merge(x,t[y].l);
			return y;
		}
	}
	void insert(int now){
		int l,r;
		split(root,l,r,t[now].c);
		root=merge(l,now);
		root=merge(root,r);
	}
}

bool id0(pair<int,int> a,pair<int,int> b){
	if(a.second!=b.second){
		return a.second>b.second;
	}else{
		return a.first<b.first;
	}
}

vector<int> trans;

void Trans(int id){
	treap::pushdown(id);
	if(treap::t[id].l){
		Trans(treap::t[id].l);
	}
	trans.push_back(id);
	if(treap::t[id].r){
		Trans(treap::t[id].r);
	}
	treap::t[id].l=treap::t[id].r=0;
}

int ans[200005];

int main(){
	jtrand.seed(114514^time(0)^1919810);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i].first,&d[i].second);
	}
	sort(d+1,d+n+1,id0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&q[i].first);
		q[i].second=i;
	}
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++){
		treap::root=treap::merge(treap::root,treap::newnode(q[i].second,q[i].first));
	}
	for(int i=1;i<=n;i++){
		int cs=d[i].first;
		int ls,ms,rs;
		treap::split(treap::root,ls,ms,cs-1);
		if(ms){
			treap::addcv(ms,-cs,1);
		}
		treap::split(ms,ms,rs,2*cs-1);
		trans.clear();
		Trans(ms);
		treap::root=ls;
		for(int i=0;i<trans.size();i++){
			treap::insert(trans[i]);
		}
		treap::root=treap::merge(treap::root,rs);
	}
	trans.clear();
	Trans(treap::root);
	for(int i=0;i<m;i++){
		ans[treap::t[trans[i]].id]=treap::t[trans[i]].v;
	}
	for(int i=1;i<=m;i++){
		printf("%d%c",ans[i]," \n"[i==m]);
	}
	return 0;
}