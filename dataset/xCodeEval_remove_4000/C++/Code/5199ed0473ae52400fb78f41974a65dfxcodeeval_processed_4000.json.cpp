



















 
 






 
typedef long long ll;
 
using namespace std;

ll modd = 1000*1000*1000+7;

ll binary_search(function<bool(ll)> func, ll start, ll end) {
    
    if (end <= start) {   return end;  }   

    if (!func(end-1)) {  return end;  }
    while (end-start>1) {
        ll mid = (start+end)/2;
        if (func(mid)) {  end = mid;  } else { start = mid;   }
    }
    if (func(start)) {  return start;  } else {  return end;   }
}; 

template<class T>
class id4 {
  public:
    stack<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;

    id4() {}

    id4(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
      notvisited(notv), mark_visited(mark_v), neighbors(neigh), end_(false), current(start), prev(start) {
          todo.push(make_pair(start, start)); operator++();
    }

    void operator++() {
        end_ = true;
        while (!todo.empty()) {
            current = todo.top().first; prev = todo.top().second; todo.pop();
            if (notvisited(current)) {
                mark_visited(current);
                for (const T x : neighbors(current)) {  todo.push(make_pair(x, current));   }
                end_ = false;
                break;
            }
        }
    }

    T operator*() {     return current;    }

    T previous() {  return prev;  }

    bool end() {  return end_;  }

  private:
    T current; 

    T prev;    

    bool end_;
};

template<class T>
class id3 {
  public:
    queue<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;

    id3() {}

    id3(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
      notvisited(notv), mark_visited(mark_v), neighbors(neigh), end_(false), current(start), prev(start) {
          todo.push(make_pair(start, start)); operator++();
    }

    void operator++() {
        end_ = true;
        while (!todo.empty()) {
            current = todo.front().first; prev = todo.front().second; todo.pop();
            if (notvisited(current)) {
                mark_visited(current);
                for (const T x : neighbors(current)) {  todo.push(make_pair(x, current));   }
                end_ = false;
                break;
            }
        }
    }

    T operator*() {     return current;    }

    T previous() {  return prev;  }

    bool end() {  return end_;  }

  private:
    T current;   

    T prev;      

    bool end_;
};


template<class T>
class DirectedGraph {
    

    public:
      vector<T> vertices;
      vector<set<int>> neighbors;
      id4<int> dfs_iterator;
      id3<int> id11;
      vector<bool> visited;

      DirectedGraph() {}

      DirectedGraph(int n) {  for (int i = 0; i < n; ++i) {  AddVertex(0);  }   }

      bool EdgeExists(int i_from, int j_to) {
          return (neighbors[i_from].find(j_to) != neighbors[i_from].end());
      }

      void AddVertex(T val) {
          vertices.push_back(val);
          neighbors.push_back(set<int>());      }

      void AddEdge(int i_from, int j_to) {
          if (!EdgeExists(i_from, j_to)) {     neighbors[i_from].insert(j_to);      }
      }

      T& operator[](int i) {      return vertices[i];      }

      void RemoveEdge(int i_from, int j_to) {
          if (EdgeExists(i_from, j_to)) {
          neighbors[i_from].erase(find(neighbors[i_from].begin(), neighbors[i_from].end(), j_to));      } }

      DirectedGraph<T> Transpose() {
          DirectedGraph<T> ret;
          for (auto x : vertices) {  ret.AddVertex(x);   }
          for (int i_from = 0; i_from < vertices.size(); ++i_from) {
              for (int j_to : neighbors[i_from]) {
                  ret.AddEdge(j_to, i_from);
              }
          }
          return ret;      }

      int vertices_count() {   return vertices.size();  }

      void dfs_init(int start) {
          visited = vector<bool>(vertices.size(), false);
          dfs_iterator = id4<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
            [this](int x) {  return neighbors[x];  } );
      }

      void bfs_init(int start) {
          visited = vector<bool>(vertices.size(), false);
          id11 = id3<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
            [this](int x) {  return neighbors[x];  } );
      }

      void print_() {
          forr(i, 0, vertices.size()) {
              for (auto x : neighbors[i]) {
                  cout << i << "->" << x << endl;
              }
          }
      }

};


template<class T>
struct SegmentData {
    int left, right;    

    T max_in_interval;   

    int prev;           

};

template<class T>
class SegmentTree : public DirectedGraph<SegmentData<T>> {
        

    public:
      int root;        

      int data_size;   

      vector<T> data;                    


    SegmentTree(int n, function<T(T,T)> f, T zero_v) : 
       default_val(zero_v), data(vector<T>(n, zero_v)), data_size(n), singleton_index(vector<int>(n, 0)), func(f)  {  
        

      root = HelperCreate(0, data.size());
      HelperSetPrev(root, -1);
    }

    T GetIntervalEvaluation(int x, int y) {  

      if (x >= y)  {   return default_val;  }  

      return GetMaxHelper(x, y, root);
    }

    void SetVal(int index, T val) {
        data[index] = val;
        int curr = singleton_index[index];
        this->vertices[curr].max_in_interval = val;
        while (this->vertices[curr].prev >= 0) {
            curr = this->vertices[curr].prev;
            T ret = this->vertices[*(this->neighbors[curr].begin())].max_in_interval;
            if (this->neighbors[curr].size() > 1) {
                if (  this->vertices[*(this->neighbors[curr].begin())].left < this->vertices[ *next(this->neighbors[curr].begin())].right  ) {
                  ret = func(ret, this->vertices[ *next(this->neighbors[curr].begin())].max_in_interval );
                } else {
                  ret = func( this->vertices[ *next(this->neighbors[curr].begin())].max_in_interval, ret );
                }
            }
            this->vertices[curr].max_in_interval = ret;
        }
    }

    T operator[](int i) {    return data[i];     }

    private:
      T default_val;                     

      function<T(T,T)> func;             

      vector<int> singleton_index;       


      void HelperSetPrev(int root, int prev_) {
          this->vertices[root].prev = prev_;
          for (auto x : this->neighbors[root]) {      HelperSetPrev(x, root);       }
      }

      int HelperCreate(int left, int right) {
          if (right-left == 1) {
              this->AddVertex({left, right, default_val, 0});
              singleton_index[left] = this->vertices.size()-1;
              return this->vertices.size()-1;
          }
          int mid = (left+right)/2;
          int l1 = HelperCreate(left, mid);
          int r1 = HelperCreate(mid, right);
          this->AddVertex({left, right, default_val, 0});
          this->AddEdge(this->vertices.size()-1, l1); this->AddEdge(this->vertices.size()-1, r1);

          return this->vertices.size()-1;
      }

      T GetMaxHelper(int x, int y, int root) {
          if ((x == this->vertices[root].left) && (y == this->vertices[root].right)) {   return this->vertices[root].max_in_interval;   }
          int left = *(this->neighbors[root].begin());
          int right = *next(this->neighbors[root].begin());
          if (this->vertices[left].left > this->vertices[right].left) {  swap(left, right);   }
          int mid = this->vertices[left].right;
          if ((x < mid) && (y > mid))  {      return func(GetMaxHelper(x, mid, left), GetMaxHelper(mid, y, right));  }
          if ((x < mid) && (y <= mid)) {      return GetMaxHelper(x, y, left);      }
          if ((x >= mid) && (y > mid)) {      return GetMaxHelper(x, y, right);     }
      }
};


int main()   {

    ios_base::sync_with_stdio(false);

    cout.precision(17);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> rand_gen(0, modd);   

 


  


    int test_cases = 1;
    forr(t, 1, test_cases) {
        readll(n); readll(m); readll(k);
        vector<pair<ll,int>> id5, id9, both_like, id6;
        int ct_a = 0, ct_b = 0;
        forr(i,0,n) {
            readll(kk); readll(a); readll(b);
            ct_a += a; ct_b += b;
            if ((a==1) && (b==0)) {
                id5.push_back(make_pair(kk,i));
            }
            if ((a==0) && (b==1)) {
                id9.push_back(make_pair(kk,i));
            }
            if ((a==1) && (b==1)) {
                both_like.push_back(make_pair(kk,i));
            }
            if((a==0) && (b==0)) {
                id6.push_back(make_pair(kk,i));
            }
        }
        if ((ct_a<k) || (ct_b<k)) {cout << -1 << endl; continue;}
        sort(id5.begin(), id5.end());
        sort(id9.begin(), id9.end());
        sort(both_like.begin(), both_like.end());
        sort(id6.begin(), id6.end());

        vector<tuple<ll,ll,ll>> elts;
        forr(i,0,id5.size()) {  elts.push_back(make_tuple(id5[i].first,0,i));  }
        forr(i,0,id9.size()) {  elts.push_back(make_tuple(id9[i].first,1,i));  }
        forr(i,0,id6.size()) {  elts.push_back(make_tuple(id6[i].first,2,i));  }
        sort(elts.begin(), elts.end());
        vector<int> indices_a(id5.size()), indices_b(id9.size());
        forr(i,0,elts.size()) {
            if (get<1>(elts[i])==0) {
                indices_a[get<2>(elts[i])] = i; 
            }
            if (get<1>(elts[i])==1) {
                indices_b[get<2>(elts[i])] = i;
            }
        }

        if (elts.empty()) {
            ll ret = 0; forr(i,0,m) {  ret += both_like[i].first;  }
            cout << ret << endl;
            forr(i,0,m) {  cout << both_like[i].second+1 << " ";   }
            cout << endl;
            continue;
        }

        SegmentTree<ll> id1(elts.size(), [](ll x,ll y){return x+y;}, 0);
        SegmentTree<ll> id7(elts.size(), [](ll x,ll y){return x+y;}, 0);
        forr(i,0,elts.size()) {  id1.SetVal(i, 1);   }
        forr(i,0,elts.size()) {  id7.SetVal(i, get<0>(elts[i]));   }

        vector<ll> id2; id2.push_back(0);
        for(auto x : elts) {
            id2.push_back(id2.back() + get<0>(x));
        }

        vector<ll> id10; id10.push_back(0);
        vector<ll> id0; id0.push_back(0);
        vector<ll> id8; id8.push_back(0);
        for(auto x : id5) {
            id10.push_back(id10.back()+x.first);
        }
        for(auto x : id9) {
            id0.push_back(id0.back()+x.first);
        }
        for(auto x : both_like) {
            id8.push_back(id8.back()+x.first);
        }

        ll ret = 1000000000007, ret_orig(ret);
        ll min_i, min_need;
        int last_cleanup = -1;
        for(int i=id8.size()-1; i>=0; --i) {


            if ((max((k-i),0LL)>=(int)id10.size()) || (max((k-i),0LL)>=(int)id0.size())) { continue; }
            if (max((k-i),0LL)>0) {
              for(int j = last_cleanup+1; j <= k-i-1; ++j) {
                id1.SetVal(indices_a[j], 0); id1.SetVal(indices_b[j], 0);
                id7.SetVal(indices_a[j], 0); id7.SetVal(indices_b[j], 0);
              }
              last_cleanup = k-i-1;
            }

            int need = -i-2*max((k-i),0LL)+m;
            if (need<0) {continue;}
            ll temp = id8[i] + id0[max((k-i),0LL)] + id10[max((k-i),0LL)];
            if (need>id1.GetIntervalEvaluation(0, elts.size()))  {
                continue;
            }
            if (need>0) {
                ll where = binary_search([&id1, need](ll x) {
                    return (id1.GetIntervalEvaluation(0, x+1)>=need);
                  }, 0, elts.size());
                if (id1.GetIntervalEvaluation(0, where+1)<need) {continue;}
                temp += id7.GetIntervalEvaluation(0, where+1);
            }
            ret = min(ret, temp);
            if (ret==temp) {  min_i = i; min_need = need;   }
        }

        if (ret==ret_orig) {cout << -1 << endl; continue;}

        cout << ret << endl;
        vector<int> ans;
        forr(i,0,min_i) {
            ans.push_back(both_like[i].second+1);
        }
        int ct = 0;
        forr(i,0,elts.size()) {
            if (ct==max(k-min_i,0LL)) {break;}
            if (get<1>(elts[i]) == 0) {
                ct++; ans.push_back( id5[get<2>(elts[i])].second + 1 );
                elts[i] = make_tuple(-1,-1,-1);
            }            
        }
        ct = 0;
        forr(i,0,elts.size()) {
            if (ct==max(k-min_i,0LL)) {break;}
            if (get<1>(elts[i]) == 1) {
                ct++; ans.push_back( id9[get<2>(elts[i])].second + 1 );
                elts[i] = make_tuple(-1,-1,-1);
            }            
        }
        ct = 0;
        forr(i,0,elts.size()) {
            if (ct==min_need) {break;}
            if (get<1>(elts[i]) == 0) {
                ct++; ans.push_back( id5[get<2>(elts[i])].second + 1 );
            }            
            if (get<1>(elts[i]) == 1) {
                ct++; ans.push_back( id9[get<2>(elts[i])].second + 1 );
            }            
            if (get<1>(elts[i]) == 2) {
                ct++; ans.push_back( id6[get<2>(elts[i])].second + 1 );
            }            
        }
        sort(ans.begin(), ans.end());
        for(auto x : ans) {
            cout << x << " ";
        }
        cout << endl;

    }
 




 
    return 0;
}