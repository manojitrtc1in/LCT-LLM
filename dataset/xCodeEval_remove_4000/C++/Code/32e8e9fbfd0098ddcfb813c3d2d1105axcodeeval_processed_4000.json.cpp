

namespace std {

template<class Fun>
class id11 {
	Fun fun_;
public:
	template<class T>
	explicit id11(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) id4(Fun &&fun) {
	return id11<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} 



struct id8 {
	static constexpr bool PRINT_DEBUG = false;

	

	int NV = 0;
	

	int NE = 0;

	

	int NC = 0;
	

	int NB = 0;
	

	int NN = 0;
	

	int NVE = 0;

	

	struct range_t {
		int st = -1, en = -1;
		int size() const { return en - st; }
		bool contains(int v) const { return st <= v && v < en; }
	};
	struct iterable_range_t : public range_t {
		struct iterator {
			int v;
			int operator * () const { return v; }
			iterator& operator ++ () { ++v; return *this; }
			friend bool operator != (iterator a, iterator b) { return a.v != b.v; }
		};
		iterator begin() const { return iterator{st}; }
		iterator end() const { return iterator{en}; }
	};
	template <typename T> struct bound_array_range_t {
		typename std::vector<T>::const_iterator st, en;
		int size() const { return int(en - st); }
		auto begin() const { return st; }
		auto end() const { return en; }
	};
	template <typename T, std::vector<T> id8::* array> struct array_range_t : public range_t {
		bound_array_range_t<T> bind(const id8& tree) const {
			return {(tree.*array).begin() + st, (tree.*array).begin() + en};
		}
	};
	template <typename T, std::vector<T> id8::* array> struct enumerable_array_range_t : public iterable_range_t {
		bound_array_range_t<T> bind(const id8& tree) const {
			return {(tree.*array).begin() + st, (tree.*array).begin() + en};
		}
	};

	struct vertex_t;
	std::vector<vertex_t> vertices;
	std::vector<int> vertex_blocks;

	struct component_t;
	std::vector<component_t> components;
	std::vector<int> component_vertices;

	struct block_t;
	std::vector<block_t> blocks;
	std::vector<int> block_vertices;

	struct node_t;
	std::vector<node_t> nodes;
	std::vector<int> node_vertices;

	struct vedge_t;
	std::vector<vedge_t> vedges;

	struct vertex_t {
		int component = -1;
		array_range_t<int, &id8::vertex_blocks> vertex_blocks;
		

	};
	struct component_t {
		enumerable_array_range_t<block_t, &id8::blocks> blocks;
		enumerable_array_range_t<node_t, &id8::nodes> nodes;
		enumerable_array_range_t<vedge_t, &id8::vedges> vedges;
		array_range_t<int, &id8::component_vertices> component_vertices;
	};

	struct block_t {
		int component = -1;
		enumerable_array_range_t<node_t, &id8::nodes> nodes;
		enumerable_array_range_t<vedge_t, &id8::vedges> vedges;
		array_range_t<int, &id8::block_vertices> block_vertices;
	};

	enum class node_type : char {
		Q = 'Q', I = 'I', O = 'O', S = 'S', P = 'P', R = 'R'
	};

	struct node_t {
		node_type type;
		int component = -1;
		int block = -1;
		enumerable_array_range_t<vedge_t, &id8::vedges> vedges;
		array_range_t<int, &id8::node_vertices> node_vertices;
	};

	struct vedge_t {
		std::array<int, 2> vs;
		int component = -1;
		int block = -1;
		int node = -1;
		bool is_tree = false;

		

		int id10 = -1;
		int o_node = -1;
		node_type o_type;
	};

	std::vector<int> depth;

private:
	

	

	std::vector<std::pair<int, int>> adj_lists;
	std::vector<array_range_t<std::pair<int, int>, &id8::adj_lists>> adj;

	struct bucket_edge_t {
		int v; int e; int cur, nxt;
	};
	std::vector<bucket_edge_t> bucket_edges;

	std::pair<int, int> dfs_lowval(int cur, int d, int id2) {
		depth[cur] = d;
		int v1 = d, v2 = d;
		for (auto [nxt, e] : adj[cur].bind(*this)) {
			if (e == id2) continue;
			if (depth[nxt] == -1) {
				const auto [n1, n2] = dfs_lowval(nxt, d+1, e);

				if (n1 >= d) {
					bucket_edges.push_back({0, ~e, cur, nxt});
				} else {
					bucket_edges.push_back({1 + n1 * 2 + (n2 < d), 2*e + (n2 < d), cur, nxt});
				}

				if (n1 < v1) {
					v2 = std::min(v1, n2);
					v1 = n1;
				} else if (n1 == v1) {
					v2 = std::min(v2, n2);
				} else {
					v2 = std::min(v2, n1);
				}
			} else if (depth[nxt] <= d) {
				int nd = depth[nxt];
				if (nd == d) {
					

					bucket_edges.push_back({0, ~e, cur, nxt});
				} else {
					bucket_edges.push_back({1 + nd * 2, 2*e, cur, nxt});
				}

				if (nd < v1) {
					v2 = v1;
					v1 = nd;
				} else if (v1 < nd) {
					v2 = std::min(v2, nd);
				}
			} else {
				

				

			}
		}
		return {v1, v2};
	}

	void build_sorted_adj(std::vector<std::array<int, 2>> edges, int root) {
		{
			std::vector<int> deg(NV, 0);
			for (auto e : edges) {
				for (int v : e) {
					deg[v]++;
				}
			}
			adj.resize(NV);
			int cur = 0;
			for (int i = 0; i < NV; i++) {
				adj[i].st = adj[i].en = cur;
				cur += deg[i];
			}
			adj_lists.resize(cur);
		}
		for (int e = 0; e < int(edges.size()); e++) {
			auto [u, v] = edges[e];
			adj_lists[adj[u].en++] = {v, e};
			if (u != v) {
				adj_lists[adj[v].en++] = {u, e};
			}
		}

		depth = std::vector<int>(NV, -1);

		

		bucket_edges.reserve(NE);

		for (int rt = 0; rt < NV; rt++) {
			if (root != -1 && rt != root) continue;
			if (depth[rt] != -1) continue;
			dfs_lowval(rt, 0, -1);
		}
		assert(int(bucket_edges.size()) == NE);

		for (auto& v : adj) {
			v.en = v.st;
		}

		std::vector<int> bucket_st(1 + NV * 2);
		for (int i = 0; i < int(bucket_edges.size()); i++) {
			++bucket_st[bucket_edges[i].v];
		}
		{
			int cur = 0;
			for (int i = 0; i < int(bucket_st.size()); i++) {
				bucket_st[i] = std::exchange(cur, cur + bucket_st[i]);
			}
			assert(cur == int(bucket_edges.size()));
		}
		std::vector<bucket_edge_t> id0(bucket_edges.size());
		for (int i = 0; i < int(bucket_edges.size()); i++) {
			id0[bucket_st[bucket_edges[i].v]++] = bucket_edges[i];
		}
		bucket_edges = {};
		for (auto [_, e, cur, nxt] : id0) {
			adj_lists[adj[cur].en++] = {nxt, e};
		}
	}

	

	


	struct vestack_t {
		std::array<int, 2> vs;
		bool is_tree = false;
		int id10 = -1;
		int o_node = -1;
		node_type o_type;
	};
	std::vector<vestack_t> vestack;

	using vestack_range_t = enumerable_array_range_t<vestack_t, &id8::vestack>;

	struct estack_t {
		std::array<int, 2> vs;
		vestack_range_t id6;
		node_type type;
		bool is_tree;
	};
	std::vector<estack_t> estack;

	struct tstack_t {
		int idx; 

		int vstart;
		int top_depth;
	};
	std::vector<tstack_t> tstack;

	std::vector<int> id12;

	int cur_component;
	int cur_block;

	void finalize_node(estack_t es, vestack_t cap) {
		assert(es.type != node_type::Q);
		int node = int(nodes.size());

		node_t n;
		n.type = es.type;
		n.component = cur_component;
		n.block = cur_block;

		n.vedges.st = int(vedges.size());
		n.node_vertices.st = int(node_vertices.size());

		auto id1 = [&](const vestack_t& ves) {
			vedges.push_back(vedge_t{
				ves.vs,
				cur_component,
				cur_block,
				node,
				ves.is_tree,
				ves.id10,
				ves.o_node,
				ves.o_type,
			});
			int ve = int(vedges.size()) - 1;
			int id10 = ves.id10;
			if (id10 != -1) {
				vedges[id10].id10 = ve;
				vedges[id10].o_node = node;
				vedges[id10].o_type = n.type;
			}
		};

		for (const auto& ves : es.id6.bind(*this)) {
			id1(ves);
			if (ves.is_tree) {
				int cnd = ves.vs[0];
				if (cnd != cap.vs[0] && cnd != cap.vs[1]) {
					node_vertices.push_back(cnd);
				}
			}
		}
		assert(cap.vs[0] == es.vs[1]);
		assert(cap.vs[1] == es.vs[0]);
		assert(cap.is_tree == !es.is_tree);
		id1(cap);
		if (cap.vs[0] == cap.vs[1]) {
			node_vertices.push_back(cap.vs[0]);
		} else {
			for (int v : cap.vs) {
				node_vertices.push_back(v);
			}
		}

		NVE = int(vedges.size());

		n.vedges.en = int(vedges.size());
		n.node_vertices.en = int(node_vertices.size());

		NN++;
		nodes.push_back(n);
	}

	vestack_t finalize_estack(estack_t es) {
		vestack_t cap;
		cap.vs[0] = es.vs[1];
		cap.vs[1] = es.vs[0];
		cap.is_tree = !es.is_tree;

		int id10;
		int o_node;
		if (es.type == node_type::Q) {
			int e = vestack[es.id6.st].id10;
			id10 = o_node = e;
			assert(cap.vs == vedges[e].vs && cap.is_tree == vedges[e].is_tree);
		} else {
			finalize_node(es, cap);
			id10 = int(vedges.size()) - 1;
			o_node = int(nodes.size()) - 1;
		}

		vestack_t ve;
		ve.vs = es.vs;
		ve.is_tree = es.is_tree;
		ve.id10 = id10;
		ve.o_node = o_node;
		ve.o_type = es.type;
		return ve;
	}

	void push_estack(estack_t e_ins) {
		if constexpr (PRINT_DEBUG) std::cerr << "push_estack " << e_ins.vs[0] << '-' << e_ins.vs[1] << ' ' << e_ins.is_tree << '\n';
		estack.push_back(e_ins);
		int v = e_ins.vs[0];
		if (id12[v] == -1) {
			id12[v] = int(estack.size()) - 1;
		}
	}

	void push_estack_p(estack_t e_ins) {
		if constexpr (PRINT_DEBUG) std::cerr << "push_estack_p " << e_ins.vs[0] << '-' << e_ins.vs[1] << ' ' << e_ins.is_tree << '\n';
		if (estack.back().type == node_type::P) {
			int st = e_ins.id6.st;
			vestack[st] = finalize_estack(e_ins);
			vestack.resize(st+1);
			assert(estack.back().id6.en == st);
			estack.back().id6.en ++;
		} else {
			int st = estack.back().id6.st;
			vestack[st] = finalize_estack(estack.back());
			vestack[st+1] = finalize_estack(e_ins);
			vestack.resize(st+2);
			estack.back().id6 = {st, st+2};
			estack.back().type = node_type::P;
		}
	}

	void prepare_pop_estack(int z) {
		int v = estack[z].vs[0];
		if (id12[v] == z) {
			id12[v] = -1;
		}
	}
	void pop_estack() {
		prepare_pop_estack(int(estack.size()) - 1);
		estack.pop_back();
	}

	

	

	std::pair<vestack_range_t, node_type> pop_estack_range(int idx) {
		assert(int(estack.size()) - idx > 1);
		for (int z = idx; z < int(estack.size()); z++) {
			prepare_pop_estack(z);
		}

		bool is_S = (int(estack.size()) - idx == 2);
		if (is_S) {
			assert(estack.back().type != node_type::S);
		}
		bool id9 = (is_S && estack[idx].type == node_type::S);
		int st = estack[idx].id6.st;

		int sidx = idx + id9;
		int en = estack[sidx].id6.st;
		for (int z = sidx; z < int(estack.size()); z++) {
			vestack[en++] = finalize_estack(estack[z]);
		}

		vestack.resize(en);
		estack.resize(idx);
		return {{st, en}, is_S ? node_type::S : node_type::R};
	}

	estack_t make_q_node(int e, int cur, int nxt, bool is_tree) {
		vedges[e].vs = {cur, nxt};
		vedges[e].component = cur_component;
		vedges[e].block = cur_block;
		vedges[e].node = e;
		vedges[e].is_tree = !is_tree;
		

		

		

		vestack.emplace_back();
		vestack.back().id10 = e;

		nodes[e].type = node_type::Q;
		nodes[e].component = cur_component;
		nodes[e].block = cur_block;
		nodes[e].vedges = {e, e+1};
		nodes[e].node_vertices = {2*e, 2*e + (cur == nxt ? 1 : 2)};
		node_vertices[2*e] = cur;
		node_vertices[2*e+1] = nxt;

		return estack_t{{nxt, cur}, {int(vestack.size()) - 1, int(vestack.size())}, node_type::Q, is_tree};
	}

	void dfs_spqr(int cur, int cur_low) {
		int cur_depth = depth[cur];
		for (auto [nxt, e] : adj[cur].bind(*this)) {
			if (e < 0) continue;
			bool id5 = !(e & 1);
			e >>= 1;

			int orig_size = int(estack.size());

			bool is_tree = (depth[nxt] > cur_depth);
			if (is_tree) {
				dfs_spqr(nxt, cur_low);

				

				assert(!tstack.empty());
				if (tstack.back().top_depth == cur_depth + 1) {
					assert(tstack.back().idx == int(estack.size())-1);
					tstack.back().top_depth = cur_depth;
				}
			}

			

			estack_t e_ins = make_q_node(e, cur, nxt, is_tree);
			if (is_tree) {
				while (true) {
					if (estack.back().vs == std::array<int, 2>{cur, nxt}) {
						push_estack_p(e_ins);
						e_ins.id6 = estack.back().id6;
						assert(estack.back().type == node_type::P);
						e_ins.type = node_type::P;

						assert(!tstack.empty());
						if (tstack.back().idx == int(estack.size()) - 1) {
							tstack.pop_back();
						}
						

						

						pop_estack();
					}

					push_estack(e_ins);

					assert(!tstack.empty());
					if (tstack.back().top_depth != cur_depth) break;
					assert(tstack.back().idx > orig_size);
					if (estack[tstack.back().idx].is_tree) {
						assert(estack[tstack.back().idx].vs[0] == tstack.back().vstart);
						if (int(estack.size()) - tstack.back().idx > 2) {
							tstack.push_back({
								tstack.back().idx + 1,
								estack[tstack.back().idx].vs[1],
								tstack.back().top_depth
							});
						}
					}

					int idx = tstack.back().idx;
					assert(idx > orig_size);
					nxt = tstack.back().vstart;
					tstack.pop_back();
					auto [id6, type] = pop_estack_range(idx);
					e_ins = estack_t{{nxt, cur}, id6, type, true};
				}

				if (id5) {
					


					nxt = estack[orig_size].vs[0];

					

					

					

					while (tstack.back().idx > orig_size) tstack.pop_back();
					assert(!tstack.empty());
					if (tstack.back().idx == orig_size) {
						assert(tstack.back().vstart == cur_low && tstack.back().top_depth == depth[nxt]);
					}

					int idx = orig_size;
					auto [id6, type] = pop_estack_range(idx);
					e_ins = estack_t{{nxt, cur}, id6, type, false};
					if (!estack.empty() && estack.back().vs == e_ins.vs) {
						push_estack_p(e_ins);
						

						if (tstack.back().idx == orig_size) tstack.pop_back();
					} else {
						push_estack(e_ins);
						

					}
				} else if (cur_low == cur) {
					

					

					while (tstack.back().idx > orig_size) tstack.pop_back();
					assert(!tstack.empty());
				} else if (id12[cur] != -1) {
					

					while (tstack.back().idx > id12[cur]) tstack.pop_back();
					assert(!tstack.empty());
				} else {
					

					

					

					

					

					

					

					

					tstack.push_back({int(estack.size())-1, nxt, cur_depth});
				}
			} else {
				if (!estack.empty() && estack.back().vs == e_ins.vs) {
					push_estack_p(e_ins);
					

				} else {
					push_estack(e_ins);

					

					assert(depth[cur_low] > depth[nxt]);
					tstack_t t_ins{int(estack.size())-1, cur_low, depth[nxt]};
					assert(tstack.empty() || tstack.back().top_depth <= depth[cur_low]);
					while (!tstack.empty() && tstack.back().top_depth > t_ins.top_depth) {
						t_ins.idx = tstack.back().idx;
						t_ins.vstart = tstack.back().vstart;
						tstack.pop_back();
					}
					tstack.push_back(t_ins);
				}
			}

			cur_low = cur;
		}

		block_vertices.push_back(cur);
		vertex_blocks[vertices[cur].vertex_blocks.en++] = cur_block;
	}

	int start_spqr(int cur, int nxt, int e) {
		int block = NB++;
		blocks.emplace_back();
		blocks[block].component = cur_component;
		blocks[block].nodes.st = int(nodes.size());
		blocks[block].vedges.st = int(vedges.size());
		blocks[block].block_vertices.st = int(block_vertices.size());
		cur_block = block;

		if (nxt != cur) {
			dfs_spqr(nxt, nxt);
			if (estack.empty()) {
				estack.push_back(estack_t{{cur, nxt}, {int(vestack.size()), int(vestack.size())}, node_type::I, false});
			} else {
				assert(int(estack.size()) == 1);
				assert((estack.back().vs == std::array<int, 2>{cur, nxt}));
				assert(!estack.back().is_tree);

				if (estack.back().type == node_type::Q) {
					vestack.back() = finalize_estack(estack.back());
					

					estack.back().type = node_type::O;
				}

				assert(!tstack.empty() && tstack.back().idx == 0);
				tstack.pop_back();
			}
		} else {
			estack.push_back(estack_t{{cur, cur}, {int(vestack.size()), int(vestack.size())}, node_type::O, true});
		}

		

		auto id13 = make_q_node(e, cur, nxt, cur != nxt);
		vestack.back() = finalize_estack(id13);

		auto es = estack.back();
		pop_estack();
		finalize_node(es, vestack.back());
		vestack.resize(es.id6.st);

		assert(tstack.empty());
		assert(estack.empty());
		assert(vestack.empty());

		block_vertices.push_back(cur);

		cur_block = -1;
		blocks[block].nodes.en = int(nodes.size());
		blocks[block].vedges.en = int(vedges.size());
		blocks[block].block_vertices.en = int(block_vertices.size());
		return block;
	}

	std::vector<int> id3;
	void dfs_block(int cur) {
		int buf_st = int(id3.size());
		for (auto [nxt, e] : adj[cur].bind(*this)) {
			assert(depth[nxt] <= depth[cur] + 1);
			if (depth[nxt] < depth[cur]) continue;
			if (nxt != cur) {
				dfs_block(nxt);
			}
			if (e < 0) {
				e = ~e;
				

				int block = start_spqr(cur, nxt, e);

				id3.push_back(block);
			}
		}

		vertices[cur].vertex_blocks.st = int(vertex_blocks.size());
		vertex_blocks.insert(vertex_blocks.end(), id3.begin() + buf_st, id3.end());
		id3.resize(buf_st);
		vertices[cur].vertex_blocks.en = int(vertex_blocks.size());

		

		if (depth[cur] > 0) {
			vertex_blocks.push_back(-1);
		}

		component_vertices.push_back(cur);
		vertices[cur].component = cur_component;
	}

	void build_spqr() {
		vertices.resize(NV);
		vertex_blocks.reserve(NV + NE);

		components.reserve(NV);
		component_vertices.reserve(NV);

		blocks.reserve(NE);
		block_vertices.reserve(NV + NE);

		

		nodes.reserve(2 * NE);
		NN = NE;
		nodes.resize(NN);
		

		node_vertices.reserve(NV + 5 * NE);
		node_vertices.resize(2 * NE);

		

		vedges.reserve(2 * (2 * NE));
		NVE = NE;
		vedges.resize(NVE);

		id3.reserve(NE);
		vestack.reserve(NE);
		estack.reserve(NE);
		tstack.reserve(NE);
		id12.assign(NV, -1);

		for (int rt = 0; rt < NV; rt++) {
			if (depth[rt] != 0) continue;
			int component = NC++;
			components.emplace_back();
			component_t& c = components[component];
			c.blocks.st = int(blocks.size());
			c.nodes.st = int(nodes.size());
			c.vedges.st = int(vedges.size());
			c.component_vertices.st = int(component_vertices.size());

			cur_component = component;
			dfs_block(rt);
			cur_component = -1;

			c.blocks.en = int(blocks.size());
			c.nodes.en = int(nodes.size());
			c.vedges.en = int(vedges.size());
			c.component_vertices.en = int(component_vertices.size());
		}

		id3 = {};
		vestack = {};
		estack = {};
		tstack = {};
		id12 = {};
	}

public:
	id8() = default;
	explicit id8(int NV_, std::vector<std::array<int, 2>> edges, int root = -1) {
		NV = NV_;
		if (NV == 0) return;

		if (root != -1) {
			assert(0 <= root && root < NV);
		}

		NE = int(edges.size());

		build_sorted_adj(std::move(edges), root);

		build_spqr();

		adj = {};
		adj_lists = {};
		

		

	}
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		std::vector<std::array<int, 2>> edges(M);
		for (auto& e : edges) {
			for (auto& v : e) cin >> v;
		}

		std::vector<std::vector<int>> ans(N);
		auto solve = [&]() -> bool {
			const id8 tree(N, edges);

			for (int node = tree.NE; node < tree.NN; node++) {
				if (tree.nodes[node].type == id8::node_type::R) {
					return false;
				} else if (tree.nodes[node].type == id8::node_type::S) {
					continue;
				} else if (tree.nodes[node].type == id8::node_type::P) {
					assert(tree.nodes[node].vedges.size() >= 3);
					if (tree.nodes[node].vedges.size() > 3) return false;
					assert(tree.nodes[node].vedges.size() == 3);
					bool id7 = false;
					for (const auto& ve : tree.nodes[node].vedges.bind(tree)) {
						if (ve.o_type == id8::node_type::Q) {
							id7 = true;
							break;
						}
					}
					if (!id7) return false;
				} else if (tree.nodes[node].type == id8::node_type::I) {
				} else assert(false);
			}

			std::vector<int> succ(2 * tree.NVE);

			for (int block = 0; block < tree.NB; block++) {
				int root_node = tree.blocks[block].nodes.en-1;
				auto dfs = std::id4([&](auto self, int node, bool flip) -> void {
					if (tree.nodes[node].type == id8::node_type::Q) {
						const auto& ve = tree.vedges[tree.nodes[node].vedges.st];
						ans[ve.vs[0]].push_back(ve.vs[1]);
						ans[ve.vs[1]].push_back(ve.vs[0]);
						return;
					} else if (tree.nodes[node].type == id8::node_type::P) {
						int a = tree.nodes[node].vedges.st;
						int b = tree.nodes[node].vedges.st+1;
						int c = tree.nodes[node].vedges.st+2;
						assert(tree.vedges[c].o_type != id8::node_type::Q);
						if (tree.vedges[a].o_type == id8::node_type::Q) {
							swap(a, b);
						}
						assert(tree.vedges[b].o_type == id8::node_type::Q);
						assert(tree.vedges[a].o_type != id8::node_type::Q);

						flip ^= tree.vedges[c].is_tree == tree.vedges[a].is_tree;

						int x = tree.vedges[a].vs[0];
						int y = tree.vedges[a].vs[1];

						if (flip) swap(x, y);
						ans[x].push_back(y);
						self(tree.vedges[a].o_node, flip);
						ans[y].push_back(x);
					} else if (tree.nodes[node].type == id8::node_type::S) {
						int st = tree.nodes[node].vedges.st;
						int en = tree.nodes[node].vedges.en-1;
						if (flip) {
							for (int ve = en-1; ve >= st; ve--) {
								self(tree.vedges[ve].o_node, flip);
							}
						} else {
							for (int ve = st; ve < en; ve++) {
								self(tree.vedges[ve].o_node, flip);
							}
						}
					} else assert(false);
				});
				if (tree.nodes[root_node].type == id8::node_type::P) {
					int a = tree.nodes[root_node].vedges.st;
					int b = tree.nodes[root_node].vedges.st+1;
					const auto& ve = tree.vedges[tree.nodes[root_node].vedges.en-1];
					ans[ve.vs[1]].push_back(ve.vs[0]);
					dfs(tree.vedges[a].o_node, false);
					int l = int(ans[ve.vs[1]].size());
					ans[ve.vs[0]].push_back(ve.vs[1]);
					dfs(tree.vedges[b].o_node, true);
					std::rotate(ans[ve.vs[1]].begin(), ans[ve.vs[1]].begin() + l, ans[ve.vs[1]].end());
				} else if (tree.nodes[root_node].type == id8::node_type::S) {
					const auto& ve = tree.vedges[tree.nodes[root_node].vedges.en-1];
					assert(ve.is_tree);
					ans[ve.vs[1]].push_back(ve.vs[0]);
					dfs(root_node, false);
					ans[ve.vs[0]].push_back(ve.vs[1]);
				} else if (tree.nodes[root_node].type == id8::node_type::I) {
					for (const auto& ve : tree.nodes[root_node].vedges.bind(tree)) {
						dfs(ve.o_node, false);
					}
				} else assert(false);
			}
			return true;
		};
		if (solve()) {
			cout << "YES" << '\n';
			for (int i = 0; i < N; i++) {
				for (int z = 0; z < int(ans[i].size()); z++) {
					cout << ans[i][z] << " \n"[z+1==int(ans[i].size())];
				}
			}
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}
