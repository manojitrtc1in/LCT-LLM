










using namespace std;

const int INF = 2000000000;
class Thuge
{
private:
	vector<int> num;
	bool positive;
public:
	Thuge()
	{
		positive = true;
		num.resize(0);
	};
	Thuge(int a)
	{
		positive = true;
		if (a < 0)
		{
			positive = false;
			a *= -1;
		}
		while (a > 0)
		{
			num.push_back(a % 10);
			a /= 10;
		}
		if (num.size() == 0)
			num.push_back(0);
	};
	void createnum()
	{
		positive = true;
		char c;
		cin >> c;
		string s;
		if (c == '-')
			positive = false;
		else
			s += c;
		string tmp;
		cin >> tmp;
		s = s + tmp;
		for (unsigned int i = 0; i < s.size(); i++)
			num.push_back(s[s.size() - i - 1] - '0');
		if (num.size() == 0)
			num.push_back(0);
	};
	Thuge(string s)
	{
		for (unsigned int i = 0; i < s.size(); i++)
			num.push_back(s[s.size() - i - 1] - '0');
		if (num.size() == 0)
			num.push_back(0);
	};
	vector<int> getnum()
	{
		return num;
	}
	bool getPos()
	{
		return positive;
	}
	void printnum()
	{
		if (!positive)
			cout << "-";
		for (vector <int>::iterator i = num.begin(); i != num.end(); i++)
			cout << num[num.size() - (i - num.begin()) - 1];
	}
	void check_number()
	{
		while (num.size() > 1 && num[num.size() - 1] == 0)
		{
			num.pop_back();
		}
	}
	int compareThuge(const Thuge &b)
	{
		if (num.size() > b.num.size() || (positive && !b.positive))
			if (positive)
				return 1;
			else
				return -1;
		if (num.size() < b.num.size() || (!positive && b.positive))
			if (positive)
				return -1;
			else
				return 1;
		for (unsigned int i = 0; i < num.size(); i++)
		{
			if (num[i] > b.num[i] && positive)
				return 1;
			if (num[i] > b.num[i] && !positive)
				return -1;
			if (num[i] < b.num[i] && positive)
				return -1;
			if (num[i] < b.num[i] && !positive)
				return 1;
		}
		return 0;
	}
	bool operator ==(const Thuge &b)
	{
		if (compareThuge(b) == 0)
			return true;
		return false;
	}
	bool operator >(const Thuge &b)
	{
		if (compareThuge(b) == 1)
			return true;
		return false;
	}
	bool operator <(const Thuge &b)
	{
		if (compareThuge(b) == -1)
			return true;
		return false;
	}
	bool operator >=(const Thuge &b)
	{
		if (compareThuge(b) != -1)
			return true;
		return false;
	}
	bool operator <=(const Thuge &b)
	{
		if (compareThuge(b) != 1)
			return true;
		return false;
	}
	bool operator !=(const Thuge &b)
	{
		if (compareThuge(b) != 0)
			return true;
		return false;
	}
	Thuge operator =(Thuge &b)
	{
		num = b.num;
		positive = b.positive;
		return *this;
	};
	Thuge operator +(const Thuge &b);
	Thuge operator -(const Thuge &b)
	{
		Thuge c = b;
		if (positive != b.positive)
		{
			c.positive = !b.positive;
			return *this + c;
		}
		int k = 0;
		if (*this < b)
		{
			c = c - *this;
			c.positive = !b.positive;
			return c;
		}
		Thuge ans;
		ans.positive = positive;
		unsigned int i = 0, j = 0;
		while (i < num.size() || j < c.num.size())
		{
			if (i < num.size())
				k += num[i];
			if (j < c.num.size())
				k -= c.num[j];
			if (k < 0)
			{
				k = k + 10;
				if (j + 1 < c.num.size())
					c.num[j + 1] += 1;
				else
					c.num.push_back(1);
			}
			ans.num.push_back(k % 10);
			i++;
			k /= 10;
			j++;
		}
		if (k > 0)
			ans.num.push_back(k % 10);
		ans.check_number();
		return ans;
	}
	Thuge operator *(const Thuge &b)
	{
		unsigned int i = 0, j = 0;
		vector<Thuge>ans(1);
		ans[0].num.push_back(0);
		int kol0 = 0;
		while (i < num.size() && num[i] == 0)
		{
			kol0++;
			i++;
		}
		while (j < b.num.size() && b.num[j] == 0)
		{

			kol0++;
			j++;
		}
		if (i >= num.size() || j >= b.num.size())
		{
			return ans[0];
		}
		int r = 1;
		while (j < b.num.size())
		{
			ans.resize(ans.size() + 1);
			for (int i = 1; i < r; i++)
				ans[r].num.push_back(0);
			int k = 0;
			for (unsigned int p = i; p < num.size(); p++)
			{
				ans[r].num.push_back(num[p] * b.num[j] + k);
				k = ans[r].num[ans[r].num.size() - 1] / 10;
				ans[r].num[ans[r].num.size() - 1] %= 10;
			}
			if (k > 0)
				ans[r].num.push_back(k);
			r++;
			j++;
		}
		for (unsigned int i = 1; i < ans.size(); i++)
		{
			ans[0] = ans[0] + ans[i];
		}
		Thuge answer;
		for (int i = 0; i < kol0; i++)
			answer.num.push_back(0);
		for (unsigned int i = 0; i < ans[0].num.size(); i++)
			answer.num.push_back(ans[0].num[i]);
		if (positive != b.positive)
			answer.positive = false;
		return answer;
	}
	Thuge operator /(const Thuge &b)
	{
		Thuge d;
		d.num = b.num;
		Thuge ans;
		int i = 0;
		Thuge c;
		while (i < num.size())
		{
			while (i < num.size() && c < d)
			{
				c.num.push_back(num[i]);
				ans.num.push_back(0);
				i++;
			}
			if (i == num.size() && c < d)
				break;
			int j = 0;
			int p = 0;
			int l = 0;
			while (l == 0 && c.num.size()>j + 1)
			{
				p = p * 10 + c.num[c.num.size() - 1 - j];
				j++;
				l = p / d.num[d.num.size() - 1];
			}
			Thuge k(l);

			if (k*d > c)
				k.num[0]--;
			ans.num.push_back(k.num[0]);
			c = c - k*d;
		}
		reverse(ans.num.begin(), ans.num.end());
		ans.check_number();
		ans.positive = positive == b.positive;
		return ans;
	}
	Thuge operator % (const Thuge &b)
	{
		Thuge k = *this / b;
		return *this - k*b;
	}
};
Thuge Thuge::operator +(const Thuge &b)
{
	if (positive != b.positive)
	{
		Thuge c = b;
		c.positive = !b.positive;
		return *this - c;
	}
	int k = 0;
	Thuge ans;
	ans.positive = b.positive;
	unsigned int i = 0, j = 0;
	while (i < num.size() || j < b.num.size())
	{
		if (i < num.size())
			k += num[i];
		if (j < b.num.size())
			k += b.num[j];
		ans.num.push_back(k % 10);
		k = k / 10;
		i++;
		j++;
	}
	if (k > 0)
		ans.getnum().push_back(k % 10);
	return ans;
};


int id0(string s)
{
	int ans = 0;
	int k = 1;
	int i = s.size() - 1;
	while (i >= 0)
	{
		ans += (s[i] - '0')*k;
		k *= 10;
		i--;
	}
	return ans;
}
class edge
{
public:
	int from, to, cost;
	edge()
	{
		from = 0;
		to = 0;
		cost = 0;
	};
	edge(int a, int b, int c)
	{
		from = a;
		to = b;
		cost = c;
	};
	bool operator<(const edge &a) const
	{
		return from < a.from || (from == a.from && to < a.to) || (from == a.from && to == a.to && cost < a.cost);
	}
	bool operator==(const edge &a) const
	{
		return from == a.from && to == a.to && cost == a.cost;
	}
};
bool Comp(edge a, edge b)
{
	return a.cost < b.cost;
}
class graph
{
public:
	int n, m;
	int type;
	

	

	

	

	

	int timer;
	vector<vector<int> > g;
	vector<char> used;
	set<edge> e;
	vector<int> d;
	vector<int> tin;
	vector<int> fup;
	vector<int> dPrev;
	vector<vector<int> > dist;
	graph()
	{
		n = 0;
		m = 0;
		timer = 0;
		type = 0;
	};
	

	void set_Size()
	{
		int a, b;
		cin >> a >> b;
		n = a;
		m = b;
		if (type < 3)
			g.resize(n);
	};
	void set_Size(int a, int b = 0)
	{
		n = a;
		m = b;
		if (type < 3)
			g.resize(n);
	}
	

	void set_Type(int a = -1)
	{
		if (a == -1)
			cin >> a;
		type = a;
	}
	

	void CreateFromLAdj()
	{
		for (int p = 0; p < n; p++)
		{
			int i;
			cin >> i;
			i--;
			string s;
			getline(cin, s);
			size_t j = 0;
			while (j < s.size())
			{
				if (s[j] >= '0' && s[j] <= '9')
				{
					string tmp;
					while (j < s.size() && s[j] >= '0' && s[j] <= '9')
						tmp += s[j];
					int k = id0(tmp) - 1;
					if (type > 2)
					{
						tmp = "";
						j++;
						while (j < s.size() && s[j] >= '0' && s[j] <= '9')
							tmp += s[j];
						e.insert(edge(i, k, id0(tmp)));
						if (type == 3)
							e.insert(edge(k, i, id0(tmp)));
					}
					else
					{
						g[i].push_back(k);
						if (type == 1)
							g[k].push_back(i);
					}
				}
				j++;
			}
		}
	}
	void CreateFromEdges()
	{
		if (type < 3)
		{
			for (int i = 0; i < m; i++)
			{
				int u, v;
				cin >> u >> v;
				u--;
				v--;
				g[u].push_back(v);
				if (type == 1)
					g[v].push_back(u);
			}
			for (int i = 0; i < n; i++)
				sort(g[i].begin(), g[i].end());
		}
		else
			for (int i = 0; i < m; i++)
			{
				edge tmp;
				cin >> tmp.from >> tmp.to >> tmp.cost;
				tmp.from--;
				tmp.to--;
				e.insert(tmp);
				swap(tmp.from, tmp.to);
				if (type == 3)
					e.insert(tmp);
			}
	}
	void CreateFromMatrix()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				int k;
				cin >> k;
				if (type > 2)
				{
					e.insert(edge(i, j, k));
					if (type == 3)
						e.insert(edge(j, i, k));
				}
				else
				{
					g[i].push_back(j);
					if (type == 1)
						g[j].push_back(i);
				}
			}
	}
	

	void PrintGraphsAdj()
	{
		for (unsigned int i = 0; i < g.size(); i++, cout << endl)
		{
			cout << i + 1 << ":";
			for (unsigned int j = 0; j < g[i].size(); j++)
				cout << " " << g[i][j] + 1;
		}
	};
	void PrintGraphsEdges()
	{
		for (set<edge>::iterator it = e.begin(); it != e.end(); it++, cout << endl)
			cout << (*it).from + 1 << " " << (*it).to + 1 << " " << (*it).cost;
	};
	void PrintGraphsMatrix()
	{
		vector<vector<int> > ans(n, vector<int>(n, 0));
		if (type < 3)
			for (size_t i = 0; i < g.size(); i++)
				for (size_t j = 0; j < g[i].size(); j++)
					ans[i][g[i][j]] = 1;
		else
			for (set<edge>::iterator it = e.begin(); it != e.end(); it++)
				ans[(*it).from][(*it).to] = (*it).cost;
		for (int i = 0; i < n; i++, cout << endl)
			for (int j = 0; j < n; j++)
				cout << ans[i][j] << " ";
	}
	

	void addnode()
	{
		n++;
		if (type < 3)
			g.push_back(vector<int>());
	}
	bool addedge(int u, int v, int k = 0)
	{
		if (type < 3)
		{
			g[u].push_back(v);
			sort(g[u].begin(), g[u].end());
			g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
			if (type == 1)
			{
				g[v].push_back(u);
				sort(g[v].begin(), g[v].end());
				g[v].erase(unique(g[v].begin(), g[v].end()), g[v].end());
			}
			return true;
		}
		else
		{
			edge tmp(u, v, k);
			if (find(e.begin(), e.end(), tmp) != e.end())
				return false;
			e.insert(tmp);
			m++;
			return true;
		}
	}
	bool delete_edge(int u, int v, int k = INF)
	{
		if (type < 3)
		{
			vector<int>::iterator itu = find(g[u].begin(), g[u].end(), v);
			if (itu == g[u].end())
				return false;
			g[u].erase(itu);
			if (type == 2)
			{
				vector<int>::iterator itv = find(g[v].begin(), g[v].end(), u);
				g[v].erase(itv);
			}
			return true;
		}
		if (type > 2)
		{
			set<edge>::iterator itu;
			if (k == INF)
				for (itu = e.begin(); itu != e.end(); itu++)
					if ((*itu).from == u && (*itu).to == v)
						break;
					else
					{
						edge tmp(u, v, k);
						itu = find(e.begin(), e.end(), tmp);
					}
			if (itu == e.end())
				return false;
			e.erase(itu);
			m--;
			if (type == 3)
			{
				set<edge>::iterator itv;
				if (k == INF)
					for (itv = e.begin(); itv != e.end(); itu++)
						if ((*itv).from == v && (*itv).to == u)
							break;
						else
						{
							edge tmp(v, u, k);
							itv = find(e.begin(), e.end(), tmp);
						}
				e.erase(itv);
			}
			return true;
		}
	}
	bool deletenode(int k)
	{
		if (k > n)
			return false;
		k--;
		if (type > 2)
			for (set<edge>::iterator i = e.begin(); i != e.end(); i++)
			{
				if ((*i).from == k || (*i).to == k)
				{
					e.erase(i);
					i--;
					continue;
				}
			}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (i == k)
					continue;
				for (unsigned int j = 0; j < g[i].size(); j++)
					if (g[i][j] == k)
						delete_edge(i, k);
					else
						if (g[i][j] > k)
							g[i][j]--;
			}
			g.erase(g.begin() + k);
		}
		n--;
		return true;
	}
	

	void deletegraph()
	{
		g.clear();
		used.clear();
		d.clear();
		e.clear();
		tin.clear();
		fup.clear();
		CutPoints.clear();
		n = 0;
		m = 0;
		timer = 0;
	};
	

	void dfs(int v, int prev = -1)
	{
		used.resize(n, 0);
		if (dPrev[v] == -2)
			dPrev[v] = prev;
		used[v] = 1;
		if (type < 3)
		{
			for (size_t i = 0; i < g[v].size(); i++)
				if (used[g[v][i]] == 0)
					dfs(g[v][i], v);
		}
		else
			for (set<edge>::iterator it = e.begin(); it != e.end(); it++)
				if ((*it).from == v && used[(*it).to] == 0)
					dfs((*it).to, v);
		used[v] = 2;
	}
	void bfs(int u = 0)
	{
		used.resize(n, 0);
		d.resize(n, INF);
		queue<int> q;
		q.push(u);
		d[u] = 0;
		dPrev.resize(n, -1);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			used[v] = 1;
			if (type < 3)
			{
				for (unsigned int i = 0; i < g[v].size(); i++)
					if (used[g[v][i]] == 0)
					{
						dPrev[g[v][i]] = v;
						d[g[v][i]] = d[v] + 1;
						q.push(g[v][i]);
					}
			}
			else
				for (set<edge>::iterator it = e.begin(); it != e.end(); it++)
					if ((*it).from == v && used[(*it).to] == 0)
					{
						dPrev[(*it).to] = (*it).from;
						d[(*it).to] = d[(*it).from] + 1;
						q.push((*it).to);
					}
		}
	};
	

	set<int> CutPoints;
	void FindCutPoints(int v = 0, int p = -1)
	{
		used.resize(n, 0);
		tin.resize(n);
		fup.resize(n);
		used[v] = 2;
		tin[v] = fup[v] = timer++;
		int children = 0;
		for (size_t i = 0; i < g[v].size(); ++i)
		{
			int to = g[v][i];
			if (to == p)
				continue;
			if (used[to])
				fup[v] = min(fup[v], tin[to]);
			else
			{
				FindCutPoints(to, v);
				fup[v] = min(fup[v], fup[to]);
				if (fup[to] >= tin[v] && p != -1)
					CutPoints.insert(v);
				++children;
			}
		}
		if (p == -1 && children > 1)
			CutPoints.insert(v);
	}
	

	int dfs_for_sort(int u)
	{
		used[u] = 2;
		for (unsigned int j = 0; j < g[u].size(); j++)
			if (used[g[u][j]] == 0)
				dfs_for_sort(g[u][j]);
		return u;

	}
	vector<int> topological_sort()
	{
		used.resize(n, 0);
		vector<int> top_sort;
		for (int i = 0; i < n; i++)
			if (used[i] == 0)
				top_sort.push_back(dfs_for_sort(i));
		reverse(top_sort.begin(), top_sort.end());
		return top_sort;
	};
	

	void Dijkstra(int u = 0)
	{
		used.resize(n, 0);
		d.resize(n, INF);
		d[u] = 0;
		bool ok = true;
		for (int i = 0; ok &&i < n; i++)
		{
			ok = false;
			int v = -1;
			for (int j = 0; j < n; j++)
				if (used[j] == 0 && d[j] < INF && (v == -1 || d[j] < d[v]))
					v = j;
			if (v == -1)
				break;
			ok = true;
			used[v] = 1;
			for (set<edge>::iterator it = e.begin(); it != e.end(); it++)
				if ((*it).from == v && d[(*it).to] > d[v] + (*it).cost)
				{
					d[(*it).to] = d[v] + (*it).cost;
					dPrev[(*it).to] = v;
				}
		}
	}
	void Floyd()
	{
		dist.resize(n, vector<int>(n, INF));
		for (set<edge>::iterator it = e.begin(); it != e.end(); it++)
			dist[(*it).from][(*it).to] = (*it).cost;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					if (dist[i][j] != -INF && dist[i][k] < INF / 2 && abs(dist[k][j]) < INF / 2)
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					if (dist[k][j] < INF / 2 && dist[j][j] < 0 && dist[j][i] < INF / 2)
						dist[k][i] = -INF;
				}
	}
	void Ford_Bellman(int v = 0)
	{
		d.resize(n, INF);
		d[v] = 0;
		dPrev[v] = -1;
		int i = 0;
		while (i <= n)
		{
			bool change = false;
			for (set<edge>::iterator j = e.begin(); j != e.end(); j++)
				if (d[(*j).from]<INF / 2)
					if (d[(*j).to]>d[(*j).from] + (*j).cost)
					{
						dPrev[(*j).to] = (*j).from;
						d[(*j).to] = d[(*j).from] + (*j).cost;
						change = true;
					}
			if (!change)
				break;
			i++;
		}
	}
	

	vector<edge> Prim()
	{
		used.assign(n, 0);
		vector<edge> ans;
		used[0] = 1;
		while (ans.size() != n - 1)
		{
			edge min_el;
			min_el.cost = INF;
			for (set<edge>::iterator j = e.begin(); j != e.end(); j++)
				if (used[(*j).from] == 1 && used[(*j).to] == 0)
					if ((*j).cost < min_el.cost)
						min_el = (*j);
			ans.push_back(min_el);
			used[min_el.to] = 1;
		}
		return ans;
	};
	vector<edge> Kruskal()
	{
		vector<edge> graf;
		for (set<edge>::iterator it = e.begin(); it != e.end(); it++)
			graf.push_back(*it);
		vector<int> tree_id(n);
		for (int i = 0; i < n; i++)
			tree_id[i] = i;
		vector<edge> ans;
		sort(graf.begin(), graf.end(), Comp);
		for (int i = 0; i < m; ++i)
		{
			int a = graf[i].from, b = graf[i].to, l = graf[i].cost;
			if (tree_id[a] != tree_id[b])
			{
				ans.push_back(graf[i]);
				int old_id = tree_id[b], new_id = tree_id[a];
				for (int j = 0; j < n; ++j)
					if (tree_id[j] == old_id)
						tree_id[j] = new_id;
			}
		}
		return ans;
	}
	

	bool operator==(const graph &a) const
	{
		return g == a.g && e == a.e;
	}
};

template<typename X>
X gcd(X a, X b)
{
	if (a < b)
		swap(a, b);
	while (a != b)
	{
		X tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

int main()
{

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	vector<int> pos0;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == '0')
			pos0.push_back(i);
	}
	int ans = INF;
	for (int i = 0; k + i < pos0.size(); i++)
	{
		int l = pos0[i], r = pos0[k + i];
		int mid = (r + l) / 2;
		vector<int>::iterator it = lower_bound(pos0.begin() + i, pos0.end(), mid);
		mid = it - pos0.begin();
		if (max(pos0[mid-1] - l, r - pos0[mid-1]) < max(pos0[mid] - l, r - pos0[mid]))
			mid--;
		mid = pos0[mid];
		ans = min(ans, max(mid - l, r - mid));
	}
	cout << ans;
	return 0;
}