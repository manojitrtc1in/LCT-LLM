

















using namespace std;


const int MOD_A = 961748941;
const int MOD_B = 1000000007;
const int MOD_C = 920419823;

bool printA = false;
bool printB = false;

namespace phillypham {
  class priority_queue {
  private:
    int keys_size;
    vector<int> keys;
    vector<long long> values;
    unordered_map<int, int> keyToIdx;
    int parent(int idx) {
      return (idx + 1)/2 - 1;
    }
    int left(int idx) {
      return 2*(idx+1) - 1;
    }
    int right(int idx) {
      return 2*(idx+1);
    }
    void heap_swap(int i, int j) {
      if (i != j) {
        keyToIdx[keys[j]] = i;
        keyToIdx[keys[i]] = j;
        swap(values[j], values[i]);
        swap(keys[j], keys[i]);
      }
    }
    void max_heapify(int idx) {
      int lIdx = left(idx);
      int rIdx = right(idx);
      int id9 = idx;
      if (lIdx < keys_size && values[lIdx] < values[id9]) {
        id9 = lIdx;
      }
      if (rIdx < keys_size && values[rIdx] < values[id9]) {
        id9 = rIdx;
      }
      if (id9 != idx) {
        heap_swap(id9, idx);
        max_heapify(id9);
      } 
    }
    
    void min_heapify(int idx)  {
      while (idx > 0 && values[parent(idx)] > values[idx]) {
        heap_swap(parent(idx), idx);
        idx = parent(idx);
      }
    }
    
  public:
    priority_queue(int N) {
      keys_size = 0;
      keys.clear(); keys.reserve(N);
      values.clear(); values.reserve(N);
      keyToIdx.clear(); keyToIdx.reserve(N);
    }
    void push(int key, long long value) {
      

      int idx = keys_size; ++keys_size;
      if (keys_size > keys.size()) {
        keys.push_back(key);
        values.push_back(value);
      } else {
        keys[idx] = key;
        values[idx] = value;
      }   
      keyToIdx[key] = idx;
      min_heapify(idx);      
    }

    void increase_key(int key, long long value) {
      

      

      values[keyToIdx[key]] = value;
      max_heapify(keyToIdx[key]);
    }

    void decrease_key(int key, long long value) {
      

      

      values[keyToIdx[key]] = value;
      min_heapify(keyToIdx[key]);       
    }

    void pop() {
      if (keys_size > 0) {
        heap_swap(0, --keys_size);
        keyToIdx.erase(keys[keys_size]);       
        if (keys_size > 0) max_heapify(0);
      } else {
        throw logic_error("priority queue is empty");
      }
    }
    int top() {
      return keys.front();
    }    

    int size() {
      return keys_size;
    }

    bool empty() {
      return keys_size == 0;
    }

    int at(int key) {
      return values[keyToIdx[key]];
    }

    int count(int key) {
      return keyToIdx.count(key);
    }

    string to_string() {
      ostringstream out;
      copy(keys.begin(), keys.begin() + keys_size, ostream_iterator<int>(out, " "));
      out << '\n';
      copy(values.begin(), values.begin() + keys_size, ostream_iterator<int>(out, " "));
      out << '\n';      
      return out.str();
    }    
  };
}



vector<pair<long long, unordered_set<int>>> id8(int s, const vector<unordered_map<int, pair<int, int>>> &edgeList) {
  int N = edgeList.size();
  vector<pair<long long, unordered_set<int>>> distance(N, make_pair(LLONG_MAX/3, unordered_set<int>()));
  phillypham::priority_queue pq(N);
  distance[s].first = 0;
  pq.push(s, 0);
  while (!pq.empty()) {  
    int currentVertex = pq.top(); pq.pop();
    long long currentDistance = distance[currentVertex].first;
    

    for (pair<int, pair<int, int>> entry : edgeList[currentVertex]) {
      int nextVertex = entry.first; int length = entry.second.first;
      long long newDistance = currentDistance + length;
      if (distance[nextVertex].first > newDistance) {
        distance[nextVertex].first = newDistance;
        distance[nextVertex].second.clear();
        distance[nextVertex].second.insert(currentVertex);
        if (pq.count(nextVertex)) {
          pq.decrease_key(nextVertex, newDistance);
        } else {
          pq.push(nextVertex, newDistance);
        }
      } else if (distance[nextVertex].first == newDistance) {        
        distance[nextVertex].second.insert(currentVertex);
      }
    }
  }
  return distance;
}

void dfs(int vertex, 
         const vector<pair<long long, unordered_set<int>>> &children,
         vector<long long> &pathCounts) {
  ++pathCounts[vertex];
  for (int nextVertex : children[vertex].second) {
    dfs(nextVertex, children, pathCounts);
  }  
}

long long countPaths(int vertex, const vector<pair<long long, unordered_set<int>>> &distances,
                     vector<long long> &pathCounts) {
  if (pathCounts[vertex]) {
    return pathCounts[vertex];
  } else {
    for (int parent : distances[vertex].second) {
      pathCounts[vertex] += countPaths(parent, distances, pathCounts);
    }
  }
  return pathCounts[vertex];
}

tuple<int, int, int> id10(tuple<int, int, int> a, tuple<int, int, int> b) {
  return make_tuple((get<0>(a) + get<0>(b)) % MOD_A, (get<1>(a) + get<1>(b)) % MOD_B, (get<2>(a) + get<2>(b)) % MOD_C);
}

tuple<int, int, int> id1(tuple<int, int, int> a, tuple<int, int, int> b) {
  long long a0 = get<0>(a);
  long long a1 = get<1>(a);
  long long a2 = get<2>(a);
  return make_tuple((a0*get<0>(b)) % MOD_A, (a1*get<1>(b)) % MOD_B, (a2*get<2>(b)) % MOD_C);
}

vector<tuple<int, int, int>> id5(int s, 
                              const vector<pair<long long, unordered_set<int>>> &distances,
                              const vector<pair<long long, unordered_set<int>>> &children) {
  

  int N = children.size();
  vector<tuple<int, int, int>> pathCounts(N, make_tuple(0, 0, 0)); 
  pathCounts[s] = make_tuple(1, 1, 1);
  phillypham::priority_queue pq(N);
  

  vector<bool> added(N, false);
  

  pq.push(s, 0);
  added[s] = true;
  while (!pq.empty()) {
    

    int currentVertex = pq.top(); pq.pop();  
    for (int nextVertex : children[currentVertex].second) {
      

      

      

      

      

      

      

      

      

      

      

      

      

      pathCounts[nextVertex] = id10(pathCounts[currentVertex], pathCounts[nextVertex]);
      

      

      if (!pq.count(nextVertex)) {
        

        pq.push(nextVertex, distances[nextVertex].first);
        added[nextVertex] = true;
      }
    }    
  }
  return pathCounts;
}

int main(int argc, char *argv[]) {
  clock_t start_time = std::clock();
  

  

  

  

  

  

  

  

  

  

  

  

  

  ios::sync_with_stdio(false); cin.tie(NULL);
  int N, M, s, t; 

  cin >> N >> M >> s >> t;
  --s; --t;                     

  vector<tuple<int, int, int>> edges;
  vector<unordered_map<int, pair<int, int>>> edgeList(N);
  vector<unordered_map<int, pair<int, int>>> id2(N);
  for (int m = 0; m < M; ++m) { 

    int a, b, l;
    cin >> a >> b >> l;
    if (m == 0 && a == 8360) printA = true;
    --a; --b;
    edges.emplace_back(a, b, l);
    if (!edgeList[a].count(b) || edgeList[a][b].first > l) {
      edgeList[a][b] = make_pair(l, 1);
      id2[b][a] = make_pair(l, 1);
    } else if (edgeList[a][b].first == l) {
      ++edgeList[a][b].second;
      ++id2[b][a].second;
    }
  } 
  if (N==20000 && M == 100000 && s == 0 && t == 19999 && printA) {
    

    

    printB = true;
  }
  

  

  vector<pair<long long, unordered_set<int>>> id3 = id8(s, edgeList);
  vector<pair<long long, unordered_set<int>>> id4 = id8(t, id2);
  

  

  

  

  

  

  

  

  

  

  

  vector<tuple<int, int, int>> pathCounts = id5(s, id3, id4);
  vector<tuple<int, int, int>> id0 = id5(t, id4, id3);
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  for (int i = 0; i < N; ++i) pathCounts[i] = id1(pathCounts[i], id0[i]);
  

  
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  
  long long id6 = id3[t].first;
  tuple<int, int, int> id7 = pathCounts[s];
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  for (tuple<int, int, int> edge : edges) {
    long long pathDistance = id3[get<0>(edge)].first + get<2>(edge) + id4[get<1>(edge)].first;
    if (pathDistance == id6 && 

        pathCounts[get<0>(edge)] == id7 && 

        pathCounts[get<1>(edge)] == id7 && 

        id3[get<1>(edge)].second.size() == 1 && 

        edgeList[get<0>(edge)][get<1>(edge)].second == 1) {
      cout << "YES" << '\n';
    } else if (pathDistance - get<2>(edge) + 1 < id6) {
      cout << "CAN" << ' ' << (pathDistance - id6) + 1 << '\n';
    } else {
      

      cout << "NO" << '\n';
    }
  }
  cout << flush;
  return 0;
}
























































































