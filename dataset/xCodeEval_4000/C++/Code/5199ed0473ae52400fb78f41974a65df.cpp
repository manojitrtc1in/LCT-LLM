
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>
 
 
#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s
 
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
class depth_first_search_iterator {
  public:
    stack<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;

    depth_first_search_iterator() {}

    depth_first_search_iterator(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
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
class breadth_first_search_iterator {
  public:
    queue<pair<T,T>> todo;
    function<bool(T)> notvisited;
    function<void(T)> mark_visited;
    function<set<T>(T)> neighbors;

    breadth_first_search_iterator() {}

    breadth_first_search_iterator(T start, function<bool(T)> notv, function<void(T)> mark_v, function<set<T>(T)> neigh) :
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
      depth_first_search_iterator<int> dfs_iterator;
      breadth_first_search_iterator<int> bfs_iterator;
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
          dfs_iterator = depth_first_search_iterator<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
            [this](int x) {  return neighbors[x];  } );
      }

      void bfs_init(int start) {
          visited = vector<bool>(vertices.size(), false);
          bfs_iterator = breadth_first_search_iterator<int>(start, [this](int x){ return !visited[x]; }, [this](int x) { visited[x] = true;  },
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
        vector<pair<ll,int>> only_alice, only_bob, both_like, noonelikes;
        int ct_a = 0, ct_b = 0;
        forr(i,0,n) {
            readll(kk); readll(a); readll(b);
            ct_a += a; ct_b += b;
            if ((a==1) && (b==0)) {
                only_alice.push_back(make_pair(kk,i));
            }
            if ((a==0) && (b==1)) {
                only_bob.push_back(make_pair(kk,i));
            }
            if ((a==1) && (b==1)) {
                both_like.push_back(make_pair(kk,i));
            }
            if((a==0) && (b==0)) {
                noonelikes.push_back(make_pair(kk,i));
            }
        }
        if ((ct_a<k) || (ct_b<k)) {cout << -1 << endl; continue;}
        sort(only_alice.begin(), only_alice.end());
        sort(only_bob.begin(), only_bob.end());
        sort(both_like.begin(), both_like.end());
        sort(noonelikes.begin(), noonelikes.end());

        vector<tuple<ll,ll,ll>> elts;
        forr(i,0,only_alice.size()) {  elts.push_back(make_tuple(only_alice[i].first,0,i));  }
        forr(i,0,only_bob.size()) {  elts.push_back(make_tuple(only_bob[i].first,1,i));  }
        forr(i,0,noonelikes.size()) {  elts.push_back(make_tuple(noonelikes[i].first,2,i));  }
        sort(elts.begin(), elts.end());
        vector<int> indices_a(only_alice.size()), indices_b(only_bob.size());
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

        SegmentTree<ll> count_elts(elts.size(), [](ll x,ll y){return x+y;}, 0);
        SegmentTree<ll> sum_elts(elts.size(), [](ll x,ll y){return x+y;}, 0);
        forr(i,0,elts.size()) {  count_elts.SetVal(i, 1);   }
        forr(i,0,elts.size()) {  sum_elts.SetVal(i, get<0>(elts[i]));   }

        vector<ll> part_sum_elts; part_sum_elts.push_back(0);
        for(auto x : elts) {
            part_sum_elts.push_back(part_sum_elts.back() + get<0>(x));
        }

        vector<ll> part_sum_alice; part_sum_alice.push_back(0);
        vector<ll> part_sum_bob; part_sum_bob.push_back(0);
        vector<ll> part_sum_both; part_sum_both.push_back(0);
        for(auto x : only_alice) {
            part_sum_alice.push_back(part_sum_alice.back()+x.first);
        }
        for(auto x : only_bob) {
            part_sum_bob.push_back(part_sum_bob.back()+x.first);
        }
        for(auto x : both_like) {
            part_sum_both.push_back(part_sum_both.back()+x.first);
        }

        ll ret = 1000000000007, ret_orig(ret);
        ll min_i, min_need;
        int last_cleanup = -1;
        for(int i=part_sum_both.size()-1; i>=0; --i) {


            if ((max((k-i),0LL)>=(int)part_sum_alice.size()) || (max((k-i),0LL)>=(int)part_sum_bob.size())) { continue; }
            if (max((k-i),0LL)>0) {
              for(int j = last_cleanup+1; j <= k-i-1; ++j) {
                count_elts.SetVal(indices_a[j], 0); count_elts.SetVal(indices_b[j], 0);
                sum_elts.SetVal(indices_a[j], 0); sum_elts.SetVal(indices_b[j], 0);
              }
              last_cleanup = k-i-1;
            }

            int need = -i-2*max((k-i),0LL)+m;
            if (need<0) {continue;}
            ll temp = part_sum_both[i] + part_sum_bob[max((k-i),0LL)] + part_sum_alice[max((k-i),0LL)];
            if (need>count_elts.GetIntervalEvaluation(0, elts.size()))  {
                continue;
            }
            if (need>0) {
                ll where = binary_search([&count_elts, need](ll x) {
                    return (count_elts.GetIntervalEvaluation(0, x+1)>=need);
                  }, 0, elts.size());
                if (count_elts.GetIntervalEvaluation(0, where+1)<need) {continue;}
                temp += sum_elts.GetIntervalEvaluation(0, where+1);
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
                ct++; ans.push_back( only_alice[get<2>(elts[i])].second + 1 );
                elts[i] = make_tuple(-1,-1,-1);
            }            
        }
        ct = 0;
        forr(i,0,elts.size()) {
            if (ct==max(k-min_i,0LL)) {break;}
            if (get<1>(elts[i]) == 1) {
                ct++; ans.push_back( only_bob[get<2>(elts[i])].second + 1 );
                elts[i] = make_tuple(-1,-1,-1);
            }            
        }
        ct = 0;
        forr(i,0,elts.size()) {
            if (ct==min_need) {break;}
            if (get<1>(elts[i]) == 0) {
                ct++; ans.push_back( only_alice[get<2>(elts[i])].second + 1 );
            }            
            if (get<1>(elts[i]) == 1) {
                ct++; ans.push_back( only_bob[get<2>(elts[i])].second + 1 );
            }            
            if (get<1>(elts[i]) == 2) {
                ct++; ans.push_back( noonelikes[get<2>(elts[i])].second + 1 );
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