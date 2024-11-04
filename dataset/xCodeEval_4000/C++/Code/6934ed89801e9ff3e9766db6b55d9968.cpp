#include <bits/stdc++.h>































#ifndef _MCMF_H_
#define _MCMF_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

using namespace std;












#define MAX_64 (0x7fffffffffffffffLL)
#define MAX_32 (0x7fffffff)
#define PRICE_MAX MAX_64

#define MAXLINE       100 

#define ARC_FIELDS      5 

#define NODE_FIELDS     2 

#define P_FIELDS        3 

#define PROBLEM_TYPE "min" 


#define UNFEASIBLE          2
#define ALLOCATION_FAULT    5
#define PRICE_OFL           6



#define UPDT_FREQ      0.4
#define UPDT_FREQ_S    30
#define SCALE_DEFAULT  12.0


#define PRICE_OUT_START  1
#define CUT_OFF_POWER    0.44
#define CUT_OFF_COEF     1.5
#define CUT_OFF_POWER2   0.75
#define CUT_OFF_COEF2    1
#define CUT_OFF_GAP      0.8
#define CUT_OFF_MIN      12
#define CUT_OFF_INCREASE 4

#define TIME_FOR_PRICE_IN1    2
#define TIME_FOR_PRICE_IN2    4
#define TIME_FOR_PRICE_IN3    6

#define MAX_CYCLES_CANCELLED 0
#define START_CYCLE_CANCEL   100

#define MAX( x, y ) ( ( (x) > (y) ) ?  x : y )
#define MIN( x, y ) ( ( (x) < (y) ) ? x : y )
#define ABS( x ) ( (x) >= 0 ) ? (x) : -(x)
#define N_NODE( i ) ( ( (i) == NULL ) ? -1 : ( (i) - _nodes + _node_min ) )
#define N_ARC( a ) ( ( (a) == NULL )? -1 : (a) - _arcs )

class MCMF_CS2
{
 public:
	typedef long long int excess_t;
	typedef long long int price_t;

	class NODE;
	
	class ARC {
	public:
		long _rez_capacity; 

		price_t _cost; 

		NODE *_head; 

		ARC *_sister; 

	public:
		ARC() {}
		~ARC() {}

		void set_rez_capacity( long rez_capacity) { _rez_capacity = rez_capacity; }
		void dec_rez_capacity( long delta) { _rez_capacity -= delta; }
		void inc_rez_capacity( long delta) { _rez_capacity += delta; }
		void set_cost( price_t cost) { _cost = cost; }
		void multiply_cost( price_t mult) { _cost *= mult; }
		void set_head( NODE *head) { _head = head; }
		void set_sister( ARC *sister) { _sister = sister; }
		long rez_capacity() { return _rez_capacity; }
		price_t cost() { return _cost; }
		NODE *head() { return _head; }
		ARC *sister() { return _sister; }
	};

	class NODE {
	public:
		excess_t _excess; 

		price_t _price; 

		ARC *_first; 

		ARC *_current; 

		ARC *_suspended;
		NODE *_q_next; 

		NODE *_b_next; 

		NODE *_b_prev; 

		long _rank; 

		long _inp; 

	public:
		NODE() {}
		~NODE() {}

		void set_excess( excess_t excess) { _excess = excess; }
		void dec_excess( long delta) { _excess -= delta; }
		void inc_excess( long delta) { _excess += delta; }
		void set_price( price_t price) { _price = price; }
		void dec_price( long delta) { _price -= delta; }
		void set_first( ARC *first) { _first = first; }
		void set_current( ARC *current) { _current = current; }
		void inc_current() { _current ++; }
		void set_suspended( ARC *suspended) { _suspended = suspended; }
		void set_q_next( NODE *q_next) { _q_next = q_next; }
		void set_b_next( NODE *b_next) { _b_next = b_next; }
		void set_b_prev( NODE *b_prev) { _b_prev = b_prev; }
		void set_rank( long rank) { _rank = rank; }
		void set_inp( long inp) { _inp = inp; }
		excess_t excess() { return _excess; }
		price_t price() { return _price; }
		ARC *first() { return _first; }
		void dec_first() { _first --; }
		void inc_first() { _first ++; }
		ARC *current() { return _current; }
		ARC *suspended() { return _suspended; }
		NODE *q_next() { return _q_next; }
		NODE *b_next() { return _b_next; }
		NODE *b_prev() { return _b_prev; }
		long rank() { return _rank; }
		long inp() { return _inp; }
	};
 
	class BUCKET {
	private:
		

		NODE *_p_first;
	public:
	BUCKET( NODE *p_first) : _p_first(p_first) {}
		BUCKET() {}
		~BUCKET() {}

		void set_p_first( NODE *p_first) { _p_first = p_first; }
		NODE *p_first() { return _p_first; }
	};

 public:
	long _n; 

	long _m; 


	long *_cap; 

	NODE *_nodes; 

	NODE *_sentinel_node; 

	NODE *_excq_first; 

	NODE *_excq_last; 

	ARC *_arcs; 

	ARC *_sentinel_arc; 


	BUCKET *_buckets; 

	BUCKET *_l_bucket; 

	long _linf; 

	int _time_for_price_in;

	price_t _epsilon; 

	price_t _dn; 

	price_t _price_min; 

	price_t _mmc; 

	double _f_scale; 

	double _cut_off_factor; 

	double _cut_on; 

	double _cut_off; 

	excess_t _total_excess; 


	

	

	int _flag_price;
	

	

	int _flag_updt;
	

	int _snc_max;

	

	ARC _d_arc; 

	NODE _d_node; 

	NODE *_dummy_node; 

	NODE *_dnode;

	long _n_rel; 

	long _n_ref; 

	long _n_src; 

	long _n_push;
	long _n_relabel;
	long _n_discharge;
	long _n_refine;
	long _n_update;
	long _n_scan;
	long _n_prscan;
	long _n_prscan1;
	long _n_prscan2;
	long _n_bad_pricein;
	long _n_bad_relabel;
	long _n_prefine;

	bool _no_zero_cycles; 

	bool _check_solution; 

	bool _comp_duals; 

	bool _cost_restart; 

	bool _print_ans;
	long long int *_node_balance;

	

	long _node_min; 

	long _node_max; 

    long *_arc_first; 

                      

                      

	long *_arc_tail; 

	long _pos_current;
	ARC *_arc_current;
	ARC *_arc_new;
	ARC *_arc_tmp;
	price_t _max_cost; 

	excess_t _total_p; 

	excess_t _total_n; 

	

	NODE *_i_node;
	NODE *_j_node;

 public:
	MCMF_CS2( long num_nodes, long num_arcs) {
		_n = num_nodes;
		_m = num_arcs;

		_flag_price = 0;
		_flag_updt = 0;
		_n_push = 0;
		_n_relabel = 0;
		_n_discharge = 0;
		_n_refine = 0;
		_n_update = 0;
		_n_scan = 0;
		_n_prscan = 0;
		_n_prscan1 = 0;
		_n_prscan2 = 0;
		_n_bad_pricein = 0;
		_n_bad_relabel = 0;
		_n_prefine = 0;
		_no_zero_cycles = false;
		_check_solution = false;
		_comp_duals = false;
		_cost_restart = false;
		_print_ans = true;
		

		

		allocate_arrays();
	}
	~MCMF_CS2() {}

	void err_end( int cc);
	void allocate_arrays();
	void deallocate_arrays();
	void set_arc( long tail_node_id, long head_node_id,
				  long low_bound, long up_bound, price_t cost);
	void set_supply_demand_of_node( long id, long excess);
	void pre_processing();
	void cs2_initialize();
	void up_node_scan( NODE *i);
	void price_update();
	int relabel( NODE *i);
	void discharge( NODE *i);
	int price_in();
	void refine();
	int price_refine();
	void compute_prices();
	void price_out();
	int update_epsilon();
	int check_feas();
	int check_cs();
	int check_eps_opt();
	void init_solution();
	void cs_cost_reinit();
	void cs2_cost_restart( double *objective_cost);
	void print_solution();
	void print_graph();
	void finishup( double *objective_cost);
	void cs2( double *objective_cost);
	int run_cs2();

	

	void increase_flow( NODE *i, NODE *j, ARC *a, long df) {
		i->dec_excess( df);
		j->inc_excess( df);
		a->dec_rez_capacity( df);
		a->sister()->inc_rez_capacity( df);
	}
	bool time_for_update() { 
		return ( _n_rel > _n * UPDT_FREQ + _n_src * UPDT_FREQ_S); 
	}
	

	void reset_excess_q() {
		for ( ; _excq_first != NULL; _excq_first = _excq_last ) {
			_excq_last = _excq_first->q_next();
			_excq_first->set_q_next( _sentinel_node);
		}
	}
	bool out_of_excess_q( NODE *i) { return ( i->q_next() == _sentinel_node); }
	bool empty_excess_q() { return ( _excq_first == NULL); }
	bool nonempty_excess_q() { return ( _excq_first != NULL); }
	void insert_to_excess_q( NODE *i) {
		if ( nonempty_excess_q() ) {
			_excq_last->set_q_next( i);
		} else {
			_excq_first = i;
		}
		i->set_q_next( NULL);
		_excq_last = i;
	}
	void insert_to_front_excess_q( NODE *i) {
		if ( empty_excess_q() ) {
			_excq_last = i;
		}
		i->set_q_next( _excq_first);
		_excq_first = i;
	}
	void remove_from_excess_q( NODE *i) {
		i = _excq_first;
		_excq_first = i->q_next();
		i->set_q_next( _sentinel_node);
	}
	

	bool empty_stackq() { return empty_excess_q(); }
	bool nonempty_stackq() { return nonempty_excess_q(); }
	void reset_stackq() { reset_excess_q(); }
	void stackq_push( NODE *i) {
		i->set_q_next( _excq_first);
		_excq_first = i;
	}
	void stackq_pop( NODE *i) {
		remove_from_excess_q( i);
	}
	

	void reset_bucket( BUCKET *b) { b->set_p_first( _dnode); }
	bool nonempty_bucket( BUCKET *b) { return ( (b->p_first()) != _dnode); }
	void insert_to_bucket( NODE *i, BUCKET *b) {
		i->set_b_next( b->p_first() );
		b->p_first()->set_b_prev( i);
		b->set_p_first( i);
	}
	void get_from_bucket( NODE *i, BUCKET *b) {
		i = b->p_first();
		b->set_p_first( i->b_next());
	}
	void remove_from_bucket( NODE *i, BUCKET *b) {
		if ( i == b->p_first() ) {
			b->set_p_first( i->b_next());
		} else {
			i->b_prev()->set_b_next( i->b_next());
			i->b_next()->set_b_prev( i->b_prev());
		}
	}
	

	void update_cut_off() {
		if ( _n_bad_pricein + _n_bad_relabel == 0) {
			_cut_off_factor = CUT_OFF_COEF2 * pow( (double)_n, CUT_OFF_POWER2 );
			_cut_off_factor = MAX ( _cut_off_factor, CUT_OFF_MIN );
			_cut_off = _cut_off_factor * _epsilon;
			_cut_on = _cut_off * CUT_OFF_GAP;
		} else {
			_cut_off_factor *= CUT_OFF_INCREASE;
			_cut_off = _cut_off_factor * _epsilon;
			_cut_on = _cut_off * CUT_OFF_GAP;
		}
	}
	void exchange( ARC *a, ARC *b) {
		if ( a != b) {
			ARC *sa = a->sister();
			ARC *sb = b->sister();
			long d_cap;						

			_d_arc.set_rez_capacity( a->rez_capacity());
			_d_arc.set_cost( a->cost());
			_d_arc.set_head( a->head());

			a->set_rez_capacity( b->rez_capacity());
			a->set_cost( b->cost());
			a->set_head( b->head());

			b->set_rez_capacity( _d_arc.rez_capacity());
			b->set_cost( _d_arc.cost());
			b->set_head( _d_arc.head());

			if ( a != sb) {			
				b->set_sister( sa);
				a->set_sister( sb);
				sa->set_sister( b);
				sb->set_sister( a);
			}
						
			d_cap = _cap[ a - _arcs];
			_cap[ a - _arcs] = _cap[ b - _arcs];
			_cap[ b - _arcs] = d_cap;	
		}
	}
};

#endif

using namespace std;












#define WHITE 0
#define GREY  1
#define BLACK 2
#define OPEN( a ) ( a->rez_capacity() > 0 )
#define CLOSED( a ) ( a->rez_capacity() <= 0 )
#define REDUCED_COST( i, j, a ) ( i->price() + a->cost() - j->price() )
#define FEASIBLE( i, j, a ) ( i->price() + a->cost() < j->price() )
#define ADMISSIBLE( i, j, a ) ( OPEN( a ) && FEASIBLE( i, j, a ) )
#define SUSPENDED( i, a ) ( a < i->first() )


#define REMOVE_FROM_EXCESS_Q( i )				\
	{											\
		i           = _excq_first;				\
		_excq_first = i -> q_next();			\
		i ->set_q_next( _sentinel_node );		\
	}

#define STACKQ_POP( i )							\
	{											\
		i           = _excq_first;				\
		_excq_first = i -> q_next();			\
		i ->set_q_next( _sentinel_node );		\
	}

#define GET_FROM_BUCKET( i, b )					\
	{											\
		i    = ( b -> p_first() );				\
		b ->set_p_first( i -> b_next() );		\
	}
#define REMOVE_FROM_BUCKET( i, b )								\
	{															\
		if ( i == ( b -> p_first() ) )							\
			b ->set_p_first( i -> b_next() );					\
		else													\
			{													\
				( i -> b_prev() )->set_b_next( i -> b_next() );	\
				( i -> b_next() )->set_b_prev( i -> b_prev() );	\
			}													\
	}


void MCMF_CS2::err_end( int cc)
{
	

	

	

	

	

	exit( cc);
}

void MCMF_CS2::allocate_arrays()
{
	


	_nodes = (NODE*) calloc ( _n+2,   sizeof(NODE) );
	_arcs = (ARC*)  calloc ( 2*_m+1, sizeof(ARC) );
	_cap = (long*) calloc ( 2*_m,   sizeof(long) );

	_arc_tail = (long*) calloc ( 2*_m,   sizeof(long) );
	_arc_first = (long*) calloc ( _n+2,   sizeof(long) );
	


	for ( NODE *in = _nodes; in <= _nodes + _n; in ++ ) {
		in->set_excess( 0);
	}
	if ( _nodes == NULL || _arcs == NULL || _arc_first == NULL || _arc_tail == NULL) {
		

		exit( 1);
	}

	

	_pos_current = 0;
	_arc_current = _arcs; 

	_node_max = 0;
	_node_min = _n;
	_max_cost = 0;
	_total_p = _total_n = 0;
	

	

}

void MCMF_CS2::deallocate_arrays()
{ 
	if ( _arcs) free ( _arcs );
	if ( _dnode) delete _dnode;
	if ( _cap) free ( _cap );
	if ( _buckets) free ( _buckets );
	if ( _check_solution == true) free ( _node_balance );
	if ( _nodes) {
		_nodes = _nodes - _node_min;
		free ( _nodes );
	}
}

void MCMF_CS2::set_arc( long tail_node_id, long head_node_id,
						long low_bound, long up_bound, 

						price_t cost)
{
	

	


	if ( tail_node_id < 0 || tail_node_id > _n || 
		 head_node_id < 0 || head_node_id > _n ) {
		

		exit( 1);
	}
	if ( up_bound < 0 ) {
		up_bound = MAX_32;
		

	}
	if ( low_bound < 0 || low_bound > up_bound ) {
		

		exit( 1);
	}

	

	_arc_first[tail_node_id + 1] ++; 
	_arc_first[head_node_id + 1] ++;
	_i_node = _nodes + tail_node_id;
	_j_node = _nodes + head_node_id;

	

	_arc_tail[_pos_current]   = tail_node_id;
	_arc_tail[_pos_current+1] = head_node_id;
	_arc_current->set_head( _j_node );
	_arc_current->set_rez_capacity( up_bound - low_bound );
	_cap[_pos_current] = up_bound;
	_arc_current->set_cost( cost );
	_arc_current->set_sister( _arc_current + 1 );
	( _arc_current + 1 )->set_head( _nodes + tail_node_id );
	( _arc_current + 1 )->set_rez_capacity( 0 );
	_cap[_pos_current+1] = 0;
	( _arc_current + 1 )->set_cost( -cost );
	( _arc_current + 1 )->set_sister( _arc_current );

	_i_node->dec_excess( low_bound );
	_j_node->inc_excess( low_bound );

	

	if ( head_node_id < _node_min ) _node_min = head_node_id;
	if ( tail_node_id < _node_min ) _node_min = tail_node_id;
	if ( head_node_id > _node_max ) _node_max = head_node_id;
	if ( tail_node_id > _node_max ) _node_max = tail_node_id;

	if ( cost < 0 ) cost = -cost;
	if ( cost > _max_cost && up_bound > 0 ) _max_cost = cost;

	

	_arc_current += 2;
	_pos_current += 2;
}

void MCMF_CS2::set_supply_demand_of_node( long id, long excess)
{
	

	if ( id < 0 || id > _n ) {
		

		exit( 1);
	}
	(_nodes + id)->set_excess( excess);
	if ( excess > 0) _total_p += excess;
	if ( excess < 0) _total_n -= excess;
}

void MCMF_CS2::pre_processing()
{
	

	

	long i;
	long last, arc_num, arc_new_num;;
	long tail_node_id;
	NODE *head_p;
	ARC *arc_new, *arc_tmp;	
	long up_bound;
	price_t cost; 

	excess_t cap_out; 

	excess_t cap_in; 


	if ( ABS( _total_p - _total_n ) > 0.5 ) {
		cout << _total_p << ' ' << _total_n << '\n';
		

		exit( 1);
	}
	
	

	( _nodes + _node_min )->set_first( _arcs );

	

	

	

	

	for ( i = _node_min + 1; i <= _node_max + 1; i ++ ) {
		_arc_first[i] += _arc_first[i-1];
		( _nodes + i )->set_first( _arcs + _arc_first[i] );
	}

	

	for ( i = _node_min; i < _node_max; i ++ ) {

		last = ( ( _nodes + i + 1 )->first() ) - _arcs;
		

		

		


		for ( arc_num = _arc_first[i]; arc_num < last; arc_num ++ ) {
			tail_node_id = _arc_tail[arc_num];

			while ( tail_node_id != i ) {
				

				

				

				


				arc_new_num = _arc_first[tail_node_id];
				_arc_current = _arcs + arc_num;
				arc_new = _arcs + arc_new_num;
	    
				

				


				head_p = arc_new->head();
				arc_new->set_head( _arc_current->head() );
				_arc_current->set_head( head_p );

				up_bound          = _cap[arc_new_num];
				_cap[arc_new_num] = _cap[arc_num];
				_cap[arc_num]     = up_bound;

				up_bound = arc_new->rez_capacity();
				arc_new->set_rez_capacity( _arc_current->rez_capacity() );
				_arc_current->set_rez_capacity( up_bound) ;

				cost = arc_new->cost();
				arc_new->set_cost( _arc_current->cost() );
				_arc_current->set_cost( cost );

				if ( arc_new != _arc_current->sister() ) {
					arc_tmp = arc_new->sister();
					arc_new->set_sister( _arc_current->sister() );
					_arc_current->set_sister( arc_tmp );

					_arc_current->sister()->set_sister( _arc_current );
					arc_new->sister()->set_sister( arc_new );
				}

				_arc_tail[arc_num] = _arc_tail[arc_new_num];
				_arc_tail[arc_new_num] = tail_node_id;

				

				_arc_first[tail_node_id] ++ ;

				tail_node_id = _arc_tail[arc_num];
			}
		}
		

	}       
	



	

	for ( NODE *ndp = _nodes + _node_min; ndp <= _nodes + _node_max; ndp ++ ) {
		cap_in  =   ( ndp->excess() );
		cap_out = - ( ndp->excess() );
		for ( _arc_current = ndp->first(); _arc_current != (ndp+1)->first(); 
			  _arc_current ++ ) {
			arc_num = _arc_current - _arcs;
			if ( _cap[arc_num] > 0 ) cap_out += _cap[arc_num];
			if ( _cap[arc_num] == 0 ) 
				cap_in += _cap[ _arc_current->sister() - _arcs ];
		}
	}
	if ( _node_min < 0 || _node_min > 1 ) {
		

		exit( 1);
	}

	

	_n = _node_max - _node_min + 1;
	_nodes = _nodes + _node_min;

	

	free ( _arc_first ); 
	free ( _arc_tail );
}

void MCMF_CS2::cs2_initialize()
{
	

	


	NODE *i; 

	ARC *a; 

	ARC *a_stop;
	BUCKET *b; 

	long df;

	_f_scale = (long) SCALE_DEFAULT;
	_sentinel_node = _nodes + _n;
	_sentinel_arc  = _arcs + _m;

	for ( i = _nodes; i != _sentinel_node; i ++ ) {
		i->set_price( 0);
		i->set_suspended( i->first());
		i->set_q_next( _sentinel_node);
	}

	_sentinel_node->set_first( _sentinel_arc);
	_sentinel_node->set_suspended( _sentinel_arc);

	

	for ( i = _nodes; i != _sentinel_node; i ++ ) {
		for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++ ) {
			if ( a->cost() < 0) {
				if ( ( df = a->rez_capacity()) > 0) {
					increase_flow( i, a->head(), a, df);
				}
			}
		}
	}

	_dn = _n + 1;
	if ( _no_zero_cycles == true) { 

		_dn = 2 * _dn;
	}

	for ( a = _arcs; a != _sentinel_arc; a ++ ) {
		a->multiply_cost( _dn);
	}

	if ( _no_zero_cycles == true) { 

		for ( a = _arcs; a != _sentinel_arc; a ++ ) {
			if ((a->cost() == 0) && (a->sister()->cost() == 0)) {
				a->set_cost( 1);
				a->sister()->set_cost( -1);
			}
		}
	}

	if ((double) _max_cost * (double) _dn > MAX_64) {
		

	}
	_mmc = _max_cost * _dn;

	_linf = (long) (_dn * ceil(_f_scale) + 2);

	_buckets = (BUCKET*) calloc ( _linf, sizeof(BUCKET));
	if ( _buckets == NULL )
		err_end( ALLOCATION_FAULT);

	_l_bucket = _buckets + _linf;

	_dnode = new NODE; 


	for ( b = _buckets; b != _l_bucket; b ++ ) {
		reset_bucket( b);
	}

	_epsilon = _mmc;
	if ( _epsilon < 1) {
		_epsilon = 1;
	}

	_price_min = -PRICE_MAX;

	_cut_off_factor = CUT_OFF_COEF * pow( (double)_n, CUT_OFF_POWER);

	_cut_off_factor = MAX( _cut_off_factor, CUT_OFF_MIN);

	_n_ref = 0;

	_flag_price = 0;

	_dummy_node = &_d_node;

	_excq_first = NULL;

	

}

void MCMF_CS2::up_node_scan( NODE *i)
{
	NODE *j; 

	ARC *a; 

	ARC *a_stop; 

	ARC *ra; 

	BUCKET *b_old; 

	BUCKET *b_new; 

	long i_rank;
	long j_rank; 

	long j_new_rank;             
	price_t rc; 

	price_t dr; 


	_n_scan ++;

	i_rank = i->rank();

	

	for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++ ) {

		ra = a->sister();

		if ( OPEN ( ra ) ) {
			j = a->head();
			j_rank = j->rank();

			if ( j_rank > i_rank ) {
				if ( ( rc = REDUCED_COST( j, i, ra ) ) < 0 ) {
					j_new_rank = i_rank;
				} else {
					dr = rc / _epsilon;
					j_new_rank = ( dr < _linf ) ? i_rank + (long)dr + 1 : _linf;
				}

				if ( j_rank > j_new_rank ) {
					j->set_rank( j_new_rank);
					j->set_current( ra);

					if ( j_rank < _linf ) {
						b_old = _buckets + j_rank;
						REMOVE_FROM_BUCKET( j, b_old );
					}

					b_new = _buckets + j_new_rank;
					insert_to_bucket( j, b_new );
				}
			}
		}
	}

	i->dec_price( i_rank * _epsilon);
	i->set_rank( -1);
}

void MCMF_CS2::price_update()
{
	register NODE *i;
	excess_t remain;
	

	BUCKET *b; 

	price_t dp; 


	_n_update ++;

	for ( i = _nodes; i != _sentinel_node; i ++ ) {
		if ( i->excess() < 0 ) {
			insert_to_bucket( i, _buckets );
			i->set_rank( 0);
		} else {
			i->set_rank( _linf);
		}
	}

	remain = _total_excess;
	if ( remain < 0.5 ) return;

	

	for ( b = _buckets; b != _l_bucket; b ++ ) {

		while ( nonempty_bucket( b) ) {

			GET_FROM_BUCKET( i, b );
			up_node_scan( i );

			if ( i ->excess() > 0 ) {
				remain -= ( i->excess());
				if ( remain <= 0 ) break; 
			}
		}
		if ( remain <= 0 ) break; 
	}

	if ( remain > 0.5 ) _flag_updt = 1;

	

	

	dp = ( b - _buckets ) * _epsilon;

	for ( i = _nodes; i != _sentinel_node; i ++ ) {

		if ( i->rank() >= 0 ) {
			if ( i->rank() < _linf ) {
				REMOVE_FROM_BUCKET( i, ( _buckets + i->rank()) );
			}
			if ( i->price() > _price_min ) {
				i->dec_price( dp);
			}			
		}
	}
}

int MCMF_CS2::relabel( NODE *i)
{
	register ARC *a; 

	register ARC *a_stop; 

	register ARC *a_max; 

	register price_t p_max; 

	register price_t i_price; 

	register price_t dp; 


	p_max = _price_min;
	i_price = i->price();

	a_max = NULL;

	

	for ( a = i->current() + 1, a_stop = (i + 1)->suspended(); a != a_stop; a ++ ) {
		
		if ( OPEN(a) && ( (dp = (a->head()->price() - a->cost())) > p_max ) ) {
			if ( i_price < dp ) {
				i->set_current( a);
				return ( 1);
			}
			p_max = dp;
			a_max = a;
		}
	}

	

	for ( a = i->first(), a_stop = i->current() + 1; a != a_stop; a ++ ) {
		if ( OPEN( a) && ( (dp = (a->head()->price() - a->cost())) > p_max ) ) {
			if ( i_price < dp ) {
				i->set_current( a);
				return ( 1);
			}
			p_max = dp;
			a_max = a;
		}
	}

	

	if ( p_max != _price_min ) {
		i->set_price( p_max - _epsilon);
		i->set_current( a_max);
	} 
	else { 

		if ( i->suspended() == i->first() ) {
			if ( i->excess() == 0 ) {
				i->set_price( _price_min);
			} else {
				if ( _n_ref == 1 ) {
					err_end( UNFEASIBLE );
				} else {
					err_end( PRICE_OFL );
				}
			}
		} else { 

			_flag_price = 1;
		}
	}

	_n_relabel ++;
	_n_rel ++;
	return ( 0);
}

void MCMF_CS2::discharge( NODE *i)
{
	register ARC *a;

	register NODE *j; 

	register long df; 

	excess_t j_exc; 


	_n_discharge ++;

	a = i->current();
	j = a->head();

	if ( !ADMISSIBLE( i, j, a ) ) { 
		relabel( i );
		a = i->current();
		j = a->head();
	}

	while ( 1 ) {

		j_exc = j->excess();
		if ( j_exc >= 0 ) {

			df = MIN( i->excess(), a->rez_capacity() );
			if ( j_exc == 0) _n_src++;
			increase_flow( i, j, a, df ); 

			_n_push ++;

			if ( out_of_excess_q( j ) ) {
				insert_to_excess_q( j );
			}
		} 
		else { 


			df = MIN( i->excess(), a->rez_capacity() );
			increase_flow( i, j, a, df ); 

			_n_push ++;

			if ( j->excess() >= 0 ) {
				if ( j->excess() > 0 ) {
					_n_src ++;
					relabel( j );
					insert_to_excess_q( j );
				}
				_total_excess += j_exc;
			}
			else {
				_total_excess -= df;
			}
		}
  
		if ( i->excess() <= 0) _n_src --;
		if ( i->excess() <= 0 || _flag_price ) break;

		relabel( i );

		a = i->current();
		j = a->head();
	}

	i->set_current( a);
}

int MCMF_CS2::price_in()
{
	NODE *i; 

	NODE *j;
	ARC *a; 

	ARC *a_stop; 

	ARC *b; 

	ARC *ra; 

	ARC *rb; 

	price_t rc; 

	int n_in_bad; 

	int bad_found; 

	excess_t i_exc; 

	excess_t df; 



	bad_found = 0;
	n_in_bad = 0;

 restart:

	for ( i = _nodes; i != _sentinel_node; i ++ ) {

		for ( a = i->first() - 1, a_stop = i->suspended() - 1; a != a_stop; a -- ) {

			rc = REDUCED_COST( i, a->head(), a );
			if ( ( rc < 0) && ( a->rez_capacity() > 0) ) { 

				if ( bad_found == 0 ) {
					bad_found = 1;
					update_cut_off();
					goto restart;
				}
				df = a->rez_capacity();
				increase_flow( i, a->head(), a, df );
	    
				ra = a->sister();
				j  = a->head();
	    
				i->dec_first();
				b = i->first();
				exchange( a, b );
	    
				if ( SUSPENDED( j, ra ) ) {
					j->dec_first();
					rb = j->first();
					exchange( ra, rb );
				}
	    
				n_in_bad ++; 
			}
			else {
				if ( ( rc < _cut_on ) && ( rc > -_cut_on ) ) {
					i->dec_first();
					b = i->first();
					exchange( a, b );
				}
			}
		}
	}


	if ( n_in_bad != 0 ) {

		_n_bad_pricein ++;

		

		_total_excess = 0;
		_n_src = 0;
		reset_excess_q();

		for ( i = _nodes; i != _sentinel_node; i ++ ) {
			i->set_current( i->first());
			i_exc = i->excess();
			if ( i_exc > 0 ) { 

				_total_excess += i_exc;
				_n_src ++;
				insert_to_excess_q( i );
			}
		}

		insert_to_excess_q( _dummy_node );
	}

	if ( _time_for_price_in == TIME_FOR_PRICE_IN2)
		_time_for_price_in = TIME_FOR_PRICE_IN3;
	if ( _time_for_price_in == TIME_FOR_PRICE_IN1)
		_time_for_price_in = TIME_FOR_PRICE_IN2;

	return ( n_in_bad);
}

void MCMF_CS2::refine()
{
	NODE *i; 

	excess_t i_exc; 

	long np, nr, ns; 

	int pr_in_int; 


	np = _n_push; 
	nr = _n_relabel; 
	ns = _n_scan;

	_n_refine ++;
	_n_ref ++;
	_n_rel = 0;
	pr_in_int = 0;

	

	_total_excess = 0;
	_n_src = 0;
	reset_excess_q();

	_time_for_price_in = TIME_FOR_PRICE_IN1;

	for ( i = _nodes; i != _sentinel_node; i ++ ) {
		i->set_current( i->first());
		i_exc = i->excess();
		if ( i_exc > 0 ) { 

			_total_excess += i_exc;
			_n_src++;
			insert_to_excess_q( i );
		}
	}

	if ( _total_excess <= 0 ) return;

	


	while ( 1 ) {

		if ( empty_excess_q() ) {
			if ( _n_ref > PRICE_OUT_START ) {
				pr_in_int = 0;
				price_in();
			}
	  
			if ( empty_excess_q() ) break;
		}
		
		REMOVE_FROM_EXCESS_Q( i );

		

		if ( i->excess() > 0 ) {
			discharge( i );

			if ( time_for_update() || _flag_price ) {
				if ( i->excess() > 0 ) {
					insert_to_excess_q( i );
				}

				if ( _flag_price && ( _n_ref > PRICE_OUT_START ) ) {
					pr_in_int = 0;
					price_in();
					_flag_price = 0;
				}

				price_update();

				while ( _flag_updt ) {
					if ( _n_ref == 1 ) {
						err_end( UNFEASIBLE );
					} else {
						_flag_updt = 0;
						update_cut_off();
						_n_bad_relabel ++;
						pr_in_int = 0;
						price_in();
						price_update();
					}
				}
				_n_rel = 0;

				if ( _n_ref > PRICE_OUT_START && (pr_in_int ++ > _time_for_price_in) ) {
					pr_in_int = 0;
					price_in();
				}
			}
		}
	}

	return;
}

int MCMF_CS2::price_refine()
{
	NODE *i; 

	NODE *j; 

	NODE *ir; 

	NODE *is;
	ARC *a; 

	ARC *a_stop; 

	ARC *ar;
	long bmax;            

	long i_rank;          

	long j_rank;         

	long j_new_rank;      

	BUCKET *b;              

	BUCKET *b_old;          

	BUCKET *b_new;
	price_t rc = 0; 

	price_t dr; 

	price_t dp;
	int cc;              
	

	

	long df; 

	int nnc; 

	int snc; 


	_n_prefine ++;

	cc = 1;
	snc = 0;

	_snc_max = ( _n_ref >= START_CYCLE_CANCEL) ? MAX_CYCLES_CANCELLED : 0;


	

	

	while ( 1 ) { 

		nnc = 0;
		for ( i = _nodes; i != _sentinel_node; i ++ ) {
			i->set_rank( 0);
			i->set_inp( WHITE);
			i->set_current( i->first());
		}
		reset_stackq();

		for ( i = _nodes; i != _sentinel_node; i ++ ) {
			if ( i->inp() == BLACK ) continue;

			i->set_b_next( NULL);

			

			while ( 1 ) {
				i->set_inp( GREY);

				

				for ( a = i->current(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
					if ( OPEN( a ) ) {
						j = a->head();
						if ( REDUCED_COST ( i, j, a ) < 0 ) {
							if ( j->inp() == WHITE ) { 

								i->set_current( a);
								j->set_b_next( i);
								i = j;
								a = j->current();
								a_stop = (j+1)->suspended();
								break;
							}

							if ( j->inp() == GREY ) { 

								cc = 0;
								nnc ++;
								i->set_current( a);
								is = ir = i;
								df = MAX_32;

								while ( 1 ) {
									ar = ir->current();
									if ( ar->rez_capacity() <= df ) {
										df = ar->rez_capacity();
										is = ir;
									}
									if ( ir == j ) break;
									ir = ir->b_next();
								}

								ir = i;

								while ( 1 ) {
									ar = ir->current();
									increase_flow( ir, ar->head(), ar, df);
									if ( ir == j ) break;
									ir = ir->b_next();
								}

								if ( is != i ) {
									for ( ir = i; ir != is; ir = ir->b_next() ) {
										ir->set_inp( WHITE);
									}
									i = is;
									a = is->current() + 1;
									a_stop = (is+1)->suspended();
									break;
								}
							}
						}
						

					}
				} 


				if ( a == a_stop ) {
					

					i->set_inp( BLACK);
					_n_prscan1 ++;
					j = i->b_next();
					stackq_push( i );
					if ( j == NULL ) break;
					i = j;
					i->inc_current();
				}

			} 

		} 



		

		


		snc += nnc;
		if ( snc < _snc_max ) cc = 1;
		if ( cc == 0 ) break;
		bmax = 0;

		while ( nonempty_stackq() ) {

			_n_prscan2 ++;
			STACKQ_POP( i );
			i_rank = i->rank();
			for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {

				if ( OPEN( a ) ) {
					j  = a->head();
					rc = REDUCED_COST( i, j, a );

					if ( rc < 0 ) { 

						dr = (price_t) (( - rc - 0.5 ) / _epsilon);
						if (( j_rank = dr + i_rank ) < _linf ) {
							if ( j_rank > j->rank() )
								j->set_rank( j_rank);
						}
					}
				}
			} 


			if ( i_rank > 0 ) {
				if ( i_rank > bmax ) bmax = i_rank;
				b = _buckets + i_rank;
				insert_to_bucket( i, b );
			}
		} 



		if ( bmax == 0 ) 

			{ break; }


		for ( b = _buckets + bmax; b != _buckets; b -- ) {
			i_rank = b - _buckets;
			dp = i_rank * _epsilon;

			while ( nonempty_bucket( b) ) {
				GET_FROM_BUCKET( i, b );
				_n_prscan ++;

				for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
					if ( OPEN( a ) ) {
						j = a->head();
						j_rank = j->rank();
						if ( j_rank < i_rank ) {
							rc = REDUCED_COST( i, j, a );
							if ( rc < 0 ) {
								j_new_rank = i_rank;
							} else {
								dr = rc / _epsilon;
								j_new_rank = ( dr < _linf ) ? i_rank - ( (long)dr + 1 ) : 0;
							}
							if ( j_rank < j_new_rank ) {
								if ( cc == 1 ) {
									j->set_rank( j_new_rank);
									if ( j_rank > 0 ) {
										b_old = _buckets + j_rank;
										REMOVE_FROM_BUCKET( j, b_old );
									}
									b_new = _buckets + j_new_rank;
									insert_to_bucket( j, b_new );
								}
								else {
									df = a->rez_capacity();
									increase_flow( i, j, a, df );
								}
							}
						}
					} 

				} 


				i->dec_price( dp);

			} 

		} 


		if ( cc == 0 ) break;

	} 




	

	


	if ( cc == 0 ) { 
		for ( i = _nodes; i != _sentinel_node; i ++) {
			for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
				if ( REDUCED_COST( i, a->head(), a ) < - _epsilon ) {
					if ( ( df = a->rez_capacity() ) > 0 ) {
						increase_flow( i, a->head(), a, df );
					}
				}
			}
		}
	}

	return ( cc );
}

void MCMF_CS2::compute_prices()
{
	NODE *i; 

	NODE *j; 

	ARC *a; 

	ARC *a_stop; 

	long bmax; 

	long i_rank; 

	long j_rank; 

	long j_new_rank; 

	BUCKET *b; 

	BUCKET *b_old; 

	BUCKET *b_new;
	price_t rc; 

	price_t dr; 

	price_t dp;
	int cc; 


	_n_prefine ++;
	cc = 1;

	

	

	while ( 1 ) {

		for ( i = _nodes; i != _sentinel_node; i ++) {
			i->set_rank( 0);
			i->set_inp( WHITE);
			i->set_current( i->first());
		}
		reset_stackq();

		for ( i = _nodes; i != _sentinel_node; i ++ ) {
			if ( i->inp() == BLACK ) continue;

			i->set_b_next( NULL);
			

			while ( 1 ) {
				i->set_inp( GREY);

				

				for ( a = i->suspended(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
					if ( OPEN( a ) ) {
						j = a->head();
						if ( REDUCED_COST( i, j, a ) < 0 ) {
							if ( j->inp() == WHITE ) { 

								i->set_current( a);
								j->set_b_next( i);
								i = j;
								a = j->current();
								a_stop = (j+1)->suspended();
								break;
							}

							if ( j->inp() == GREY ) { 

								cc = 0;
							}                     
						}
						

					} 
				} 


				if ( a == a_stop ) {
					

					i->set_inp( BLACK);
					_n_prscan1 ++;
					j = i->b_next();
					stackq_push( i );
					if ( j == NULL ) break;
					i = j;
					i->inc_current();
				}

			} 

		} 



		

		


		if ( cc == 0 ) break;
		bmax = 0;

		while ( nonempty_stackq() ) {
			_n_prscan2 ++;
			STACKQ_POP( i );
			i_rank = i->rank();
			for ( a = i->suspended(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
				if ( OPEN( a ) ) {
					j  = a->head();
					rc = REDUCED_COST( i, j, a );


					if ( rc < 0 ) {

						dr = - rc;
						if (( j_rank = dr + i_rank ) < _linf ) {
							if ( j_rank > j->rank() )
								j->set_rank( j_rank);
						}
					}
				}
			} 


			if ( i_rank > 0 ) {
				if ( i_rank > bmax ) bmax = i_rank;
				b = _buckets + i_rank;
				insert_to_bucket( i, b );
			}
		} 


		if ( bmax == 0 )
			{ break; }

		for ( b = _buckets + bmax; b != _buckets; b -- ) {
			i_rank = b - _buckets;
			dp = i_rank;

			while ( nonempty_bucket( b) ) {
				GET_FROM_BUCKET( i, b );
				_n_prscan ++;

				for ( a = i->suspended(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
					if ( OPEN( a ) ) {
						j = a->head();
						j_rank = j->rank();
						if ( j_rank < i_rank ) {
							rc = REDUCED_COST( i, j, a );
 
							if ( rc < 0 ) {
								j_new_rank = i_rank;
							} else {
								dr = rc;
								j_new_rank = ( dr < _linf ) ? i_rank - ( (long)dr + 1 ) : 0;
							}
							if ( j_rank < j_new_rank ) {
								if ( cc == 1 ) {
									j->set_rank( j_new_rank);
									if ( j_rank > 0 ) {
										b_old = _buckets + j_rank;
										REMOVE_FROM_BUCKET( j, b_old );
									}
									b_new = _buckets + j_new_rank;
									insert_to_bucket( j, b_new );
								}
							}
						}
					} 

				} 


				i->dec_price( dp);

			} 

		} 


		if ( cc == 0 ) break;

	} 

} 

void MCMF_CS2::price_out()
{
	NODE *i; 

	ARC *a; 

	ARC *a_stop; 

	ARC *b; 

	double n_cut_off; 

	double rc; 


	n_cut_off = - _cut_off;

	for ( i = _nodes; i != _sentinel_node; i ++) {
		for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {

			rc = REDUCED_COST( i, a->head(), a );		
			if ( ( rc > _cut_off && CLOSED(a->sister()) ) ||
				 ( rc < n_cut_off && CLOSED(a) ) ) { 


				b = i->first();
				i->inc_first();
				exchange( a, b );
			}
		}
	}
}

int MCMF_CS2::update_epsilon()
{
	

	if ( _epsilon <= 1 ) return ( 1 );

	_epsilon = (price_t) (ceil ( (double) _epsilon / _f_scale ));
	_cut_off = _cut_off_factor * _epsilon;
	_cut_on = _cut_off * CUT_OFF_GAP;

	return ( 0 );
}

int MCMF_CS2::check_feas()
{
	if ( _check_solution == false)
		return ( 0);
	
	NODE *i;
	ARC *a, *a_stop;
	long fa;
	int ans = 1;

	for ( i = _nodes; i != _sentinel_node; i ++) {
		for ( a = i->suspended(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {
			if ( _cap[ N_ARC(a) ] > 0) {
				fa = _cap[ N_ARC(a) ] - a->rez_capacity();
				if ( fa < 0) {
					ans = 0;
					break;
				}
				_node_balance[ i - _nodes ] -= fa;
				_node_balance[ a->head() - _nodes ] += fa;
			}
		}
	}

	for ( i = _nodes; i != _sentinel_node; i ++) {
		if ( _node_balance[ i - _nodes ] != 0) {
			ans = 0;
			break;
		}
	}

	return ( ans);
}

int MCMF_CS2::check_cs()
{
	

	NODE *i;
	ARC *a, *a_stop;

	for ( i = _nodes; i != _sentinel_node; i ++) {
		for ( a = i->suspended(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {

			if ( OPEN(a) && (REDUCED_COST(i, a->head(), a) < 0) ) {
				return ( 0);
			}
		}
	}
	return(1);
}

int MCMF_CS2::check_eps_opt()
{
	NODE *i;
	ARC *a, *a_stop;

	for ( i = _nodes; i != _sentinel_node; i ++) {
		for ( a = i->suspended(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {

			if ( OPEN(a) && (REDUCED_COST(i, a->head(), a) < - _epsilon) ) {
				return ( 0);
			}
		}
	}
	return(1);
}

void MCMF_CS2::init_solution()
{
	ARC *a; 

	NODE *i; 

	NODE *j; 

	long df; 


	for ( a = _arcs; a != _sentinel_arc; a ++ ) {
		if ( a->rez_capacity() > 0 && a->cost() < 0 ) {
			df = a->rez_capacity();
			i  = a->sister()->head();
			j  = a->head();
			increase_flow( i, j, a, df );
		}
	}
}

void MCMF_CS2::cs_cost_reinit()
{
	if ( _cost_restart == false)
		return;
	
	NODE *i; 

	ARC *a;          

	ARC *a_stop;
	BUCKET *b; 

	price_t rc, minc, sum;


	for ( b = _buckets; b != _l_bucket; b ++) {
		reset_bucket( b);
	}

	rc = 0;
	for ( i = _nodes; i != _sentinel_node; i ++) {
		rc = MIN(rc, i->price());
		i->set_first( i->suspended());
		i->set_current( i->first());
		i->set_q_next( _sentinel_node);
	}

	

	for ( i = _nodes; i != _sentinel_node; i ++) {
		i->set_price( (i->price() - rc) * _dn);
	}

	

	for (a = _arcs; a != _sentinel_arc; a ++) {
		a->multiply_cost( _dn);
	}

	sum = 0;
	for ( i = _nodes; i != _sentinel_node; i ++) {
		minc = 0;
		for ( a = i->first(), a_stop = (i + 1)->suspended(); a != a_stop; a ++) {		
			if ( (OPEN(a) && ((rc = REDUCED_COST(i, a->head(), a)) < 0)) )
				minc = MAX( _epsilon, -rc);
		}
		sum += minc;
	}

	_epsilon = ceil(sum / _dn);

	_cut_off_factor = CUT_OFF_COEF * pow((double)_n, CUT_OFF_POWER);

	_cut_off_factor = MAX( _cut_off_factor, CUT_OFF_MIN);

	_n_ref = 0;

	_n_refine = _n_discharge = _n_push = _n_relabel = 0;
	_n_update = _n_scan = _n_prefine = _n_prscan = _n_prscan1 = 
		_n_bad_pricein = _n_bad_relabel = 0;

	_flag_price = 0;

	_excq_first = NULL;
}

void MCMF_CS2::cs2_cost_restart( double *objective_cost)
{
	

	if ( _cost_restart == false)
		return;

	int cc; 


	

	

	


	cs_cost_reinit();
  
	

	cc = update_epsilon();
  
	if (cc != 0) {
		

	} 
	else {
		do { 

			while ( 1 ) {
				if ( ! price_refine() ) 
					break;

				if ( _n_ref >= PRICE_OUT_START ) {
					if ( price_in() ) 
						break;
				}
				if ((cc = update_epsilon ())) 
					break;
			}
			if (cc) break;
			refine();
			if ( _n_ref >= PRICE_OUT_START ) {
				price_out();
			}
			if ( update_epsilon() )
				break;
		} while ( cc == 0 );
	}

	finishup( objective_cost );
}

void MCMF_CS2::print_solution()
{
	if ( _print_ans == false)
		return;
	
	NODE *i;
	ARC *a;
	long ni;
	price_t cost;

	for ( i = _nodes; i < _nodes + _n; i ++ ) {
		ni = N_NODE( i );
		for ( a = i->suspended(); a != (i+1)->suspended(); a ++) {
			if ( _cap[ N_ARC (a) ]  > 0 ) {
				

					   

			}
		}
    }

	

	if ( _comp_duals == true) { 

		cost = MAX_32;
		for ( i = _nodes; i != _sentinel_node; i ++) {
			cost = MIN(cost, i->price());
		}
		for ( i = _nodes; i != _sentinel_node; i ++) {
			

		}
	}

	

}

void MCMF_CS2::print_graph()
{
	NODE *i;
	ARC *a;
	long ni, na;
	

	for ( i = _nodes; i < _nodes + _n; i ++ ) {
		ni = N_NODE( i );
		

		for ( a = i->suspended(); a != (i+1)->suspended(); a ++) {
			na = N_ARC( a );
			

				

		}
    }
}

void MCMF_CS2::finishup( double *objective_cost)
{
	ARC *a; 

	long na; 

	double obj_internal = 0; 

	price_t cs; 

	long flow; 

	NODE *i;

	

	if ( _no_zero_cycles == true) {
		for ( a = _arcs; a != _sentinel_arc; a ++ ) {
			if ( a->cost() == 1) {
				assert( a->sister()->cost() == -1);
				a->set_cost( 0);
				a->sister()->set_cost( 0);
			}
		}
	}

	

	for ( a = _arcs, na = 0; a != _sentinel_arc ; a ++, na ++ ) {
		cs = a->cost() / _dn;
		if ( _cap[na]  > 0 && (flow = _cap[na] - a->rez_capacity()) != 0 )
			obj_internal += (double) cs * (double) flow;
		a->set_cost( cs);
	}

	for ( i = _nodes; i != _sentinel_node; i ++) {
		i->set_price( (i->price() / _dn));
	}

	

	if ( _comp_duals == true) {
		compute_prices();
	}

	*objective_cost = obj_internal;
}

void MCMF_CS2::cs2( double *objective_cost)
{
	

	int cc = 0; 


  
	

	update_epsilon();


	

	do {
		refine();

		if ( _n_ref >= PRICE_OUT_START )
			price_out();

		if ( update_epsilon() ) 
			break;

		while (1) {
			if ( ! price_refine() ) 
				break;

			if ( _n_ref >= PRICE_OUT_START ) {
				if ( price_in() ) break; 
				if ( (cc = update_epsilon()) ) break;
			}
		}
	} while ( cc == 0 );


	

	finishup( objective_cost );
}

int MCMF_CS2::run_cs2()
{
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	


	double objective_cost;


	

	pre_processing();


	

	if ( _check_solution == true) {
		_node_balance = (long long int *) calloc (_n+1, sizeof(long long int));
		for ( NODE *i = _nodes; i < _nodes + _n; i ++ ) {
			_node_balance[i - _nodes] = i->excess();
		}
	}


	

	_m = 2 * _m;
	cs2_initialize(); 

	print_graph(); 


	

	

	

		   


	
	

	cs2( &objective_cost );
	double t = 0.0;
  
	cout << objective_cost << '\n';
	

	

	

	

	

	

		   

  

	

	if ( _check_solution == true ) {
		printf("c checking feasibility...\n"); 
		if ( check_feas() )
			printf("c ...OK\n");
		else
			printf("c ERROR: solution infeasible\n");
		printf("c computing prices and checking CS...\n");
		compute_prices();
		if ( check_cs() )
			printf("c ...OK\n");
		else
			printf("ERROR: CS violation\n");
	}

	

	if ( _print_ans == true ) {
		print_solution();
	}

	

	deallocate_arrays();
	return 0;
}













int n,m;
int f(int r, int c){
	return r*m+c+1;
}
int main( int argc, char *argv[]){
	cin >> n >> m;
	vector<vector<int> > grid(n,vector<int>(m));
	vector<int> a,b,c;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> grid[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if((i+j)%2){
				if(i > 0){a.push_back(f(i,j)); b.push_back(f(i-1,j)); c.push_back(grid[i][j] != grid[i-1][j]);}
				if(j > 0){a.push_back(f(i,j)); b.push_back(f(i,j-1)); c.push_back(grid[i][j] != grid[i][j-1]);}
				if(i+1 < n){a.push_back(f(i,j)); b.push_back(f(i+1,j)); c.push_back(grid[i][j] != grid[i+1][j]);}
				if(j+1 < m){a.push_back(f(i,j)); b.push_back(f(i,j+1)); c.push_back(grid[i][j] != grid[i][j+1]);}
			}
	int num_nodes = n*m*4;
	int num_arcs = a.size();
	

	MCMF_CS2 my_mcmf_problem( num_nodes, num_arcs);
	for(int i = 0; i < num_arcs; ++i)
		my_mcmf_problem.set_arc( a[i], b[i], 0, 1, c[i]);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if((i+j)%2){
				my_mcmf_problem.set_supply_demand_of_node( f(i,j), 1);
			}
			else{
				my_mcmf_problem.set_supply_demand_of_node( f(i,j), -1);
			}
	my_mcmf_problem.run_cs2();
}
