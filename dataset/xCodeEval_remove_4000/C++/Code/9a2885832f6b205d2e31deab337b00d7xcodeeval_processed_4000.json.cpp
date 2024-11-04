















using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node* newNode(int d)
{
    struct node* temp=new struct node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    return temp;
};
void inorder(struct node*temp,vector<int> &v)
{
    if(!temp)
        return;
    inorder(temp->left,v);
    v.push_back(temp->data);
    inorder(temp->right,v);
}
void id7(struct node*temp)
{
    if(!temp)
        return;
    id7(temp->left);
    cout<<temp->data<<" ";
    id7(temp->right);
}
void search(struct node*temp,int data)
{
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            cout<<"found"<<endl;
            break;
        }
        else if(temp->data<data)
            temp=temp->right;
        else
            temp=temp->left;
    }

}
void insert(struct node*temp,int data)
{
    while(temp->left==NULL&&temp->right==NULL)
    {
        if(data<temp->data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(data<temp->data)
    {
        temp->left=newNode(data);
    }
    else
    {
        temp->right=newNode(data);
    }
}
void id8(struct node*temp,int data)
{
    struct node*t=temp;
    while(temp->data!=data)
    {
        t=temp;
        if(data<temp->data)
        {
            temp=temp->left;
        }
        else
            temp=temp->right;
    }
    if(!temp->left&&!temp->right)
    {
        if(t!=temp)
        {
            if(t->right==temp)
                t->right=NULL;
            else
                t->left=NULL;
        }
        else
            temp->data=-1;
    }
    else if(!(temp->left&&temp->right))
    {
        if(temp->left)
        {
            temp->data=temp->left->data;
            temp->left=NULL;
        }
        else
        {
            temp->data=temp->right->data;
            temp->right=NULL;
        }
    }
    else
    {
        t=temp->right;
        struct node*q=t;
        while(t->left)
        {
            q=t;
            t=t->left;
        }
        if(t!=q)
        {temp->data=t->data;
        q->left=NULL;
        }
        else
        {
            temp->data=t->data;
            temp->right=NULL;
        }
    }
}
struct node*construct(int a[],int l,int r)
{
    if(r<l)
        return NULL;
    struct node*root=newNode(a[(l+r)/2]);
    root->left=construct(a,l,(l+r)/2-1);
    root->right=construct(a,(l+r)/2+1,r);
    return root;
};
void constree(struct node*temp,int n)
{
    if(n<temp->data&&temp->left==NULL)
        temp->left=newNode(n);
    else if(n>temp->data&&temp->right==NULL)
        temp->right=newNode(n);
    else if(n<temp->data)
        constree(temp->left,n);
    else if(n>temp->data)
        constree(temp->right,n);
}
struct node*constructtree(vector<int> v)
{
    struct node*root=newNode(v[0]);
    struct node*temp=NULL;
    for(int i=1;i<v.size();i++)
    {
        temp=root;
        constree(temp,v[i]);
    }
    return root;
};
void checkbalanced(struct node*root)
{
    deque<struct node*> q;
    q.push_back(root);
    struct node*temp=NULL;
    while(!q.empty())
    {
        temp=q.front();
        if(!temp->left&&temp->right)
        {
            if(temp->right->right||temp->right->left)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else if(!temp->right&&temp->left)
        {
            if(temp->left->right||temp->left->left)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        if(temp->left)
            q.push_back(temp->left);
        if(temp->right)
            q.push_back(temp->right);
        q.pop_front();
    }
    cout<<"YES"<<endl;
}
void bottomtree(struct node*root)
{
    deque<struct node*> q,res;
    q.push_back(root);
    struct node*temp=NULL;
    while(q.empty()==0)
    {
        temp=q.front();
        q.pop_front();
        res.push_back(temp);
        if(temp->left!=NULL)
        {
            if(temp->left->right==NULL)
            {
                cout<<temp->data<<" ";
            }
            q.push_back(temp->left);
        }
        if(temp->right!=NULL)
        {
            if(temp->right->left==NULL)
                cout<<temp->data<<" ";
            q.push_back(temp->right);
        }
    }
}
map<int,vector<int>> verticaltree(struct node*root,map<int,vector<int>> &m,int n)
{
    m[n].push_back(root->data);
    if(root->left!=NULL)
    m=verticaltree(root->left,m,n+1);
    if(root->right!=NULL)
    m=verticaltree(root->right,m,n-1);
return m;
}
map<int,int> id1(struct node*root,map<int,int> &m,int n)
{
    if(m[n]==0)
        m[n]=root->data;
    if(root->left!=NULL)
    m=id1(root->left,m,n+1);
    if(root->right!=NULL)
    m=id1(root->right,m,n-1);
return m;

}
void printq(deque<int> q)
{
    for(auto itr=q.begin();itr!=q.end();itr++)
        cout<<*itr<<" ";
    cout<<endl;
}
void checkpath(struct node*root,deque<int> q,int n)
{
    if(root==NULL)
        {
         return;
        }
    if(root->data>n)
        return;
    if(root->data==n)
    {
        q.push_back(root->data);
        printq(q);
        q.pop_back();
        return;
    }
    q.push_back(root->data);
    checkpath(root->left,q,n-root->data);
    checkpath(root->right,q,n-root->data);
}
struct node* id4(map<int,int> m,vector<int> le)
{
    struct node*root=newNode(le[0]);
    struct node*temp=root;
    struct node*res=root;
    for(int i=1;i<le.size();i++)
    {
        temp=root;
        int p=m[le[i]];
        while(temp!=NULL)
        {
            res=temp;
            if(p<m[temp->data])
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        if(temp==res->left)
        {
            res->left=newNode(le[i]);
        }
        else
            res->right=newNode(le[i]);
    }
    return root;
}
void righttree(struct node*root)
{
    struct node*temp=NULL;
    deque<struct node*> q,s;
    s.push_back(root);
    while(s.empty()!=1)
    {
        q=s;
        s.clear();
        while(q.empty()!=1)
    {
        temp=q.front();
        if(q.front()->left!=NULL)
            s.push_back(q.front()->left);
        if(q.front()->right!=NULL)
            s.push_back(q.front()->right);
        q.pop_front();
    }
    cout<<temp->data<<" ";
    }

}
void id10(struct node*root,deque<int> q)
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
    {
        q.push_back(root->data);
        printq(q);
        q.pop_back();
        return;
    }
    q.push_back(root->data);
    id10(root->left,q);
    id10(root->right,q);
}


struct minheap
{
    int capacity;
    int heap_size;
    int* h;
};
struct minheap* newarr(int capacity)
{
    int* h=new int [capacity];
    struct minheap*temp=new struct minheap;
    temp->h=h;
    temp->capacity=capacity;
    temp->heap_size=0;
    return temp;
};
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return (2*i);
}
int right(int i)
{
    return (2*i+1);
}
int getmini(struct minheap*temp)
{
    return temp->h[0];
}
void id11(struct minheap*temp,int i)
{
    int *h=temp->h;
    int l,r,smallest=i;
    if(left(i)<temp->heap_size)
    l=left(i);
    else
        l=-1;
    if(right(i)<temp->heap_size)
    r=right(i);
    else
        r=-1;
    if(l==-1)
    return;
    if(l!=-1&&r==-1)
    {
        if(h[l]<h[i])
            {smallest=l;
             swap(h[l],h[i]);
            }
    }
    else
    {
        if(h[l]<h[i]&&h[l]<h[r])
            smallest=l;
        else if(h[r]<h[l]&&h[r]<h[i])
            smallest=r;
        swap(h[smallest],h[i]);
    }
    if(smallest==i)
        return;
    id11(temp,smallest);

}
void insertheap(struct minheap*temp,int n)
{
    int *h=temp->h;
    if(temp->heap_size==temp->capacity)
        cout<<"OVERFLOW";
    else
    {
        temp->heap_size++;
        int i=temp->heap_size-1;
        h[i]=n;
        while(i!=0&&h[parent(i)]>h[i])
            {swap(h[parent(i)],h[i]);
             i=parent(i);
            }
    }
}
void id3(struct minheap*temp,int i,int value)
{
    int *h=temp->h;
    h[i]=value;
    while(i!=0&&h[parent(i)]>h[i])
        {swap(h[parent(i)],h[i]);
         i=parent(i);
        }
}
int extractmin(struct minheap*temp)
{
    int s=temp->heap_size;
    int *h=temp->h;
    if(s==0)
        cout<<"heap is empty"<<endl;
    else if(s==1)
        {
         temp->heap_size--;
         return h[0];
        }
    else
    {
        int root=h[0];
        h[0]=h[s-1];
        temp->heap_size--;
        id11(temp,0);
        return root;
    }
}
void deletekey(struct minheap*temp,int i)
{
    id3(temp,i,INT_MIN);
    extractmin(temp);
}
void id9(struct minheap*temp)
{
    while(temp->heap_size>0)
    {int t=extractmin(temp);
    temp->h[temp->heap_size]=t;
    }
}
class graph
{
    int V;
    list<int> *adj;
    map<int,vector<int>> m;

public:
    graph(int V);
    void addEdge(int u,int v);
    void BFS(int u);
    void DFS(int u);
    int mothervertex();
    void timeardep(int u,int x,int y);
    void showardep();
    int checkbipartite();
    bool kahns_topo(vector<int> &topo);
    void paths_givenedges(int u,int v,int m);
    bool iscyclic(int temp,vector<bool> visited);
    int id12(int s1,int s2,int d1,int d2);
    list<int>* get_adj()
    {
        return adj;
    }
};
graph::graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}
void graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void graph::timeardep(int u,int x,int y)
{
    m[u].push_back(x);
    m[u].push_back(y);
}
void graph::showardep()
{
    for(auto itr=m.begin();itr!=m.end();itr++)
    {
        cout<<itr->first<<"->";
        cout<<itr->second[0]<<" "<<itr->second[1]<<endl;
    }
}
void graph::BFS(int u)
{
    deque<int> q;
    q.push_back(u);
    bool visited[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    visited[u]=true;
    while(!q.empty())
    {
        int temp=q.front();
        cout<<temp<<" ";
        q.pop_front();
        for(auto itr=adj[temp].begin();itr!=adj[temp].end();itr++)
        {
            if(visited[*itr]==false)
            {
                visited[*itr]=true;
                q.push_back(*itr);
            }
        }
    }
    cout<<endl;
}
int DFSmain(int v,vector<bool> visited,list<int> adj[],map<int,vector<int>> &m,int count)
{
    if(!visited[v])
    {
     cout<<v<<" ";
     m[v].push_back(count);
    }
    visited[v]=true;
    for(auto itr=adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(visited[*itr]==false)
            {
                count=DFSmain(*itr,visited,adj,m,++count);
            }
    }
    m[v].push_back(++count);
    return count;
}
void graph::DFS(int v)
{
    int count=0;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {count=DFSmain(i,visited,adj,m,count);
            count++;
            }
        }
}
int graph::checkbipartite()
{
    int count=0;
    vector<int> visited(V,false),color(V,-1);
    deque<int> q;
    q.push_back(1);
    color[1]=1;
        while(!q.empty())
    {
        int temp=q.front();
        q.pop_front();
        for(auto itr=adj[temp].begin();itr!=adj[temp].end();itr++)
        {
            if(visited[*itr]==false)
            {
                visited[*itr]=true;
                q.push_back(*itr);
                color[*itr]=1-color[temp];
            }
            else if(color[*itr]==color[temp])
                return 0;
        }
    }
    return 1;


}
bool graph::kahns_topo(vector<int> &topo)
{
    vector<int> indegree(V,0);
    deque<int> q;
    for(int i=0;i<V;i++)
    {
        for(auto itr=adj[i].begin();itr!=adj[i].end();itr++)
        {
            indegree[*itr]++;
        }
    }
    for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
                q.push_back(i);
        }
    while(q.empty()==0)
    {
        int temp=q.front();
        q.pop_front();
        topo.push_back(temp);
        for(auto itr=adj[temp].begin();itr!=adj[temp].end();itr++)
        {
            if(--indegree[*itr]==0)
                q.push_back(*itr);
        }
    }
    for(int i=0;i<V;i++)
    {
        if(indegree[i]>0)
            return false;
    }
    return true;

}
void totalpaths(int v,int m,deque<int> q,vector<bool> visited,list<int> *adj,int parent)
{
    q.push_back(parent);
    int temp=q.back();
    visited[temp]=true;
    if(temp==v)
        {
            

            {printq(q);
             return;
            }
            

              

        }
    for(auto itr=adj[temp].begin();itr!=adj[temp].end();itr++)
    {
        if(visited[*itr]==false)
        {
            totalpaths(v,m,q,visited,adj,*itr);
        }
    }
}
void graph::paths_givenedges(int u,int v,int m)
{
    deque<int> q;
    vector<bool> visited(V,false);
    totalpaths(v,m,q,visited,adj,u);
}
bool graph::iscyclic(int temp,vector<bool> visited)
{
    visited[temp]=true;
    for(auto itr=adj[temp].begin();itr!=adj[temp].end();itr++)
    {
        if(visited[*itr]==false)
        {
            if(iscyclic(*itr,visited));
            else
                return false;
        }
        else
            return false;
    }
    return true;
}
struct block
{
    int x;
    int y;
    int dist=0;
};
struct block* block(int x,int y,int dist)
{
    struct block*temp=new struct block;
    temp->x=x;
    temp->y=y;
    temp->dist=dist;
    return temp;
};
int id15(int src,int des,vector<bool> visited,int res,int &ans,list<int> *adj)
{
    if(src==des)
    {
        if(res<ans)
        {
            ans=res;
        }
        return ans;
    }
    visited[src]=true;
    for(auto itr=adj[src].begin();itr!=adj[src].end();itr++)
    {
        if(visited[*itr]==false)
        {
            id15(*itr,des,visited,res+1,ans,adj);
        }
    }
    return ans;
}
int id12(struct block*src,struct block*des)
{
    deque<struct block*> q;
    q.push_back(src);
    int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
    set<struct block*> visited;
    struct block*temp=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop_front();
        if(temp->x==des->x&&temp->y==des->y)
            break;
        if(visited.count(temp)==0)
        {
            visited.insert(temp);
            for(int i=0;i<8;i++)
            {
                int x1=temp->x+row[i];
                int y1=temp->y+col[i];
                if((x1>=0&&y1>=0)&&(x1<8&&y1<8))
                {
                    struct block*t=block(x1,y1,temp->dist+1);
                    q.push_back(t);
                }
            }
        }
    }
    return temp->dist;
}
class disjointset
{
    unordered_map<int,int> parent;
public:
    void makeset(vector<int>&v)
    {
        for(int i=0;i<v.size();i++)
            parent[i]=i;
    }
    int findrep(int k)
    {
        if(parent[k]==k)
            return k;
        parent[k]=findrep(parent[k]);
        return parent[k];
    }
    void unionset(int a,int b)
    {
        int x=findrep(a);
        int y=findrep(b);
        if(x==y);
        else
            parent[x]=y;
    }
};
class edge
{
    int x,y,w;
    public:
    edge(int x,int y,int w)
    {
        this->x=x;
        this->y=y;
        this->w=w;
    }
    edge(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    int get_w()
    {
        return w;
    }
    int get_x()
    {return x;}
    int get_y()
    {return y;}
};
bool compare_edges(edge a,edge b)
{
    if(a.get_w()<=b.get_w())
        return true;
    else
        return false;
}
void id6(vector<edge> edges)
{
    int N=INT_MIN;
    for(int i=0;i<edges.size();i++)
    {
        if(max(edges[i].get_x(),edges[i].get_y())>N)
            N=max(edges[i].get_x(),edges[i].get_y());
    }
    graph g(N+1);
    vector<int> universe;
    for(int i=0;i<N+1;i++)
        universe.push_back(i);
    disjointset ds;
    ds.makeset(universe);
    for(int i=0,j=1;i<edges.size()&&j<N+1;i++)
    {
        int p=ds.findrep(edges[i].get_x());
        int q=ds.findrep(edges[i].get_y());
        if(p==q);
        else
        {
            ds.unionset(edges[i].get_x(),edges[i].get_y());
            g.addEdge(edges[i].get_x(),edges[i].get_y());
            j++;
        }
    }
    for(int i=0;i<N+1;i++)
    {
        for(auto itr=g.get_adj()[i].begin();itr!=g.get_adj()[i].end();itr++)
        {
            cout<<i<<" "<<*itr<<endl;
        }
    }

}
class vertex
{
    int n,value;
    deque<int> q;
public:
    vertex()
    {

    }
    vertex(int n)
    {
        this->n=n;
        value=INT_MAX;
    }
    set_value(int k)
    {
        value=k;
    }
    int get_n()
    {
        return n;
    }
    int get_value()
    {
        return value;
    }
    void makequeue(deque<int> k,int m)
    {
        q=k;
        q.push_back(m);
    }
    deque<int> get_queue()
    {
        return q;
    }
};
bool operator<(vertex v1,vertex v2)
{
    if(v1.get_value()<=v2.get_value())
        return true;
    else
        return false;
}
void id14(vector<edge> edges,int V)
{
    priority_queue<vertex> p;
    vector<vertex> vertices(V);
    for(int i=0;i<V;i++)
        vertices[i]=vertex(i);
    list<edge> *adj=NULL;
    adj=new list<edge> [V];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].get_x()].push_back(edges[i]);
    }
    vertices[0].set_value(0);
    p.push(vertices[0]);
    vector<bool> visited(V,false);
    while(!p.empty())
    {
        vertex *v=new vertex();
        *v=p.top();
        visited[v->get_n()]=true;
        for(auto itr=adj[v->get_n()].begin();itr!=adj[v->get_n()].end();itr++)
        {
            if(!visited[itr->get_y()]&&(v->get_value()+itr->get_w()<vertices[itr->get_y()].get_value()))
            {
                vertices[itr->get_y()].set_value(v->get_value()+itr->get_w());
                vertices[itr->get_y()].makequeue(vertices[itr->get_x()].get_queue(),itr->get_y());
                p.push(vertices[itr->get_y()]);
            }
        }
        p.pop();
    }
    for(int i=0;i<V;i++)
    {cout<<"cost"<<i<<" "<<vertices[i].get_value()<<endl;
     cout<<"path"<<0<<" ";printq(vertices[i].get_queue());
    }
}
void pushq(int i,int j,int k,vector<int> **path)
{
    vector<int> v1=path[i][k];
    vector<int> v2=path[k][j];
    for(auto itr=v1.begin();itr!=v1.end();itr++)
    {
        path[i][j].push_back(*itr);
    }
    path[i][j].push_back(k);
    for(auto itr=v2.begin();itr!=v2.end();itr++)
    {
        path[i][j].push_back(*itr);
    }
}
void id0(vector<edge> edges,int V)
{
    int dist[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INT_MAX;
        }
    }
    int x,y,w;
    for(int i=0;i<edges.size();i++)
    {
        x=edges[i].get_x();
        y=edges[i].get_y();
        w=edges[i].get_w();
        dist[x][y]=w;
    }
    vector<int> **path;
    path=new vector<int> *[V];
    for(int i=0;i<V;i++)
        path[i]=new vector<int>[V];
    for(int k=0;k<=V-1;k++)
    {
        for(int i=0;i<=V-1;i++)
        {
            for(int j=0;j<=V-1;j++)
            {
                if(dist[i][k]!=INT_MAX&&dist[k][j]!=INT_MAX&&dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pushq(i,j,k,path);
                }
            }
            if (dist[i][i] < 0)
			{
				cout << "Negative Weight Cycle Found!!";
				return;
			}
        }
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"distance bw"<<i<<" "<<j<<":"<<dist[i][j]<<"!!"<<"path:"<<i<<"->";
            for(int k=0;k<path[i][j].size();k++)
                cout<<path[i][j][k]<<"->";
            cout<<j<<endl;
        }
    }

}
bool is_safe(int v,int c,list<int> *adj,vector<int> color)
{
    for(auto itr=adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(color[*itr]==c)
            return false;
    }
    return true;
}
void id2(list<int> *adj,int v,int k,int V,vector<int> color,string COLORS[],int &flag)
{
    if(v==V)
    {
        for(int i=0;i<V;i++)
        {
            cout<<COLORS[color[i]]<<" ";
        }
        cout<<endl;
        flag=1;
        return;
    }
    for(int c=1;c<=k;c++)
    {
        if(is_safe(v,c,adj,color))
        {
            color[v]=c;
            id2(adj,v+1,k,V,color,COLORS,flag);
        }
    }
    if(flag==0)
    {
        cout<<"no formation found"<<endl;
        flag=1;
    }
}
void id13(deque<int> q,list<int> *adj,int v,int V,vector<bool> visited)
{
    visited[v]=true;
    q.push_back(v);
    if(q.size()==V)
    {
        printq(q);
        return;
    }
    for(auto itr=adj[v].begin();itr!=adj[v].end();itr++)
    {
        if(visited[*itr]==false)
        {
            id13(q,adj,*itr,V,visited);
        }
    }

}
void id5(vector<edge> edges,int V)
{
    graph g(V);
    for(int i=0;i<edges.size();i++)
        g.addEdge(edges[i].get_x(),edges[i].get_y());
    string color[] =
    {
	"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK",
	"BLACK", "BROWN", "WHITE", "PURPLE", "VOILET"
    };
    vector<int> result(V,0);
    for(int v=0;v<V;v++)
    {
        int c=1;
        while(is_safe(v,c,g.get_adj(),result)==false)
        {
            c++;
        }
        result[v]=c;
    }
    for(int i=0;i<V;i++)
        cout<<"color for vertex "<<i<<" is "<<color[result[i]]<<endl;

}

int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,even=0,odd=0;
        cin>>n;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            long long int t;
            cin>>t;
            m[t]++;
            if(t%2==0)
                even++;
            else
                odd++;
        }
        if(odd%2==0&&even%2==0)
            {cout<<"YES"<<endl;
             continue;
            }
        for(auto itr=next(m.begin(),1);itr!=m.end();itr++)
        {
            auto it=prev(itr,1);
            if(itr->first-it->first==1)
            {
                odd--;
                even--;
                break;
            }
        }
        if(odd%2==0&&even%2==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
