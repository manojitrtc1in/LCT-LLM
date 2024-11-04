

















using namespace std;

















	

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

template <typename T>
void print_array(T arr[], int size_arr){
	rep(i, 0, size_arr){
		cout << arr[i];
		if(i == size_arr - 1) cout << endl;
		else cout << " ";
	}
}

template<typename T>
void print_vector(vector<T> v){
	rep(i, 0, v.size()){
		cout << v[i];
		if(i == v.size() - 1) cout << endl;
		else cout << " ";
	}
}

template <typename T>
void id0(T arr[], T value, int size_arr){
	rep(i, 0, size_arr){
		arr[i] = value;
	}
}



bool id2(string a, string b){
	rep(i, 0, min(a.length(), b.length())){
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return a.length() < b.length();
}

struct lex_string
{
	bool operator()(string a, string b){
		return id2(a, b);
	}
};



















bool contain_loop(list<int> graph[], int num_node){
	

	

	int num_edges = 0;
	for(int i = 0; i < num_node; i++) num_edges += graph[i].size();
	num_edges /= 2;
	if(num_edges >= num_node) return true;
	else return false;
}

bool contain_loop(list<int> graph[], vector<int>& nodes, int num_node){
	

	

	

	int id3 = nodes.size();
	int num_edges = 0;
	for(int i = 0; i < id3; i++) num_edges += graph[nodes[i]].size();
	num_edges /= 2;
	if(num_edges >= id3) return true;
	else return false;
}

vector<int> id6(list<int> graph[], int num_node){
	

	

	

	


	if(!contain_loop(graph, num_node)) return vector<int>();
	int root = 0;
	

	int parent[num_node]; 
	for(int i = 0; i < num_node; i++) parent[i] = -1;
	int level[num_node];
	for(int i = 0; i < num_node; i++) level[i] = -1;
	parent[root] = root;
	level[root] = 0;

	queue<int> q;
	q.push(root);
	int first_point, second_point;
	

	

	

	

	rep(LEVEL, 1, num_node+1){
		bool found = false;
		

		int size = q.size();
		

		rep(j, 0, size){
			int current_node = q.front(); q.pop();
			for(list<int>::iterator it = graph[current_node].begin(); it != graph[current_node].end(); it++){
				int node = *it;
				

				

				if(parent[node] == -1){
					parent[node] = current_node;
					level[node] = level[current_node] + 1;
					q.push(node);
				}
				else if(node != parent[current_node]){
					

					first_point = current_node;
					second_point = node;
					found = true;
				}
			}
		}
		if(found) break;
	}

	

	int first_runner = first_point, second_runner = second_point;
	

	for(int i = 0; i < level[first_runner] - level[second_runner]; i++) second_runner = parent[second_runner];
	for(int i = 0; i < level[second_runner] - level[first_runner]; i++) first_runner = parent[first_runner];
	while(first_runner != second_runner){
		first_runner = parent[first_runner];
		second_runner = parent[second_runner];
	}
	

	vector<int> first_path(level[first_point] - level[first_runner] + 1);
	vector<int> second_path(level[second_point] - level[second_runner] + 1);
	first_path[0] = first_point;
	second_path[0] = second_point;
	for(int i = 1; i < first_path.size(); i++) first_path[i] = parent[first_path[i-1]];
	for(int i = 1; i < second_path.size(); i++) second_path[i] = parent[second_path[i-1]];
	

	vector<int> cycle;
	for(int i = first_path.size() - 1; i >= 0; i--) cycle.push_back(first_path[i]);
	for(int i = 0; i < second_path.size(); i++) cycle.push_back(second_path[i]);
	return cycle;
}

vector<int> id6(list<int> graph[], vector<int>& nodes, int num_node){
	

	

	

	

	

	


	

	if(!contain_loop(graph, nodes, num_node)) return vector<int>();
	

	int id3 = nodes.size();
	int root = nodes[0];
	

	int parent[num_node]; 
	for(int i = 0; i < num_node; i++) parent[i] = -1;
	int level[num_node];
	for(int i = 0; i < num_node; i++) level[i] = -1;
	parent[root] = root;
	level[root] = 0;

	queue<int> q;
	q.push(root);
	int first_point, second_point;
	

	

	

	

	rep(LEVEL, 1, id3+1){
		bool found = false;
		

		int size = q.size();
		

		rep(j, 0, size){
			int current_node = q.front(); q.pop();
			for(list<int>::iterator it = graph[current_node].begin(); it != graph[current_node].end(); it++){
				int node = *it;
				

				

				if(parent[node] == -1){
					parent[node] = current_node;
					level[node] = level[current_node] + 1;
					q.push(node);
				}
				else if(node != parent[current_node]){
					

					first_point = current_node;
					second_point = node;
					found = true;
				}
			}
		}
		if(found) break;
	}

	

	int first_runner = first_point, second_runner = second_point;
	

	for(int i = 0; i < level[first_runner] - level[second_runner]; i++) second_runner = parent[second_runner];
	for(int i = 0; i < level[second_runner] - level[first_runner]; i++) first_runner = parent[first_runner];
	while(first_runner != second_runner){
		first_runner = parent[first_runner];
		second_runner = parent[second_runner];
	}
	

	vector<int> first_path(level[first_point] - level[first_runner] + 1);
	vector<int> second_path(level[second_point] - level[second_runner] + 1);
	first_path[0] = first_point;
	second_path[0] = second_point;
	for(int i = 1; i < first_path.size(); i++) first_path[i] = parent[first_path[i-1]];
	for(int i = 1; i < second_path.size(); i++) second_path[i] = parent[second_path[i-1]];
	

	vector<int> cycle;
	for(int i = first_path.size() - 1; i >= 0; i--) cycle.push_back(first_path[i]);
	for(int i = 0; i < second_path.size(); i++) cycle.push_back(second_path[i]);
	return cycle;
}

vector<int> connected_component(list<int> graph[], int num_node){
	vector<int> component;
	component.assign(num_node, -1);
	int next_component = 0;
	for(int i = 0; i < num_node; i++){
		if(component[i] != -1) continue;
		stack<int> st;
		st.push(i);
		component[i] = next_component;
		while(!st.empty()){
			int head = st.top(); st.pop();
			for(list<int>::iterator it = graph[head].begin(); it != graph[head].end(); it++){
				if(component[*it] == -1){
					component[*it] = next_component;
					st.push(*it);
				}
			}
		}
		next_component++;
	}
	return component;
}

int id7(list<int> graph[], int num_node){
	

	vector<int> component = connected_component(graph, num_node);
	int num_cc = 0;
	for(int i = 0; i < component.size(); i++) num_cc = max(num_cc, component[i]);
	return num_cc;
}

vector<int> id4(list<int> graph[], int root, int num_node){
	

	

	

	vector<int> dist;
	dist.assign(num_node, -1);
	dist[root] = 0;

	queue<int> q; 
	q.push(root);
	while(!q.empty()){
		int head = q.front(); q.pop();
		for(list<int>::iterator it = graph[head].begin(); it != graph[head].end(); it++){
			if(dist[*it] == -1){
				dist[*it] = dist[head] + 1;
				q.push(*it);
			}
		}
	}
	return dist;
}

vector<int> id8(list<int> graph[], int src, int dst, int num_node){
	

	


	assert(src < num_node && dst < num_node);
	vector<int> dist = id4(graph, dst, num_node);
	
	

	if(dist[src] == -1) return vector<int>();

	vector<int> path(dist[src]+1);
	path[0] = src;
	for(int i = 1; i < path.size(); i++){
		for(list<int>::iterator it = graph[path[i-1]].begin(); it != graph[path[i-1]].end(); it++){
			if(dist[*it] == dist[path[i-1]] - 1){
				path[i] = *it;
				break;
			}
		}
	}
	return path;
}


const int MAX_SIZE = 1e5+5;
list<int> graph[MAX_SIZE];
int t, n, m;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--){
		

		cin >> n >> m;
		

		rep(i, 0, n) graph[i].clear();
		

		rep(i, 0, m){
			int a, b; cin >> a >> b;
			a--; b--;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		

		vector<int> component = connected_component(graph, n);
		int num_component = 0;
		for(int i = 0; i < component.size(); i++) num_component = max(num_component, component[i]);
		

		num_component++;
		

		vector<int> nodes[num_component];
		rep(i, 0, n) nodes[component[i]].pb(i); 
		
		

		

		int values[n]; id0(values, 0, n);
		bool have_answer = false;
		rep(COMPO, 0, num_component){
			int sum_degree = 0;
			int max_degree = 0;
			int id5 = -1;
			int id1 = 0;
			int degree_three_nodes[2];

			

			rep(i, 0, nodes[COMPO].size()){
				sum_degree += graph[nodes[COMPO][i]].size();
				if(graph[nodes[COMPO][i]].size() > max_degree){
					max_degree = max(max_degree, (int)graph[nodes[COMPO][i]].size());
					id5 = nodes[COMPO][i];
				}
				if(graph[nodes[COMPO][i]].size() == 3 && id1 < 2){
					degree_three_nodes[id1] = nodes[COMPO][i];
					id1 += 1;
				}
			}
			int num_edges = sum_degree/2;
			if(num_edges >= nodes[COMPO].size()){
				cout << "YES" << endl;
				

				vector<int> loop = id6(graph, nodes[COMPO], n);
				

				rep(i, 0, loop.size()-1) values[loop[i]] = 1;
				print_array(values, n);
				have_answer = true;
				break;
			}
			

			else if(max_degree >= 4){
				cout << "YES" << endl;
				values[id5] = 2;
				for(list<int>::iterator it = graph[id5].begin(); it != graph[id5].end(); it++){
					values[*it] = 1;
				}
				print_array(values, n);
				have_answer = true;
				break;
			}
			

			else if(id1 >= 2){
				cout << "YES" << endl;
				vector<int> path = id8(graph, degree_three_nodes[0], degree_three_nodes[1], n);
				rep(i, 0, path.size()) values[path[i]] = 2;
				for(list<int>::iterator it = graph[degree_three_nodes[0]].begin(); it != graph[degree_three_nodes[0]].end(); it++){
					if(values[*it] == 0){
						values[*it] = 1;
					}
				}
				for(list<int>::iterator it = graph[degree_three_nodes[1]].begin(); it != graph[degree_three_nodes[1]].end(); it++){
					if(values[*it] == 0){
						values[*it] = 1;
					}
				}
				print_array(values, n);
				have_answer = true;
				break;
			}
			

			

			

			else if(id1 == 1){
				int root = degree_three_nodes[0];
				int branches_size[3] = {0,0,0};
				vector<int> branches_nodes[3];
				vector<int> subroots;
				for(list<int>::iterator it = graph[root].begin(); it != graph[root].end(); it++){
					subroots.pb(*it);
				}
				set<int> visited;
				for(int i = 0; i < 3; i++){
					visited.clear();
					visited.insert(root);
					branches_nodes[i].pb(root);
					int next_node = subroots[i];
					while(true){
						visited.insert(next_node);
						branches_nodes[i].pb(next_node);
						bool finished = true;
						for(list<int>::iterator it = graph[next_node].begin(); it != graph[next_node].end(); it++){
							if(visited.find(*it) == visited.end()){
								next_node = *it;
								finished = false;
								break;
							}
						}
						if(finished) break;
					}
					branches_size[i] = branches_nodes[i].size();
				}
				

				for(int i = 0; i < 3; i++) branches_size[i] = min(10, branches_size[i]);
				if(branches_size[0]*branches_size[1] + branches_size[1]*branches_size[2] + branches_size[2]*branches_size[0] <= 
					branches_size[0]*branches_size[1]*branches_size[2]){
					cout << "YES" << endl;
					ll ROOT = branches_size[0] * branches_size[1] * branches_size[2];
					values[root] = ROOT;
					for(int i = 0; i < 3; i++){
						for(int j = 1; j < branches_size[i]; j++){
							values[branches_nodes[i][j]] = values[branches_nodes[i][j-1]] * (branches_size[i] - j) / (branches_size[i] - j + 1);
						}
					}
					print_array(values, n);
					have_answer = true;
					break;
				}
			}
			

			

		}
		if(!have_answer) cout << "NO" << endl;
	}

	return 0;
}