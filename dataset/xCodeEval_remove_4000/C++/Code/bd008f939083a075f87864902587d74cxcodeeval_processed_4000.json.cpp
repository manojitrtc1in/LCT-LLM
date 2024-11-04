



















using std::cout;
using std::cin;
using std::endl;


using std::vector;


using std::map;


using std::priority_queue;













namespace my_graph
{
    typedef size_t vertex_id;
    typedef size_t edge_id;
    typedef int edge_weight;

    class graph;

    

    struct vert_edge
    {
        vert_edge (vertex_id v, edge_id e) : v(v), e(e) {};

        vertex_id v;
        edge_id e;
    };

    

    class vertex
    {
    public:
        friend class graph;
        typedef vector<vert_edge>::const_iterator adj_iterator;

        adj_iterator in_begin()  const {return adj.begin();}
        adj_iterator out_begin() const {return adj.begin();}
        adj_iterator in_end()    const {return adj.end();}
        adj_iterator out_end()   const {return adj.end();}

        inline size_t get_degree () const {return adj.size();};
    private:
        vector<vert_edge> adj;
    };

    

    struct edge
    {
        friend class graph;
    public:
        edge(const edge_weight &weight) : weight(weight) {};

        const edge_weight &get_data() const {return weight;}

    public:
        edge_weight weight;
    };


    

    class graph
    {
    public:
        inline       vertex &get_vertex(vertex_id id);
        inline const vertex &get_vertex(vertex_id id) const;
        inline       edge   &get_edge  (edge_id id);
        inline const edge   &get_edge  (edge_id id)   const;

        inline size_t v_count() const;
        inline size_t e_count() const;

        inline vertex_id add_vertex();
        inline edge_id add_edge(vertex_id v1, vertex_id v2, const  edge_weight &data);

        inline void reserve(size_t id3, size_t n_edges);
        inline void clear();

    private:
        typedef vector<vertex> vertex_map;
        typedef vector<edge> edge_map;
    public:
        typedef vertex_map::iterator v_iterator;
        typedef vertex_map::const_iterator v_const_iterator;

        typedef edge_map::iterator e_iterator;
        typedef edge_map::const_iterator e_const_iterator;

        v_iterator         v_begin    ()        {return vertices_.begin();};
        v_const_iterator   v_begin    () const  {return vertices_.begin();};
        v_iterator         v_end      ()        {return vertices_.end();};
        v_const_iterator   v_end      () const  {return vertices_.end();};

        e_iterator         e_begin    ()        {return edges_.begin();};
        e_const_iterator   e_begin    () const  {return edges_.begin();};
        e_iterator         e_end      ()        {return edges_.end();};
        e_const_iterator   e_end      () const  {return edges_.end();};

        inline vertex_id get_vertex_id(const v_const_iterator &it) const {return it - v_begin();}
        inline vertex_id get_vertex_id(const v_iterator &it) {return it - v_begin();}
        inline edge_id get_edge_id(const e_const_iterator &it) const {return it - e_begin();}
        inline edge_id get_edge_id(const e_iterator &it) {return it - e_begin();}

    private:
        vertex_map vertices_;
        edge_map edges_;
    };

    vertex &graph::get_vertex(vertex_id id)
    {
        return vertices_[id];
    }

    const vertex &graph::get_vertex(vertex_id id) const
    {
        return vertices_[id];
    }

    edge &graph::get_edge(edge_id id)
    {
        return edges_[id];
    }

    const edge &graph::get_edge(edge_id id) const
    {
        return edges_[id];
    }

    size_t graph::v_count() const
    {
        return vertices_.size();
    }

    
    size_t graph::e_count() const
    {
        return edges_.size();
    }
    
    vertex_id graph::add_vertex()
    {	
		size_t size = vertices_.size();
		vertices_.push_back(vertex());
		return vertices_.size() - 1;
    }

    edge_id graph::add_edge(vertex_id v1, vertex_id v2, const edge_weight &weight)
    {
        edges_.push_back(edge(weight));
        edge_id e = edges_.size() - 1;

        vertices_[v1].adj.push_back(vert_edge(v2, e));
        vertices_[v2].adj.push_back(vert_edge(v1, e));
        return e;
    }

    
    void graph::reserve(size_t id3, size_t n_edges)
    {
        vertices_.reserve(id3);
        edges_.reserve(n_edges);
    }

    
    void graph::clear()
    {
        vertices_.clear();
        edges_.clear();
    }

}









template <typename T>
class id7
{
    typedef size_t key;
public:
    id7 ();
    explicit id7 (size_t size);

    void rehash (size_t size);
    void clear ();
    
    inline T& operator[] (const key &k);
    inline const T& at (const key &k) const;

    void erase (const key &k);

    size_t count (const key& k) const;
    size_t size () const;
    bool empty () const;
public:



private:
    std::vector<T> data_;
    std::vector<bool> flags_;
    size_t size_;
};


template <typename T>
id7<T>::id7()
:   size_   (0)
{

}

template <typename T>
id7<T>::id7(size_t size)
:   data_   (size)
,   flags_  (size, false)
,   size_   (0)
{
    
}

template <typename T>
void id7<T>::rehash(size_t size)
{
    data_.resize (size);
    flags_.resize (size, false);
}


template <typename T>
void id7<T>::clear()
{
    assert (data_.size() == flags_.size());
    std::fill (flags_.begin(), flags_.end(), false);
    size_ = 0;
}






template <typename T>
size_t id7<T>::count(const key& k) const
{
    assert (data_.size() == flags_.size());
    if (k >= data_.size() || !flags_[k])
        return 0;
    return 1;   
}


template <typename T>
inline T& id7<T>::operator[](const key &k)
{
    assert (data_.size() == flags_.size());
    if (k >= data_.size())
        rehash (k+1);
    
    if (!flags_[k])
    {
        data_[k] = T ();
        flags_[k] = true;
        ++size_;
    }

    return data_[k];
}

template <typename T>
inline const T& id7<T>::at(const key &k) const
{
    assert (data_.size() == flags_.size());
    assert (flags_[k]);
    assert (k < data_.size());

    return data_[k];
}


template <typename T>
void id7<T>::erase(const key &k)
{
    assert (data_.size() == flags_.size());
    assert (count (k) > 0);
    flags_[k] = false;
    --size_;
}

template <typename T>
bool id7<T>::empty() const
{
    return (size_==0);
}

template <typename T>
size_t id7<T>::size() const
{
    return size_;
}









namespace my_graph
{

	struct path_vertex
	{
		inline path_vertex (edge_weight d, vertex_id parent) : d(d), parent(parent) {}
		inline path_vertex () {};

		edge_weight d;
		vertex_id parent;  

	};

	struct heap_vertex 
	{
		inline heap_vertex () {}
		inline heap_vertex (vertex_id id, edge_weight d) : id(id), d(d) {}
		inline bool operator< (const heap_vertex& b) const
		{
			return (d > b.d);
		}

		vertex_id id;
		edge_weight d;
	};


	typedef id7<path_vertex> path_map;

	class id10
	{
	public:

		typedef std::unary_function<vertex_id, bool> vert_checker;

		inline id10(const graph &ref_graph, vertex_id start, path_map &ref_out, vector<int> &id4, edge_weight shaft_dist);

		inline bool check_vertex(vertex_id id) const;
		inline bool done();
		inline vertex_id iterate();
		inline vertex_id get_next();
		inline const path_map &get_border() const;


		inline size_t get_n_shafts() const {return n_shafts_;}
	private:
		inline void discard_dublicates();    
		inline edge_weight get_weight(const edge &e) {return e.weight;}

	private:
		graph const * const pgraph_;
		path_map * const pout_;
		path_map border_;
		priority_queue<heap_vertex> q_;
		const edge_weight shaft_dist_;
		size_t n_shafts_;

        vector<int> *counters_;
	public:
		size_t id9;
	};

	id10::id10(const graph &ref_graph, vertex_id start, path_map &ref_out, vector<int> &id4, edge_weight shaft_dist)
		: pgraph_(&ref_graph)
		, pout_(&ref_out)
        , counters_(&id4)
		, id9(0)
		, shaft_dist_(shaft_dist)
		, n_shafts_(0)
	{
		counters_->resize(pgraph_->e_count(), 0);
        q_.push(heap_vertex(start, 0));
		border_[start] = path_vertex(0, start);
	}

	bool id10::done()
	{
		discard_dublicates();
		return q_.empty();
	}

	my_graph::vertex_id id10::iterate()
	{
		if (q_.size() > id9)
			id9 = q_.size();

		discard_dublicates();

		const heap_vertex hv = q_.top();  
		q_.pop();

		const path_vertex &pv = (*pout_)[hv.id] = border_.at(hv.id);
		border_.erase(hv.id);
			
		if (pv.d == shaft_dist_) 
		{
			

			++n_shafts_;
		}

		if (pv.d < shaft_dist_)
		{
			const vertex &v = pgraph_->get_vertex(hv.id);

			for (vertex::adj_iterator it = v.out_begin(); it != v.out_end(); ++it)
			{
				const vertex_id &adj_vid = (*it).v;
				const vertex &adj_v = pgraph_->get_vertex(adj_vid);
				const edge_id &eid = (*it).e;
				const edge &e = pgraph_->get_edge(eid);
                
				const edge_weight ew = get_weight(e);


				if (pv.d < shaft_dist_ && pv.d + ew > shaft_dist_)
				{
					if (pout_->count (adj_vid) == 0)
					{
						

						++(*counters_)[eid];
					}
					else 
					{
						const path_vertex &pv_other = pout_->at(adj_vid);
						
						if (pv_other.d + ew > shaft_dist_)
						{
							const edge_weight id0 = shaft_dist_ - pv.d;
							const edge_weight id1 = shaft_dist_ - pv_other.d;

							if (id0 + id1 < ew)
                                ++(*counters_)[eid];
                            else if (id0 + id1 > ew)
                            {
                                --(*counters_)[eid];
                                if ((*counters_)[eid] < 0)
                                {
                                    cout << "UBER ACHTUNG: " << id0 << ", " << id1 << ": " << ew
                                         << " at " << hv.id + 1 << ", " << adj_vid + 1 << endl;
                                }
                                         
                            }
						}
					}

				}

				const path_vertex pv2 (pv.d + get_weight(e), hv.id);
				const heap_vertex hv2 (adj_vid, pv2.d); 

				if (pout_->count (adj_vid) != 0)
					continue;



				if (border_.count(adj_vid) == 0 || border_.at(adj_vid).d > pv2.d)
				{
					q_.push(hv2);
					border_[adj_vid] = pv2;
				}
			}
		}



		return hv.id;
	}

	my_graph::vertex_id id10::get_next()
	{
		discard_dublicates();
		return q_.top().id;  
	}

	void id10::discard_dublicates()
	{
		while ((!q_.empty()) && (pout_->count(q_.top().id) != 0))
			q_.pop();
	}

	const my_graph::path_map & id10::get_border() const
	{
		return border_;
	}
}






using namespace my_graph;


void id6(const graph &g, const edge_weight shaft_dist, const path_map &tree, vector<int> &dst)
{
    dst.resize(g.e_count(), 0);

    for (graph::v_const_iterator it = g.v_begin(); it != g.v_end(); ++it)
    {
        const vertex_id vid = it - g.v_begin();
        for (vertex::adj_iterator adj_it = it->out_begin(); adj_it != it->out_end(); ++adj_it)
        {
            const vertex_id &adj_vid = adj_it->v;
            const vertex &adj_v = g.get_vertex(adj_vid);
            const edge_id &eid = adj_it->e;
            const edge &e = g.get_edge(eid);

            const edge_weight ew = e.weight;

            for (int l = 1; l < ew; ++l)
            {
                edge_weight www = std::min(l + tree.at(vid).d, (ew - l) + tree.at(adj_vid).d);
                if (www == shaft_dist)
                    ++dst[eid];
            }
        }
    }

    for (vector<int>::iterator it = dst.begin(); it != dst.end(); ++it)
        *it /= 2;
}

int main(int argc, char* argv[])
{
	size_t id2;
	size_t id5;
	size_t capital_id;

	cin >> id2 >> id5 >> capital_id;
	--capital_id;

	graph g;
	
	for (size_t i = 0; i < id2; ++i)
		g.add_vertex();


	for (size_t i = 0; i < id5; ++i)
	{
		vertex_id v1, v2;
		edge_weight weight;
		cin >> v1 >> v2 >> weight;

		g.add_edge(v1 - 1, v2 - 1, weight);
	}

	edge_weight shaft_dist;
	cin >> shaft_dist;

	path_map tree;

	vector<int> id8, id11;
    
    id10 d(g, capital_id, tree, id11, shaft_dist);
	while (!d.done())
		d.iterate();

    

    int shaft_counter = d.get_n_shafts() 
                      + std::accumulate(id11.begin(), 
                                        id11.end(), 
                                        0);

	cout << shaft_counter << endl;

	return 0;
}



