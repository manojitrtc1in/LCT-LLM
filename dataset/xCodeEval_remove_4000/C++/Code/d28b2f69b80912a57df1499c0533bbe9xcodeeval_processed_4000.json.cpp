





























using namespace std;

struct RMQ {
	const static int MAXLENGTH = 2 * 1e5 + 3;
	const static int LOG_MAXLENGTH = 20;
	int rmq[MAXLENGTH][LOG_MAXLENGTH];

	int* arr;

	void init(int* x, int len) {
		arr = x;

		for (int i = 0; i < len; i++)
	        rmq[i][0] = arr[i];
	    for (int j = 1; j < LOG_MAXLENGTH; j++)
	        for (int i = 0; i < len; i++) {
	            if (i + (1 << j) > len)
	                break;
	            rmq[i][j] = rmq[i][j - 1];
	           	rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j-1]);
	        }
	}

	int id2(int l, int r) {
	    if (l > r)
	        swap(l, r);

	    int interval_len = r - l;

	    int first_half = 1;
	    while ((1 << first_half) <= interval_len)
	        first_half++;
	    first_half--;

	    int second_half = r - (1 << first_half) + 1;
	    return min(rmq[l][first_half], rmq[second_half][first_half]);
	}
};

struct Graph {
    struct Edge {
        int to;
    };

    const static int MAXNODE = 1 * 1e5 + 2;
    const static int LOG_MAXNODE = 20;

    vector<int> g[MAXNODE];
    vector<Edge> edge;
    int n;

    int root = 1;

    void init(int nn) {
        n = nn;
        for (int i = 0; i <= n; i++)
            g[i].clear();
        edge.clear();
    }

    void add_e(int x, int y) {
        g[x].push_back(edge.size());
        edge.push_back((Edge){y});

        g[y].push_back(edge.size());
        edge.push_back((Edge){x});
    }

    void show() {
        for (int i = 0; i <= n; i++) {
            printf("%d:", i);
            for (int ie : g[i])
                printf(" %d", edge[ie].to);
            printf("\n");
        }
        printf("\n");
    }

    

    

    

	int dis_to_root[MAXNODE];

	int first_visit_time[MAXNODE];
	int visit[2 * MAXNODE]; 

	int visit_counter;
	int rmq[2 * MAXNODE][LOG_MAXNODE];

	int id2(int l, int r) { 

	    if (l > r)
	        swap(l, r);

	    int interval_len = r - l; 


	    int first_half = 1;
	    while ((1 << first_half) <= interval_len)
	        first_half++;
	    first_half--;

	    int second_half = r - (1 << first_half) + 1;
	    if (first_visit_time[rmq[l][first_half]] < first_visit_time[rmq[second_half][first_half]])
	        return rmq[l][first_half];
	    return rmq[second_half][first_half];
	}

	int id4(int x, int y) {
		return id2(first_visit_time[x], first_visit_time[y]);
	}

	int dist(int x, int y) {
	    int lca = id4(x, y);
	    return dis_to_root[x] + dis_to_root[y] - 2 * dis_to_root[lca];
	}

	void id8(int cur) {
	    visit[++visit_counter] = cur; 

	    if (first_visit_time[cur] == 0) 

	        first_visit_time[cur] = visit_counter; 

	    for (int ie : g[cur]) {
	    	const Edge& e = edge[ie];
	    	int nx = e.to;
	        if (first_visit_time[nx] == 0) {
		        dis_to_root[nx] = dis_to_root[cur] + 1; 

		        id8(nx);
		        visit[++visit_counter] = cur; 

	        }
	    }
	}

	void id1() {
		dis_to_root[root] = 0;
		fill_n(first_visit_time, n + 1, 0);

		visit_counter = 0;
	    id8(root);

	    for (int i = 0; i < visit_counter; i++)
	        rmq[i][0] = visit[i];
	    for (int j = 1; j < LOG_MAXNODE; j++)
	        for (int i = 0; i < visit_counter; i++) {
	            if (i + (1 << j) > visit_counter)
	                break;
	            rmq[i][j] = rmq[i][j - 1];
	            if (first_visit_time[rmq[i][j - 1]] > first_visit_time[rmq[i + (1 << (j - 1))][j - 1]])
	                rmq[i][j] = rmq[i + (1 << (j - 1))][j-1];
	        }
	}
	

	

	




    

    

    

	vector<int> centroid; 


	vector<int> subtree_size;
	vector<int> parent;
	
	vector<bool> deleted;
	int id5(int cur) {
		int& size = subtree_size[cur];
		for (int ie : g[cur]) {
			Edge& e = edge[ie];
			int nx = e.to;
			if (parent[nx] == -1) {
				parent[nx] = cur;
				size += id5(nx);
			}
		}
		return size;
	}

	void id7(int cur, int from, int tree_size) {
		int half_size = tree_size / 2;

		

		while (subtree_size[cur] <= half_size)
			cur = parent[cur];

		while (1) {
			int candidate = cur;
			for (int ie : g[cur]) {
				const Edge& e = edge[ie];
				int nx = e.to;
				if (!deleted[nx] && nx != parent[cur]) {
					if (subtree_size[nx] > half_size) {
						SHOW(cur, nx, subtree_size[nx], candidate)
						candidate = nx;
					}
				}
			}
			if (candidate == cur)
				break;
			cur = candidate;
		}

		deleted[cur] = true;
		centroid[cur] = from;

		int temp = parent[cur];
		

		while (!deleted[temp] && temp != parent[temp]) { 

			subtree_size[temp] -= subtree_size[cur];
			temp = parent[temp];
		}

		for (int ie : g[cur]) {
			const Edge& e = edge[ie];
			int nx = e.to;
			if (!deleted[nx]) {
				int id3; 

				if (nx == parent[cur])
					id3 = tree_size - subtree_size[cur];
				else {
					id3 = subtree_size[nx];
					

				}

				if (id3 == 1)
					centroid[nx] = cur; 

				else
					id7(nx, cur, id3);
			}
		}
	}

	void id7() {
		vector<int>(n + 1, -1).swap(centroid);
		vector<int>(n + 1, 1).swap(subtree_size); 

		vector<int>(n + 1, -1).swap(parent);
		vector<bool>(n + 1, false).swap(deleted);

		

		

		

		


		

		

		

		

		parent[root] = root;

		id5(root);
		for (int i = 0; i <= n; i++) {
			PRINTLN("size[%d] = %d", i, subtree_size[i])
		}

		id7(root, -1, n);
	}
    

    

    


	int min_dist[MAXNODE]; 

	void query(int city) {
		int ans = min_dist[city];
		int cur = city;
		while (cur != -1) { 

			int d = dist(cur, city) + min_dist[cur];
			if (ans > d)
				ans = d;
			cur = centroid[cur];
		}
		printf("%d\n", ans);
	}

	void update(int city) {
		int cur = city;
		while (cur != -1) { 

			int d = dist(cur, city);
			if (min_dist[cur] > d)
				min_dist[cur] = d;
			cur = centroid[cur];
		}
	}
    
    const int INF = 2000000;
    void init_else() {
    	id1();
    	id7();
    	fill(min_dist, min_dist + n + 1, INF);
    }    
};

const int MAX_NODE = 1 + (int)1e5 * 1;
const int id0 = 2 * MAX_NODE;
const int INF = 2000000;
const int id6 = 19;

int n;
int m;
vector<int> g[MAX_NODE];

int dis_to_root[MAX_NODE];

int first_visit_time[MAX_NODE];
int visit[id0]; 

int visit_counter;
int rmq[id0][id6];

int id2(int l, int r) {
    if (l > r)
        swap(l, r);

    int interval_len = r - l;

    int first_half = 1;
    while ((1 << first_half) <= interval_len)
        first_half++;
    first_half--;

    int second_half = r - (1 << first_half) + 1;
    if (first_visit_time[rmq[l][first_half]] < first_visit_time[rmq[second_half][first_half]])
        return rmq[l][first_half];
    return rmq[second_half][first_half];
}

int id4(int x, int y) {
	return id2(first_visit_time[x], first_visit_time[y]);
}

int dist(int x, int y) {
    int lca = id4(x, y);
    return dis_to_root[x] + dis_to_root[y] - 2 * dis_to_root[lca];
}

void id8(int cur) {
    visit[++visit_counter] = cur; 

    if (first_visit_time[cur] == 0) 

        first_visit_time[cur] = visit_counter; 

    for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        if (first_visit_time[next] == 0) {
	        dis_to_root[next] = dis_to_root[cur] + 1; 

	        id8(next);
	        visit[++visit_counter] = cur; 

        }
    }
}

void id1() {
    id8(1); 


    for (int i = 0; i < visit_counter; i++)
        rmq[i][0] = visit[i];
    for (int j = 1; j < id6; j++)
        for (int i = 0; i < visit_counter; i++) {
            if (i + (1 << j) > visit_counter)
                break;
            rmq[i][j] = rmq[i][j - 1];
            if (first_visit_time[rmq[i][j - 1]] > first_visit_time[rmq[i + (1 << (j - 1))][j - 1]])
                rmq[i][j] = rmq[i + (1 << (j - 1))][j-1];
        }
}

int min_dist[MAX_NODE]; 

int centroid[MAX_NODE]; 


void query(int city) {
	int ans = min_dist[city];
	int cur = city;
	while (cur != 0) { 

		int d = dist(cur, city) + min_dist[cur];
		if (ans > d)
			ans = d;
		cur = centroid[cur];
	}
	printf("%d\n", ans);
}

void update(int city) {
	int cur = city;
	while (cur != 0) { 

		int d = dist(cur, city);
		if (min_dist[cur] > d)
			min_dist[cur] = d;
		cur = centroid[cur];
	}
}

int subtree_size[MAX_NODE];
int parent[MAX_NODE];

int id5(int cur) {
	int& size = subtree_size[cur];
	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (!parent[next]) {
			parent[next] = cur;
			size += id5(next);
		}
	}
	return size;
}

bool deleted[MAX_NODE];
void id7(int cur, int from, int tree_size) {
	int half_size = tree_size / 2;

	while (cur != parent[cur] && subtree_size[cur] <= half_size)
		cur = parent[cur];

	while (1) {
		int candidate = cur;
		for (int i = 0; i < g[cur].size(); i++) {
			int next = g[cur][i];
			if (!deleted[next] && next != parent[cur])
				if (subtree_size[next] > half_size)
					candidate = next;
		}
		if (candidate == cur)
			break;
		cur = candidate;
	}

	deleted[cur] = true;
	centroid[cur] = from;
	int temp = parent[cur];
	while (temp != parent[temp]) { 

		subtree_size[temp] -= subtree_size[cur];
		temp = parent[temp];
	}

	for (int i = 0; i < g[cur].size(); i++) {
		int next = g[cur][i];
		if (!deleted[next]) {
			int next_tree; 

			if (next == parent[cur])
				next_tree = tree_size - subtree_size[cur];
			else {
				next_tree = subtree_size[next];
				parent[next] = next; 

			}
			if (next_tree == 1)
				centroid[next] = cur; 

			else
				id7(next, cur, next_tree);
		}
	}
}

Graph graph;
void init_tree() {
	graph.init(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);

		graph.add_e(a, b);
	}
	id1();

	fill(subtree_size, subtree_size + n + 1, 1); 

	parent[1] = 1;
	id5(1);

	id7(1, 0, n);

	fill(min_dist, min_dist + n + 1, INF);

	graph.init_else();
	

	

	

	

	

	

	


	

	

	

	

	

	

}
















int main() {
	scanf("%d %d", &n, &m);
	init_tree();

	graph.update(1);
	update(1);
	int q, c;
	while (m--) {
		scanf("%d %d", &q, &c);
		if (q == 1)
			graph.update(c);
		else
			graph.query(c);
		

		

		

		

	}
}

