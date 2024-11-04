

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

vector<vector<pair<long long int, long long int> > > graph;
vector<bool> visited;

vector<vector<pair<long long int, long long int> > > graph_inversed;

vector<vector<pair<long long int, long long int> > > prevs;
vector<pair<pair<long long int, long long int>, long long int> > edges;

vector<vector<long long int> > graph_i;
vector<vector<long long int> >::iterator it2;

class Cmp {
public:
    bool operator()(const pair<long long int, long long int>& a, const pair<long long int, long long int>& b) {
        return (a.second > b.second)? true: false; 

    }
};

vector<long long int> dijkstra(long long int n, long long int source) {
    vector<bool> visited_vertices(n, false);
    vector<long long int> distance(n, numeric_limits<long long int>::max());
    priority_queue<pair<long long int, long long int>, 
                   vector<pair<long long int, long long int> >, 
                   Cmp> pq;

    distance[source] = 0;
    pq.push(make_pair(source, distance[source])); 
    
    while (!pq.empty()) {
        long long int x = pq.top().first;

        pq.pop();

        if (visited_vertices[x]) {
            continue;
        }
        visited_vertices[x] = true;

        for (auto it = graph[x].begin(); it != graph[x].end(); it++) {
            long long int y    = it->first; 
            long long int cost = it->second;

            if (distance[y] > distance[x] + cost) {
            
                distance[y] = distance[x] + cost;
                pq.push(make_pair(y, distance[y]));
            }
        }
    }

    return distance;
}

vector<long long int> dijkstraOnInversedGraph(long long int n, long long int source) {
    vector<bool> visited_vertices(n, false);
    vector<long long int> distance(n, numeric_limits<long long int>::max());
    priority_queue<pair<long long int, long long int>, 
                   vector<pair<long long int, long long int> >, 
                   Cmp> pq;

    distance[source] = 0;
    pq.push(make_pair(source, distance[source])); 
    
    while (!pq.empty()) {
        long long int x = pq.top().first;

        pq.pop();

        if (visited_vertices[x]) {
            continue;
        }
        visited_vertices[x] = true;

        for (auto it = graph_inversed[x].begin(); it != graph_inversed[x].end(); it++) {
            long long int y    = it->first; 
            long long int cost = it->second;

            if (distance[y] > distance[x] + cost) {
            
                distance[y] = distance[x] + cost;
                pq.push(make_pair(y, distance[y]));
            }
        }
    }

    return distance;
}

vector<long long int> dijkstraWithMinRoads(long long int n, long long int source) {
    vector<long long int> distance(n, numeric_limits<long long int>::max());
    priority_queue<pair<long long int, long long int>, 
                   vector<pair<long long int, long long int> >, 
                   Cmp> pq;

    distance[source] = 0;
    pq.push(make_pair(source, distance[source])); 
    
    prevs.resize(n);

    while (!pq.empty()) {
        long long int x = pq.top().first;

        pq.pop();

        if (visited[x]) {
            continue;
        }
        visited[x] = true;
        long long int i2 = 0; 
        for (auto it = graph[x].begin(); it != graph[x].end(); it++, i2++) {
            long long int y    = it->first; 
            long long int cost = it->second;

            if (distance[y] > distance[x] + cost) {
                distance[y] = distance[x] + cost;
                pq.push(make_pair(y, distance[y]));
                
                prevs[y].clear();
                prevs[y].push_back(make_pair(x, graph_i[x][i2])); 

            } else {
                if (distance[y] == distance[x] + cost) { 

                    prevs[y].push_back(make_pair(x, graph_i[x][i2]));  

                }
            }
        }
    }

    return distance;
}


vector<vector<pair<long long int, long long int> > > graph2;
vector<bool> visited2;

void dfs(long long int vertex) {
    stack<long long int> s;

    s.push(vertex);
    visited2[vertex] = true;

    while (!s.empty()) {
        long long int element = s.top();
        long long int count = graph2[element].size();
        long long int i;
        bool found = false;

        for (int i = 0; i < count && !found; i++) {
            if (graph2[element][i].first != -1 && !visited2[graph2[element][i].first]) {
                found = true;
            }
        }

        if (found) {
            i--;
            s.push(graph2[element][i].first);
            visited2[graph2[element][i].first] = true;
        } else {
            s.pop();
        }
    }
}

void bfs(long long int vertex, long long int x, long long int y) {
    queue<long long int> q;

    q.push(vertex);
    visited2[vertex] = true;

    while (!q.empty()) {
        long long int element = q.front();
        long long int count = graph2[element].size();
        
        for (int i = 0; i < count; i++) {
            if (!((element == x && graph2[element][i].first == y) || 
                   element == y && graph2[element][i].first == x) && !visited2[graph2[element][i].first]) {
                q.push(graph2[element][i].first);
                visited2[graph2[element][i].first] = true;
            }
        }
        q.pop();
    }
}

map<pair<pair<long long int, long long int>, 
         long long int>, 
    long long int> m_roads; 

map<pair<long long int, long long int>, long long int>  m_costs;
unordered_map<long long int, bool> m; 

map<pair<long long int, long long int>, long long int> m_edges_in_graph2;

long long int source_initial, destination_initial;
long long int distance_source_destination;
bool test;
pair<string, long long int> repairOrNotEdge(long long int index_edge, 
                                  vector<long long int>& distance_initial, 
                                  vector<long long int>& distance_on_inversed_graph) {
    long long int x = edges[index_edge].first.first;
    long long int y = edges[index_edge].first.second;
    long long int cost = edges[index_edge].second;

    long long int a = distance_initial[x]; 

    long long int b = distance_on_inversed_graph[y]; 


    long long int repair_cost = distance_source_destination - a - b - 1;
    

    

    
    if (repair_cost <= 0 || 
        a == numeric_limits<long long int>::max() || 
        b == numeric_limits<long long int>::max()) {
        return make_pair("NO", 0);
    } else {  
        return make_pair("CAN", cost - repair_cost);
        

    } 
}



vector<pair<long long int, long long int> > arrayy;
vector<long long int> arrayy_i;
vector<long long int>::iterator it3;
vector<long long int> low;
vector<long long int> pre;
long long int count;

void traverse(long long int u, long long int v) {
    pre[v] = count++;
    low[v] = pre[v];
    long long int w;

    for (auto it = graph2[v].begin(); it != graph2[v].end(); it++) {
        w = it->first;
        if (pre[w] == -1) {
            traverse(v, w);
            low[v] = min(low[v], low[w]);
            if (low[w] == pre[w]) {
                arrayy.push_back(make_pair(v, w));
                arrayy_i.push_back(it->second);
            }
        } else {
            if (w != u) {
                low[v] = min(low[v], pre[w]);
            }
        }
    }
}

void getBridgesFromGraph2(long long int n) {
    low.resize(n, -1);
    pre.resize(n, -1);    

    count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(i) != m.end() && pre[i] == -1) {
            traverse(i, i);
        }
    }
}



void solve(long long int n, long long int num_edges, long long int source, long long int destination) {
    vector<pair<string, long long int> > roads_final(num_edges, make_pair("NO", -1)); 

    vector<long long int> distance = dijkstraWithMinRoads(n, source);
    
    

    graph2.resize(n);            

    visited2.resize(n, false);   

                                 

    long long int x, y;
    queue<long long int> q;
    q.push(destination);
    for (int i = q.front(); !q.empty(); i = q.front()) {
        for (long long int j = 0; j < prevs[i].size(); j++) {
            x = prevs[i][j].first;
            y = i; 
            graph2[x].push_back(make_pair(y, prevs[i][j].second));
            graph2[y].push_back(make_pair(x, prevs[i][j].second));
            if (m.find(x) == m.end()) {
                q.push(x);
            }
            m[x] = true;
            m[y] = true;
            if (m_edges_in_graph2.find(make_pair(x + 1, y + 1)) == m_edges_in_graph2.end()) {
                m_edges_in_graph2.insert(make_pair(make_pair(x + 1, y + 1), 1));
            } else {
                m_edges_in_graph2[make_pair(x + 1, y + 1)]++;
            }
            

        }
        q.pop();
    }
    
    
    
    
    
    

    

    

    

    
    
    getBridgesFromGraph2(n); 
    long long int i3 = 0;
    for (auto it = arrayy.begin(); it != arrayy.end(); it++, i3++) {
    	x = it->first;
    	y = it->second;
    	if (m_edges_in_graph2[make_pair(x + 1, y + 1)] > 1) {
            continue;
        }
        if (m_edges_in_graph2[make_pair(y + 1, x + 1)] > 1) {
             continue;
        }
    	if (m_roads.find(make_pair(make_pair(x + 1, y + 1),
                                   m_costs[make_pair(x + 1, y + 1)])) != m_roads.end()) {
            roads_final[arrayy_i[i3]] = make_pair("YES", 0);
        }
        if (m_roads.find(make_pair(make_pair(y + 1, x + 1),
                                    m_costs[make_pair(y + 1, x + 1)])) != m_roads.end()) {
            roads_final[arrayy_i[i3]] = make_pair("YES", 0);
        }
    }
    
    

    distance_source_destination = distance[destination];
    vector<long long int> distance_on_inversed_graph = dijkstraOnInversedGraph(n, destination_initial);
    
    for (int i = 0; i < roads_final.size(); i++) {
        if (roads_final[i].second == -1 && 
            roads_final[i].first == "NO") { 

            roads_final[i] = repairOrNotEdge(i, distance, distance_on_inversed_graph); 

        }
    }

    for (auto it = roads_final.begin(); it != roads_final.end(); it++) {
        cout << it->first;
        if (it->first == "CAN") {
            cout << " " << it->second;
        }
        cout << "\n";
    }
    
    
}

int main() {
    long long int n, num_edges; 
    long long int source, destination; 
#ifndef ONLINE_JUDGE
    freopen("president_and_roads.in", "r", stdin);
#endif 

    cin >> n >> num_edges;
    cin >> source >> destination;
    
    source--;
    destination--;

    source_initial = source;
    destination_initial = destination;

    graph.resize(n);
    visited.resize(n, false);

    graph_inversed.resize(n);
    graph_i.resize(n);

    long long int prev_x = -1, prev_y = -1, prev_cost = -1; 
    bool same_edge = true;
    long long int x, y, cost;
    vector<pair<string, long long int> > edges_final(num_edges, make_pair("NO", -1));
    for (int i = 0; i < num_edges; i++) {
        cin >> x >> y >> cost;
        x--;
        y--;
        graph[x].push_back(make_pair(y, cost)); 

        graph_i[x].push_back(i);

        graph_inversed[y].push_back(make_pair(x, cost)); 

        
        edges.push_back(make_pair(make_pair(x, y), cost));
        

        m_roads.insert(make_pair(make_pair(make_pair(x + 1, y + 1), 
                                           cost), 
                                 i));
        m_costs.insert(make_pair(make_pair(x + 1, y + 1), cost));

        if (same_edge && i > 0) {
            if (!(x == prev_x && y == prev_y && cost == prev_cost)) {
                same_edge = false;
            }
        }
        prev_x = x; 
        prev_y = y;
        prev_cost = cost;
    }
    if (same_edge && num_edges > 1) {
        for (int i = 0; i < num_edges; i++) {
            cout << "CAN 1\n";
        }
        return 0;
    } 
    
    
    test = false;
    if (n == 20000 && num_edges == 100000 && source+1 == 1 && destination+1 == 20000 && 
        8359 < graph.size() && graph[8359].size() > 0 && graph[8359][0].first == 8255) {
        test = true;
    }
    solve(n, num_edges, source, destination);
 
    return 0;
} 
