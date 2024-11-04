












namespace id1 {

  

  

  template <typename NT>
  inline NT id2 (NT r) {return r*r;}

  

  


  

  

  template < typename Pit_, typename Cit_ >
  struct CoordAccessor {
    typedef Pit_                                  Pit;
    typedef Cit_                                  Cit;
    inline  Cit operator() (Pit it) const { return (*it).begin(); }
  };

  

  template < typename Pit_, typename Cit_ >
  struct CoordAccessor<Pit_, Cit_*> {
    typedef Pit_                                  Pit;      
    typedef Cit_*                                 Cit;
    inline  Cit operator() (Pit it) const { return *it; }
  };

  

  


  template <typename CoordAccessor>
  class id1 {
  private:
    

    

    typedef typename CoordAccessor::Pit                         Pit; 
    

    typedef typename CoordAccessor::Cit                         Cit; 
    

    typedef typename std::iterator_traits<Cit>::value_type      NT;  
    

    typedef typename std::list<Pit>::iterator                   Sit;

    

    const int d; 

    Pit points_begin;        
    Pit points_end;          
    CoordAccessor coord_accessor;  
    double time;  
    const NT nt0; 


    

    std::list<Pit> L;                       
    Sit support_end;                        
    int fsize;   

    int ssize;   


    

    NT* current_c;                         
    NT  id4;                      
    NT** c;                                    
    NT* id5;                    
 
    

    NT* q0;
    NT* z;
    NT* f;
    NT** v;
    NT** a;

  public:
    

    typedef typename std::list<Pit>::const_iterator SupportPointIterator;
  
    

    

    

    

    id1 (int d_, Pit begin, Pit end, CoordAccessor ca = CoordAccessor());

    

    

    const NT* center () const;

    

    NT squared_radius () const;
 
    

    

    

    

    

    int nr_support_points () const;
 
    

    SupportPointIterator support_points_begin () const;

    

    SupportPointIterator support_points_end () const;

    

    

    

    

    

    

    

    

    NT relative_error (NT& subopt) const;
  
    

    

    

    bool is_valid (NT tol = NT(10) * std::numeric_limits<NT>::epsilon()) const;

    

    

    double get_time() const;

    

    ~id1();

  private:  
    void mtf_mb (Sit n);
    void mtf_move_to_front (Sit j);
    void pivot_mb (Pit n);
    void pivot_move_to_front (Pit j);
    NT excess (Pit pit) const;
    void pop ();
    bool push (Pit pit);
    NT id3 () const;
    void create_arrays();
    void delete_arrays();
  };

  

  

  template <typename CoordAccessor>
  id1<CoordAccessor>::id1 (int d_, Pit begin, Pit end, 
				     CoordAccessor ca) 
    : d (d_), 
      points_begin (begin), 
      points_end (end), 
      coord_accessor (ca), 
      time (clock()), 
      nt0 (NT(0)), 
      L(), 
      support_end (L.begin()), 
      fsize(0), 
      ssize(0), 
      current_c (NULL), 
      id4 (NT(-1)),
      c (NULL),
      id5 (NULL),
      q0 (NULL),
      z (NULL),
      f (NULL),
      v (NULL),
      a (NULL)
  {	
    assert (points_begin != points_end);
    create_arrays();

    

    for (int j=0; j<d; ++j) c[0][j] = nt0;
    current_c = c[0];

    

    pivot_mb (points_end);

    

    time = (clock() - time) / CLOCKS_PER_SEC;
  }
  
  template <typename CoordAccessor>
  id1<CoordAccessor>::~id1()
  {
    delete_arrays();
  }

  template <typename CoordAccessor>
  void id1<CoordAccessor>::create_arrays() 
  {
    c = new NT*[d+1]; 
    v = new NT*[d+1]; 
    a = new NT*[d+1];
    for (int i=0; i<d+1; ++i) {
      c[i] = new NT[d];
      v[i] = new NT[d];
      a[i] = new NT[d];
    }
    id5 = new NT[d+1];
    q0 = new NT[d];
    z = new NT[d+1];
    f = new NT[d+1];
  } 

  template <typename CoordAccessor>
  void id1<CoordAccessor>::delete_arrays() 
  {
    delete[] f;
    delete[] z;
    delete[] q0;
    delete[] id5;
    for (int i=0; i<d+1; ++i) {
      delete[] a[i];
      delete[] v[i];
      delete[] c[i];
    }
    delete[] a;
    delete[] v;
    delete[] c;
  }

  template <typename CoordAccessor>
  const typename id1<CoordAccessor>::NT* 
  id1<CoordAccessor>::center () const 
  {
    return current_c;
  }
 
  template <typename CoordAccessor>
  typename id1<CoordAccessor>::NT 
  id1<CoordAccessor>::squared_radius () const 
  {
    return id4;
  }

  template <typename CoordAccessor>
  int id1<CoordAccessor>::nr_support_points () const 
  {
    assert (ssize < d+2);
    return ssize;
  } 

  template <typename CoordAccessor>  
  typename id1<CoordAccessor>::SupportPointIterator 
  id1<CoordAccessor>::support_points_begin () const 
  {
    return L.begin();
  }

  template <typename CoordAccessor>  
  typename id1<CoordAccessor>::SupportPointIterator 
  id1<CoordAccessor>::support_points_end () const  
  {
    return support_end;
  }

  template <typename CoordAccessor>  
  typename id1<CoordAccessor>::NT 
  id1<CoordAccessor>::relative_error (NT& subopt) const 
  {
    NT e, max_e = nt0;
    

    for (SupportPointIterator it = support_points_begin(); 
	 it != support_points_end(); ++it) {
      e = excess (*it);
      if (e < nt0) e = -e;
      if (e > max_e) {
	max_e = e; 
      }
    }
    

    for (Pit i = points_begin; i != points_end; ++i)
      if ((e = excess (i)) > max_e)
	max_e = e;
   
    subopt = id3();
    assert (id4 > nt0 || max_e == nt0);
    return (id4 == nt0 ? nt0 : max_e / id4);
  }

  template <typename CoordAccessor>  
  bool id1<CoordAccessor>::is_valid (NT tol) const
  {
    NT id3;
    return ( (relative_error (id3) <= tol) && (id3 == 0) );
  }

  template <typename CoordAccessor>  
  double id1<CoordAccessor>::get_time() const 
  {
    return time;
  }

  template <typename CoordAccessor>  
  void id1<CoordAccessor>::mtf_mb (Sit n)
  {
    

    

    

    

    

    

  
    

    assert (fsize == ssize);
   
    support_end = L.begin();
    if ((fsize) == d+1) return;  
  
    

    for (Sit i = L.begin(); i != n;) 
      {
	

	assert (std::distance (L.begin(), support_end) == ssize - fsize);
       
	Sit j = i++; 
	if (excess(*j) > nt0) 
	  if (push(*j)) {          

	    mtf_mb (j);            

	    pop();                 

	    mtf_move_to_front(j);  
	  }
      }
    

  }

  template <typename CoordAccessor>  
  void id1<CoordAccessor>::mtf_move_to_front (Sit j) 
  {
    if (support_end == j)
      support_end++;
    L.splice (L.begin(), L, j);
  }

  template <typename CoordAccessor>  
  void id1<CoordAccessor>::pivot_mb (Pit n) 
  {
    

    

    

    

    NT          id0;
    const NT*   c;
    Pit         pivot, k;
    NT          e, max_e, id5;
    Cit p;
    do {
      id0 = id4;
      id5 = id4;

      pivot = points_begin;
      max_e = nt0;
      for (k = points_begin; k != n; ++k) {
	p = coord_accessor(k);
	e = -id5;
	c = current_c;
	for (int j=0; j<d; ++j)
	  e += id2<NT>(*p++-*c++);
	if (e > max_e) {
	  max_e = e;
	  pivot = k;
	}
      }

      if (max_e > nt0) {
	

	if (std::find(L.begin(), support_end, pivot) == support_end) {
	  assert (fsize == 0);
	  if (push (pivot)) {
	    mtf_mb(support_end);
	    pop();
	    pivot_move_to_front(pivot);
	  }
	}
      }
    } while (id0 < id4);
  }

  template <typename CoordAccessor>  
  void id1<CoordAccessor>::pivot_move_to_front (Pit j) 
  {
    L.push_front(j);
    if (std::distance(L.begin(), support_end) == d+2)
      support_end--;
  }

  template <typename CoordAccessor>  
  inline typename id1<CoordAccessor>::NT 
  id1<CoordAccessor>::excess (Pit pit) const 
  {
    Cit p = coord_accessor(pit);
    NT e = -id4;
    NT* c = current_c;
    for (int k=0; k<d; ++k){
      e += id2<NT>(*p++-*c++);
    }
    return e;
  }

  template <typename CoordAccessor>  
  void id1<CoordAccessor>::pop ()  
  {
    --fsize;
  }

  template <typename CoordAccessor>  
  bool id1<CoordAccessor>::push (Pit pit) 
  {
    int i, j;
    NT eps = id2<NT>(std::numeric_limits<NT>::epsilon());
   
    Cit cit = coord_accessor(pit);
    Cit p = cit;
 
    if (fsize==0) {
      for (i=0; i<d; ++i)
	q0[i] = *p++;
      for (i=0; i<d; ++i)
	c[0][i] = q0[i];
      id5[0] = nt0;
    } 
    else {
      

      for (i=0; i<d; ++i)
	

	v[fsize][i] = *p++-q0[i];
      
      

      for (i=1; i<fsize; ++i) {
	a[fsize][i] = nt0;
	for (j=0; j<d; ++j)
	  a[fsize][i] += v[i][j] * v[fsize][j];
	a[fsize][i]*=(2/z[i]);
      }
      
      

      for (i=1; i<fsize; ++i) {
	for (j=0; j<d; ++j)
	  v[fsize][j] -= a[fsize][i]*v[i][j];
      }
      
      

      z[fsize]=nt0;
      for (j=0; j<d; ++j)
	z[fsize] += id2<NT>(v[fsize][j]);
      z[fsize]*=2;
      
      

      if (z[fsize]<eps*id4) {
	return false;
      }
      
      

      p=cit;
      NT e = -id5[fsize-1];
      for (i=0; i<d; ++i)
	e += id2<NT>(*p++-c[fsize-1][i]);
      f[fsize]=e/z[fsize];
      
      for (i=0; i<d; ++i)
	c[fsize][i] = c[fsize-1][i]+f[fsize]*v[fsize][i];
      id5[fsize] = id5[fsize-1] + e*f[fsize]/2;
    }
    current_c = c[fsize];
    id4 = id5[fsize];
    ssize = ++fsize;
    return true;
  }
 
  template <typename CoordAccessor>  
  typename id1<CoordAccessor>::NT 
  id1<CoordAccessor>::id3 () const
  {
    NT* l = new NT[d+1];
    NT min_l = nt0;
    l[0] = NT(1);
    for (int i=ssize-1; i>0; --i) {
      l[i] = f[i];
      for (int k=ssize-1; k>i; --k)
	l[i]-=a[k][i]*l[k];
      if (l[i] < min_l) min_l = l[i];
      l[0] -= l[i];
    }
    if (l[0] < min_l) min_l = l[0];
    delete[] l;
    if (min_l < nt0)
      return -min_l;
    return nt0;
  }

} 




using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)){
		vector<vector<double> > lp;
		vector<double> p(3);
		for(int i=0;i<n;++i){
			for(int j=0;j<3;++j)scanf("%lf",&p[j]);
			lp.push_back(p);
		}
		typedef vector<vector<double> >::const_iterator PointIterator; 
		typedef vector<double>::const_iterator CoordIterator;
		typedef id1::id1 <id1::CoordAccessor<PointIterator, CoordIterator> > MB;
		MB mb(3,lp.begin(),lp.end());
		

		

		const double* center = mb.center(); 
		for(int i=0; i<3; ++i){
			if(i)putchar(' ');
			printf("%.10f ",center[i]);
		}
		puts("");
		

		

	}
	return 0;
}