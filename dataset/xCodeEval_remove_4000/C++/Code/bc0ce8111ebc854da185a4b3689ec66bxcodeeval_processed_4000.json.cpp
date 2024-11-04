












using namespace std;


class BitVector{
    struct Node{
        int height;
        Node *left,*right;
        int size;
        int index,added;

        
        Node(int k)
            :height(1),index(k),added(0),left(0),right(0),size(1){}
        ~Node(){
            if(left)delete left;
            if(right)delete right;
        }
        Node *rotate_right(){
            Node *s=left;
            int b=s->added,d=added;
            s->added += d;
            if(s->right)s->right->added += b;
            added += -b-d;
            left=s->right;
            s->right=this;
            return s;
        }
        Node *rotate_left(){
            Node *s=right;
            int b=s->added,d=added;
            s->added += d;
            if(s->left)s->left->added += b;
            added += -b-d;
            right=s->left;
            s->left=this;
            return s;
        }
        Node *insert(int k){
            if(!this)return new Node(k);
            k-=added;
            if(k < index){
                left = left->insert(k);
            }else {

                right = right->insert(k);
            }
            return balance();
        }
        bool find(int k){
            if(!this)return false;
            k-=added;
            return k==index?
                true:k<index?left->find(k):right->find(k);
        }
        Node *erase(int k){
            if(!this)return NULL;
            k-=added;
            if(k==index){
                int a=added;
                Node *le=left,*ri=right;
                left=right=NULL;
                delete this;
                if(!le){
                    if(ri)ri->added+=a;
                    return ri;
                }
                if(!ri){
                    if(le)le->added+=a;
                    return le;
                }
                Node *t;
                le = le->erase_max(&t,a,a);
                t->left = le;
                t->right = ri;
                return t->balance();
            }
            if(k < index){
                left = left->erase(k);
            }else if(index < k){
                right = right->erase(k);
            }
            return balance();
        }
        void add_ge(int k,int v){
            if(!this)return;
            k-=added;
            if(k <= index){
                added += v;
                if(left){
                    left->added -= v;
                    left->add_ge(k-v ,v);
                }
            }else{
                right->add_ge(k,v);
            }
        }
        int rank_le(int k)const{
            if(!this)return 0;
            k-=added;
            if(k==index){
                return 1+(left?left->size:0);
            }else if(k<index){
                return left->rank_le(k);
            }else{
                return 1 + (left?left->size:0) + right->rank_le(k);
            }
        }
        int select1(int k,int a)const{
            if(!this)return -1;
            a+=added;
            if((left?left->size:0)==k)return index+a;
            if(left && k<=left->size){
                return left->select1(k,a);
            }else {
                if(left)k-=left->size;
                k--;
                return right->select1(k,a);
            }
        }
        int select0(int k,int a,int lb)const{
            if(!this)return k;
            a+=added;
            int x = index+a-lb-(left?left->size:0);
            if(k<x){
                if(left)return left->select0(k,a,lb);
                else return lb+k;
            }else{
                if(right)return right->select0(k-x,a,index+a+1);
                else return index+a+1+k-x;
            }
        }

        Node *balance(){
            int bf = (right?right->height:0)-(left?left->height:0);
            if(2==bf){
                Node *t=right;
                if((t->right?t->right->height:0) < (t->left?t->left->height:0)){
                    right = t->rotate_right();
                }
                return rotate_left()->update();
            }else if(bf==-2){
                Node *t=left;
                if((t->right?t->right->height:0) > (t->left?t->left->height:0)){
                    left = t->rotate_left();
                }
                return rotate_right()->update();
            }
            updates();
            return this;
        }
        Node *update(){
            if(left)left->updates();
            if(right)right->updates();
            updates();
            return this;
        }
        void updates(){
            update_height();
            update_size();
        }
        void update_height(){
            if(!this)return;
            if(right){
                if(left && right->height < left->height)height=left->height+1;
                else height=right->height+1;
            }else if(left)height=left->height+1;
            else height=1;
        }
        void update_size(){
            if(!this)return;
            size = 1 + (left?left->size:0) + (right?right->size:0);
        }
        Node* erase_max(Node **maxnode,int add,int s){
            s += added;
            if(right){
                right = right->erase_max(maxnode,add,s);
                return balance();
            }else{
                *maxnode=this;
                if(left)left->added += added;
                index = index+s-add;
                added = add;
                return left;
            }
        }
    } *root;
public:
    BitVector():root(0){}
    ~BitVector(){if(root)delete root;}
    void insert(int k,int v){
        root->add_ge(k,1);
        if(v==1)root=root->insert(k);
    }
    void erase(int k){
        root=root->erase(k);    
        root->add_ge(k,-1);
    }
    int access(int n)const{
        return root->find(n)?1:0;
    }
    int rank(int k)const{

        return root->rank_le(k);
    }
    int rank()const{
        return root?root->size:0;
    }
    int select1(int k)const{return root->select1(k-1,0);}
    int select0(int k)const{return root->select0(k-1,0,0);}
};










class id0{
    typedef int Val;
    static const Val NIL=-1;
    static const int BITLEN = 20;
    int len;
    BitVector bv[BITLEN];
    int encode(Val c)const{
        return c;
    }
    Val decode(int n)const{
        return n;
    }
    struct Node{
        int height,s,e,code;
        Node(){}
        Node(int a,int b,int c,int d):height(a),s(b),e(c),code(d){};
        bool operator <(Node a)const{return e-s<a.e-a.s;}
    };
public:
    int length()const{
        return len;
    }
    id0():len(0){
    }
    id0(const vector<Val> &str){
        init(str);
    }
    

    void init(const vector<Val> &str){
        len = str.size();
        int *bucket;
        bucket = new int[2*len];
        int *cur,*next;
        cur = bucket;
        next = bucket+len;
        int rank0[BITLEN]={0};
        for(int i=0;i<len;i++){
            int n = encode(str[i]);
            cur[i] = n;
            for(int j=BITLEN-1;j>=0;j--){
                if((n&1<<j)==0)rank0[j]++;
            }
        }
        for(int i=BITLEN-1;;i--){
            for(int j=0;j<len;j++){
                if(cur[j]&1<<i)bv[i].insert(j,1);
            }
            if(i==0)break;
            int idx0=0,idx1=rank0[i];
            for(int j=0;j<len;j++){
                if(cur[j]&1<<i)next[idx1++]=cur[j];
                else next[idx0++]=cur[j];
            }
            swap(cur,next);
        }
        delete[] bucket;
    }
    

    Val access(int k)const{
        int code=0;
        for(int i=BITLEN-1;i>0;i--){
            if(bv[i].access(k)){
                code |= 1<<i;
                k = len-bv[i].rank()+bv[i].rank(k)-1;
            }else{
                k = k-bv[i].rank(k);
            }
        }
        if(bv[0].access(k))code |= 1;
        return decode(code);
    }
    

    

    int rank(int s,int e,Val c)const{
        int n = encode(c);
        for(int i=BITLEN-1;i>=0;i--){
            int ssum = bv[i].rank(s-1);
            int esum = bv[i].rank(e-1);
            if(n&1<<i){
                s = len-bv[i].rank() + ssum;
                e = s + esum-ssum;
            }else{
                s = s-ssum;
                e = e-esum;
            }
        }
        return e-s;
    }
    

    

    int select(Val c,int k)const{
        int n = encode(c);
        int s=0,e=len;
        for(int i=BITLEN-1;i>=0;i--){
            int ssum = bv[i].rank(s-1);
            int esum = bv[i].rank(e-1);
            if(n&1<<i){
                s = len-bv[i].rank() + ssum;
                e = s + esum-ssum;
            }else{
                s = s-ssum;
                e = e-esum;
            }
        }
        int p = s+k;
        if(e<=p)return NIL;
        for(int i=0;i<BITLEN;i++){
            if(n&1<<i)p = bv[i].select1(p-(len-bv[i].rank())+1);
            else p = bv[i].select0(p+1);
        }
        return p;
    }
    

    

    vector<pair<Val,int> > topk(int s,int e,int k)const{
        vector<pair<Val,int> > res;
        priority_queue<Node> pq;
        pq.push(Node(BITLEN-1,s,e,0));
        while(!pq.empty() && 0<=k){
            Node a = pq.top();
            pq.pop();
            if(a.height==-1){
                res.push_back(make_pair(decode(a.code),a.e-a.s));
                k--;
                continue;
            }
            int ssum = bv[a.height].rank(a.s-1);
            int esum = bv[a.height].rank(a.e-1);
            int num1 = esum-ssum;
            int num0 = a.e-a.s-num1;
            int s = a.s-ssum;
            pq.push(Node(a.height-1,s,s+num0,a.code));
            s = len-bv[a.height].rank() + ssum;
            pq.push(Node(a.height-1,s,s+num1,a.code|1<<a.height));
        }
        return res;
    }
    

    

    Val quantile(int s,int e,int r)const{
        int code=0;
        for(int i=BITLEN-1;i>=0;i--){
            int ssum = bv[i].rank(s-1);
            int esum = bv[i].rank(e-1);
            int num1 = esum-ssum;
            if(num1<=r){
                r -= num1;
                s = s-ssum;
                e = e-esum;
            }else{
                code |= 1<<i;
                s = len-bv[i].rank() + ssum;
                e = s + num1;
            }
            if(s==e)return NIL;
        }
        return decode(code);
    }
    

    int rank_lt(int s,int e,Val x)const{
        int n = encode(x);
        int res=0;
        for(int i=BITLEN-1;i>=0;i--){
            int ssum = bv[i].rank(s-1);
            int esum = bv[i].rank(e-1);
            if(n&1<<i){
                res += e-s-(esum-ssum);
                s = len-bv[i].rank() + ssum;
                e = s + esum-ssum;
            }else{
                s = s-ssum;
                e = e-esum;
            }
            if(s==e)return res;
        }
        return res;
    }
    

    

    int rangefreq(int s,int e,Val x,Val y)const{
        return rank_lt(s,e,y)-rank_lt(s,e,x);
    }
    

    

    vector<pair<Val,int> > rangemaxk(int s,int e,int k)const{
        Node sta[BITLEN+1];
        int sp=0;
        vector<pair<Val,int> > res;
        sta[sp++] = Node(BITLEN-1,s,e,0);
        while(sp && 0<=k){
            Node a = sta[--sp];
            if(a.height==-1){
                res.push_back(make_pair(decode(a.code),a.e-a.s));
                k--;
                continue;
            }
            int ssum = bv[a.height].rank(a.s-1);
            int esum = bv[a.height].rank(a.e-1);
            int num1 = esum-ssum;
            int num0 = a.e-a.s-num1;
            int s = a.s-ssum;
            if(num0)sta[sp++] = Node(a.height-1,s,s+num0,a.code);
            s = len-bv[a.height].rank() + ssum;
            if(num1)sta[sp++] = Node(a.height-1,s,s+num1,a.code|1<<a.height);
        }
        return res;
    }
    

    

    vector<pair<Val,int> > rangemink(int s,int e,int k)const{
        Node sta[BITLEN+1];
        int sp=0;
        vector<pair<Val,int> > res;
        sta[sp++] = Node(BITLEN-1,s,e,0);
        while(sp && 0<=k){
            Node a = sta[--sp];
            if(a.height==-1){
                res.push_back(make_pair(decode(a.code),a.e-a.s));
                k--;
                continue;
            }
            int ssum = bv[a.height].rank(a.s-1);
            int esum = bv[a.height].rank(a.e-1);
            int num1 = esum-ssum;
            int num0 = a.e-a.s-num1;
            int s = len-bv[a.height].rank() + ssum;
            if(num1)sta[sp++] = Node(a.height-1,s,s+num1,a.code|1<<a.height);
            s = a.s-ssum;
            if(num0)sta[sp++] = Node(a.height-1,s,s+num0,a.code);
        }
        return res;
    }
    

    

    vector<pair<Val,int> > rangelist(int s,int e,Val x,Val y)const{
        int ub = encode(y);
        int lb = encode(x);
        Node sta[BITLEN+1];
        int sp=0;
        vector<pair<Val,int> > res;
        sta[sp++] = Node(BITLEN-1,0,len,0);
        while(sp){
            Node a = sta[--sp];
            if(a.height==-1){
                res.push_back(make_pair(decode(a.code),a.e-a.s));
                continue;
            }
            int ssum = bv[a.height].rank(a.s-1);
            int esum = bv[a.height].rank(a.e-1);
            int num1 = esum-ssum;
            int num0 = a.e-a.s-num1;
            int s = len-bv[a.height].rank() + ssum;
            if((a.code|1<<a.height)<ub && num1)sta[sp++] = Node(a.height-1,s,s+num1,a.code|1<<a.height);
            s = a.s-ssum;
            if(lb<=(a.code) && num0)sta[sp++] = Node(a.height-1,s,s+num0,a.code);
        }
        return res;
    }
    

    

    Val nextvalue(int s,int e,Val x,Val y)const{
        int lb = encode(x);
        int ub = encode(y)-1;
        Node a(-1,-1,-1,-1);
        for(int i=BITLEN-1;i>=0;i--){
            int ssum = bv[i].rank(s-1);
            int esum = bv[i].rank(e-1);
            int num1 = esum-ssum;
            if(lb&1<<i){
                s = len-bv[i].rank() + ssum;
                e = s + esum-ssum;
            }else{
                if(num1){
                    int s1 = len-bv[i].rank() + ssum;
                    int e1 = s1 + esum-ssum;
                    a = Node(i-1,s1,e1,lb&~((1<<i)-1)|1<<i);
                }
                s = s-ssum;
                e = e-esum;
            }
            if(s==e)break;
            if(i==0)return decode(lb);
        }
        if(a.code==-1)return NIL;
        for(;a.height>=0;a.height--){
            int ssum = a.s?bv[a.height].rank(a.s-1):0;
            int esum = bv[a.height].rank(a.e-1);
            int num1 = esum-ssum;
            int num0 = a.e-a.s-num1;
            int s0 = a.s-ssum;
            int s1 = len-bv[a.height].rank(len-1) + ssum;
            if(num0){
                a.s=s0;
                a.e=s0+num0;
            }else{
                a.s=s1;
                a.e=s1+num1;
                a.code|=1<<a.height;
            }
        }
        return decode(a.code);
    }
    

    

    Val prevvalue(int s,int e,Val x,Val y)const{
        int lb = encode(x);
        int ub = encode(y)-1;
        Node a(-1,-1,-1,-1);
        for(int i=BITLEN-1;i>=0;i--){
            int ssum = bv[i].rank(s-1);
            int esum = bv[i].rank(e-1);
            int num1 = esum-ssum;
            int num0 = e-s-num1;
            if(ub&1<<i){
                if(num0){
                    a = Node(i-1,s-ssum,e-esum,ub&~((1<<i)-1)&~(1<<i));
                }
                s = len-bv[i].rank() + ssum;
                e = s + esum-ssum;
            }else{
                s = s-ssum;
                e = e-esum;
            }
            if(s==e)break;
            if(i==0)return decode(ub);
        }
        if(a.code==-1)return NIL;
        for(;a.height>=0;a.height--){
            int ssum = bv[a.height].rank(a.s-1);
            int esum = bv[a.height].rank(a.e-1);
            int num1 = esum-ssum;
            int num0 = a.e-a.s-num1;
            int s0 = a.s-ssum;
            int s1 = len-bv[a.height].rank() + ssum;
            if(num1){
                a.s=s1;
                a.e=s1+num1;
                a.code|=1<<a.height;
            }else{
                a.s=s0;
                a.e=s0+num0;
            }
        }
        return decode(a.code);
    }
    

    

    

    
    void insert(int k,Val c){
        int n = encode(c);
        for(int i=BITLEN-1;i>=0;i--){
            int sum = bv[i].rank(k-1);
            int prev=k;
            if(n&1<<i){
                k = len-bv[i].rank() + sum;
                bv[i].insert(prev,1);           
            }else{
                k = k-sum;
                bv[i].insert(prev,0);   
            }
        }
        len++;
    }
    void erase(int k){
        for(int i=BITLEN-1;i>=0;i--){
            int prev=k;
            if(bv[i].access(k)){
                k = len-bv[i].rank()+bv[i].rank(k-1);
            }else{
                k = k-bv[i].rank(k-1);
            }
            bv[i].erase(prev);
        }
        len--;
    }
};



int a[100000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n;
    rep(i,n)cin>>a[i];
    id0 wm(vector<int>(a,a+n));
    cin>>q;
    int lastans=0;
    rep(i,q){
        int t,l,r,k;
        cin>>t>>l>>r;
        l=(l+lastans-1)%n;
        r=(r+lastans-1)%n;
        if(r<l)swap(l,r);
        if(t==1){
            int v=wm.access(r);
            wm.erase(r);
            wm.insert(l,v);
        }else{
            cin>>k;
            k=(k+lastans-1)%n+1;
            lastans=wm.rank(l,r+1,k);
            cout<<lastans<<endl;
        }
    }
    return 0;
}