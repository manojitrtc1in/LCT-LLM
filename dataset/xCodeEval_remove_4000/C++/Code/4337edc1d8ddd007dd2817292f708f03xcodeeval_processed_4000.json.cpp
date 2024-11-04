












unsigned int id0(unsigned int n)
{
    unsigned int m=0;
    while(n>>=1)
        m++;
    if(n==(1<<m))
        return n;
    return 1<<(m+1);
}

template<typename T>
struct plus_t
{
    T operator()(const T&a,const T&b) const
    {
        return a+b;
    }
    inline static T neutral=T();
};


template<typename T>
struct max_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::max(a,b);
    }
    inline static T neutral=T();
};

template<typename T>
struct min_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::min(a,b);
    }
    inline static T neutral=T();
};


template<typename T>
struct multiplies_t
{
    T operator()(const T&a,const T&b) const
    {
        return a*b;
    }
    inline static T neutral=T(1);
};

template<typename T>
struct gcd_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::gcd(a,b);
    }
    inline static T neutral=T();
};


template<typename T>
struct lcm_t
{
    T operator()(const T&a,const T&b) const
    {
        return std::lcm(a,b);
    }
    inline static T neutral=T(1);
};


template<typename T,typename V,typename S>
struct statistic_node;

template<typename T,typename V,typename S>
struct statistic_node
{
    T v;
    int h;
    V data;
    S statistic;
    statistic_node *left,*right,*parent;
    void update()
    {
        h=std::max(left?left->h:0,right?right->h:0)+1;
        S::update(this);
    }
};

template<typename T,typename V,typename S>
int height(statistic_node<T,V,S>*node)
{
    return node?node->h:0;
}

template<typename T,typename V,typename S>
int balance(statistic_node<T,V,S>* tree)
{
    return height(tree->left)-height(tree->right);
}

template<typename T,typename V,typename S>
statistic_node<T,V,S>* upper_bound(statistic_node<T,V,S>* tree,T v)
{
    if(tree==nullptr)
        return nullptr;
    if(tree->v<=v)
        return upper_bound(tree->right,v);
    else
    {
        auto w=upper_bound(tree->left,v);
        if(w==nullptr)
            return tree;
        return w;
    }
}

template<typename T,typename V,typename S>
statistic_node<T,V,S>* lower_bound(statistic_node<T,V,S>* tree,T v)
{
    if(tree==nullptr)
        return nullptr;
    if(tree->v<v)
        return lower_bound(tree->right,v);
    else
    {
        auto w=lower_bound(tree->left,v);
        if(w==nullptr)
            return tree;
        return w;
    }
}

template<typename T,typename V,typename S>
statistic_node<T,V,S>* id3(statistic_node<T,V,S>* x)
{
    auto y=x->left,A=y->left,B=y->right,C=x->right;
    y->right=x;
    y->parent=x->parent;
    if(x->parent)
    {
        if(x->parent->left==x)
            x->parent->left=y;
        else x->parent->right=y;
    }
    x->parent=y;
    x->left=B;
    if(B) B->parent=x;
    x->update();
    return y;
}

template<typename T,typename V,typename S>
statistic_node<T,V,S>* id4(statistic_node<T,V,S>* x)
{
    auto y=x->right,A=y->right,B=y->left,C=x->left;
    y->left=x;
    y->parent=x->parent;
    if(x->parent)
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else x->parent->right = y;
    }
    x->parent=y;
    x->right=B;
    if(B) B->parent=x;
    x->update();
    return y;
}

template<typename T,typename V,typename S>
statistic_node<T,V,S>* rebalance(statistic_node<T,V,S>* x)
{
    if(balance(x)<-1)
    {
        if(balance(x->right)==1)
            id3(x->right);
        x=id4(x);
    }
    else if(balance(x)>1)
    {
        if(balance(x->left)==-1)
            id4(x->left);
        x=id3(x);
    }
    x->update();
    if(!x->parent)
        return x;
    return rebalance(x->parent);
}

template<typename T,typename V,typename S>
statistic_node<T,V,S>* insert(statistic_node<T,V,S>* tree,T v,V data)
{
    if(!tree)
    {
        tree = new statistic_node<T,V,S>;
        tree->v=v;
        tree->data=data;
        tree->h=1;
        tree->left=nullptr;
        tree->right=nullptr;
        tree->parent=nullptr;
        tree->statistic=S(v,data);
        return tree;
    }
    auto p=lower_bound(tree,v);
    if(p==nullptr)
    {
        p=tree;
        while(p->right) p=p->right;
    }
    else if(p->left)
    {
        p=p->left;
        while(p->right)
            p=p->right;
    }
    auto u=new statistic_node<T,V,S>;
    u->left=nullptr;
    u->right=nullptr;
    u->parent=p;
    u->v=v;
    u->data=data;
    u->statistic=S(v,data);
    u->h=1;
    if(v<=p->v)
        p->left=u;
    else p->right=u;
    p->update();
    return rebalance(p);
}

template<typename T,typename S>
statistic_node<T,std::tuple<>,S>* insert(statistic_node<T,std::tuple<>,S>* tree,T v)
{
    return insert(tree,v,std::make_tuple());
}

template<typename T,typename V, typename S>
statistic_node<T,V,S>* update(statistic_node<T,V,S>*tree, T v, V data)
{
    auto p=lower_bound(tree,v);
    p->data=data;
    return rebalance(p);
}

template<typename T,typename V,typename S>
void destroy(statistic_node<T,V,S>*node)
{
    if(!node)
        return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

template<typename R,typename O>
struct order_sum
{
    inline static O F=O();
    int size;
    R sum;
    order_sum(){}
    template<typename T,typename V>
    order_sum(T v,V data):sum(v),size(1){}
    template<typename T,typename V>
    static void update(statistic_node<T,V,order_sum>*node);
    template<typename T,typename V>
    static int tree_size(statistic_node<T,V,order_sum>*node);
    template<typename T,typename V>
    static T tree_sum(statistic_node<T,V,order_sum>*node);
};

template<typename R,typename O>
struct id2
{
    inline static O F=O();
    int size;
    R sum;
    id2(){}
    template<typename T,typename V>
    id2(T v,V data):sum(data),size(1){}
    template<typename T,typename V>
    static void update(statistic_node<T,V,id2>*node);
    template<typename T,typename V>
    static int tree_size(statistic_node<T,V,id2>*node);
    template<typename T,typename V>
    static T tree_sum(statistic_node<T,V,id2>*node);
};

template<typename R, typename O>
template<typename T, typename V>
void id2<R, O>::update(statistic_node<T, V, id2> *node)
{
    node->statistic.size=(node->left?node->left->statistic.size:0)+1+(node->right?node->right->statistic.size:0);
    node->statistic.sum=F(F(node->left?node->left->statistic.sum:O::neutral,node->data),node->right?node->right->statistic.sum:O::neutral);
}

template<typename R, typename O>
template<typename T, typename V>
int id2<R, O>::tree_size(statistic_node<T, V, id2> *node) {
    return node?node->statistic.size:0;
}

template<typename R, typename O>
template<typename T, typename V>
T id2<R, O>::tree_sum(statistic_node<T, V, id2> *node) {
    return node?node->statistic.sum:O::neutral;
}

template<typename R,typename O>
template<typename T, typename V>
void order_sum<R,O>::update(statistic_node<T, V, order_sum> *node)
{
    node->statistic.size=(node->left?node->left->statistic.size:0)+1+(node->right?node->right->statistic.size:0);
    node->statistic.sum=F(F(node->left?node->left->statistic.sum:O::neutral,node->v),node->right?node->right->statistic.sum:O::neutral);
}

template<typename R, typename O>
template<typename T, typename V>
int order_sum<R, O>::tree_size(statistic_node<T, V, order_sum> *node)
{
    return node?node->statistic.size:0;
}

template<typename R, typename O>
template<typename T, typename V>
T order_sum<R, O>::tree_sum(statistic_node<T, V, order_sum> *node)
{
    return node?node->statistic.sum:O::neutral;
}

template<typename T,typename V,typename O>
T order(statistic_node<T,V,order_sum<T,O>> *tree,T v)
{
    using statistic_type=order_sum<T,O>;
    if(!tree)
        return 0;
    if(v<tree->v)
        return order(tree->left,v);
    else if(tree->v==v)
        return statistic_type::tree_size(tree->left);
    else return statistic_type::tree_size(tree->left)+1+order(tree->right,v);
}

template<typename T,typename V,typename O>
T prefix_sum(statistic_node<T,V,order_sum<T,O>> *tree,int n)
{
    using statistic_type=order_sum<T,O>;
    if(!tree||n<=0)
        return O::neutral;
    if(n>=statistic_type::tree_size(tree))
        return tree->statistic.sum;
    if(n>statistic_type::tree_size(tree))
        return prefix_sum(tree,tree->statistic.size);
    if(n<=statistic_type::tree_size(tree->left))
        return prefix_sum(tree->left,n);
    else return order_sum<T,O>::F(statistic_type::F(statistic_type::tree_sum(tree->left),tree->v),
                                  prefix_sum(tree->right,n-statistic_type::tree_size(tree->left)-1));
}

template<typename T,typename V,typename O>
T sum(statistic_node<T,V,order_sum<T,O>> *tree,int l,int r)
{
    using statistic_type=order_sum<T,O>;
    if(!tree || l>=r)
        return O::neutral;
    if(r>tree->statistic.size)
        return sum(tree,l,tree->statistic.size);
    if(l<0)
        return sum(tree,0,r);
    if(l>statistic_type::tree_size(tree->left))
        return sum(tree->right,l-statistic_type::tree_size(tree->left)-1,r-statistic_type::tree_size(tree->left)-1);
    else if(r<=statistic_type::tree_size(tree->left))
        return sum(tree->left,l,r);
    else
        return statistic_type::F(statistic_type::F(sum(tree->left,l,statistic_type::tree_size(tree->left)),tree->v),
                                 prefix_sum(tree->right,r-statistic_type::tree_size(tree->left)-1));
}

template<typename T,typename V,typename O>
V prefix_sum(statistic_node<T,V,id2<V,O>> *tree,int n)
{
    using statistic_type=id2<V,O>;
    if(!tree||n<=0)
        return O::neutral;
    if(n>=statistic_type::tree_size(tree))
        return tree->statistic.sum;
    if(n>statistic_type::tree_size(tree))
        return prefix_sum(tree,tree->statistic.size);
    if(n<=statistic_type::tree_size(tree->left))
        return prefix_sum(tree->left,n);
    else return id2<V,O>::F(statistic_type::F(statistic_type::tree_sum(tree->left),tree->data),
                                       prefix_sum(tree->right,n-statistic_type::tree_size(tree->left)-1));
}

template<typename T,typename V,typename O>
V sum(statistic_node<T,V,id2<V,O>> *tree,int l,int r)
{
    using statistic_type=id2<V,O>;
    if(!tree || l>=r)
        return O::neutral;
    if(r>tree->statistic.size)
        return sum(tree,l,tree->statistic.size);
    if(l<0)
        return sum(tree,0,r);
    if(l>statistic_type::tree_size(tree->left))
        return sum(tree->right,l-statistic_type::tree_size(tree->left)-1,r-statistic_type::tree_size(tree->left)-1);
    else if(r<=statistic_type::tree_size(tree->left))
        return sum(tree->left,l,r);
    else
        return statistic_type::F(statistic_type::F(sum(tree->left,l,statistic_type::tree_size(tree->left)),tree->data),
                                 prefix_sum(tree->right,r-statistic_type::tree_size(tree->left)-1));
}

template<typename V,typename O>
class id1
{
    statistic_node<int,V,id2<V,O>>*root;
    int size=0;
public:
    id1():root(nullptr){}
    void insert(V data)
    {
        root=::insert(root,size++,data);
    }
    void update(int u,V data)
    {
        ::update(root,u,data);
    }
    V query(int l,int r) const
    {
        return sum(root,l,r);
    }
};

using natural = long long;
using couple =std::pair<natural,natural>;
constexpr natural N_max=3e5;
int main() {
    std::ios_base::sync_with_stdio(false);
    natural n,q;
    std::cin >> n >> q;
    std::vector<natural> A(n);
    std::vector<natural> B(n),C2(N_max+1);
    for(natural i=0;i<=N_max;i++)
        C2[i]=(i*(i+1))/2;
    for(auto &a:A)
        std::cin >> a;
    std::map<natural,natural> segment;
    for(int i=0;i<n;i++) {
        int j;
        for (j = i+1; j < n && A[j-1]<=A[j]; j++);
        natural m=(j-i);
        B[i]=C2[m];
        segment[i]=m;
        i=j-1;
    }
    id1<natural,plus_t<natural>> T;
    for(int i=0;i<n;i++)
        T.insert(B[i]);
    for(int i=0;i<q;i++)
    {
        int t;
        std::cin >> t;
        if(t==1)
        {
            natural x,y;
            std::cin >> x >> y;
            x--;
            A[x]=y;
            if(x>0)
            {
                auto it1=std::prev(segment.upper_bound(x-1)),it2=std::prev(segment.upper_bound(x));
                if(A[x-1]<=A[x] && it1!=it2)
                {
                    it1->second+=it2->second;
                    auto m=it1->second;
                    B[it1->first]=C2[m];
                    B[it2->first]=0;
                    T.update(it1->first,B[it1->first]);
                    T.update(it2->first,B[it2->first]);
                    segment.erase(it2->first);
                }
                else if(A[x-1]>A[x] && it1==it2)
                {
                    couple P;
                    P.first=x;
                    P.second=it1->second+(it1->first-P.first);
                    it1->second=P.first-it1->first;
                    natural m1=it1->second,m2=P.second;
                    B[it1->first]=C2[m1];
                    B[P.first]=C2[m2];
                    T.update(it1->first,B[it1->first]);
                    T.update(P.first,B[P.first]);
                    segment.insert(P);
                }
            }
            if(x<n-1)
            {
                auto it1=std::prev(segment.upper_bound(x)),it2=std::prev(segment.upper_bound(x+1));
                if(A[x]<=A[x+1] && it1!=it2)
                {
                    it1->second+=it2->second;
                    auto m=it1->second;
                    B[it1->first]=C2[m];
                    B[it2->first]=0;
                    T.update(it1->first,B[it1->first]);
                    T.update(it2->first,B[it2->first]);
                    segment.erase(it2->first);
                }
                else if(A[x]>A[x+1] && it1==it2)
                {
                    couple P;
                    P.first=x+1;
                    P.second=it1->second+(it1->first-P.first);
                    it1->second=P.first-it1->first;
                    natural m1=it1->second,m2=P.second;
                    B[it1->first]=C2[m1];
                    B[P.first]=C2[m2];
                    T.update(it1->first,B[it1->first]);
                    T.update(P.first,B[P.first]);
                    segment.insert(P);
                }
            }

        }
        else if(t==2)
        {
            int l,r;
            std::cin >> l >> r;
            l=std::max(l,1);
            r=std::min<natural>(r,n);
            l--;
            r--;
            auto it1=segment.lower_bound(l),it2=std::prev(segment.upper_bound(r));
            if(it1==segment.end() || it1->first>it2->first)
            {
                natural m = r-l+1;
                m=(m*(m+1))/2;
                std::cout << m << '\n' ;
                continue;
            }
            natural m1=0,m2=0;
            m1=std::max(it1->first-l,0LL);
            m1=C2[m1];
            m2 = std::max(r + 1 - it2->first,0LL);
            m2 = C2[m2];
            auto s=T.query(it1->first,it2->first);
            natural R=s+m1+m2;
            std::cout << R << '\n';
        }
    }
    return 0;
}
